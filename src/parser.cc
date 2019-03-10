
#include "parser.hh"
#include "svector.hpp"

#include <stdexcept>
#include <cstdlib>
#include <iostream>
#include <exception>

using namespace std;

const char * TokenTypeCSTR(TokenType type)
{
	switch (type) {
		case TokenType::LambdaDecl: return "LambdaDecl";
		case TokenType::LambdaSymbol: return "LambdaSymbol";
		case TokenType::OpenBracket: return "OpenBracket";
		case TokenType::CloseBracket: return "CloseBracket";
		case TokenType::Space: return "Space";
		case TokenType::Newline: return "Newline";
		case TokenType::Comment: return "Comment";
		case TokenType::Quote: return "Quote";
		case TokenType::Name: return "Name";
		default:
			throw runtime_error {"Unrecognized tokentype"};
	}
}

ostream & operator<< (ostream& os, const Token & me)
{
	const char * text = me.text.to_cstr();

	const char * pp = text;
	if (me.type == TokenType::Newline) {
		pp = "\\n";
	}

	os << "{ " << TokenTypeCSTR(me.type) << " [" << pp << "] " << me.lineno << ":" << me.charno << " }";

	free((void*)text);

	return os;
}

struct parse_result {
	int split;
	TokenType type;
};

typedef parse_result (*tokenizer)(const ParserConfig &, const char *, int);

parse_result tokenizeLambdaDecl(const ParserConfig & cfg, const char * str, int len)
{
	if (startswiths(str, len, cfg.LambdaDecl.c_str(), cfg.LambdaDecl.size())) {
		return { (int)cfg.LambdaDecl.size(), TokenType::LambdaDecl };
	} else {
		return { 0 };
	}
}
parse_result tokenizeLambdaSymbol(const ParserConfig & cfg, const char * str, int len)
{
	if (startswiths(str, len, cfg.LambdaSymbol.c_str(), cfg.LambdaSymbol.size())) {
		return { (int)cfg.LambdaSymbol.size(), TokenType::LambdaSymbol };
	} else {
		return { 0 };
	}
}
parse_result tokenizeOpenBracket(const ParserConfig & cfg, const char * str, int len)
{
	if (startswiths(str, len, "(", 1)) {
		return { 1, TokenType::OpenBracket };
	} else {
		return { 0 };
	}
}
parse_result tokenizeCloseBracket(const ParserConfig & cfg, const char * str, int len)
{
	if (startswiths(str, len, ")", 1)) {
		return { 1, TokenType::CloseBracket };
	} else {
		return { 0 };
	}
}
parse_result tokenizeSpace(const ParserConfig & cfg, const char * str, int len)
{
	if (startswiths(str, len, " ", 1) || startswiths(str, len, "\t", 1)) {
		return { 1, TokenType::Space };
	} else {
		return { 0 };
	}
}
parse_result tokenizeNewline(const ParserConfig & cfg, const char * str, int len)
{
	if (startswiths(str, len, "\r\n", 2) || startswiths(str, len, "\n\r", 2)) {
		return { 2, TokenType::Newline };
	} else if (startswiths(str, len, "\n", 1)) {
		return { 1, TokenType::Newline };
	} else {
		return { 0 };
	}
}
parse_result tokenizeComment(const ParserConfig & cfg, const char * str, int len)
{
	if (startswiths(str, len, "#", 1) || startswiths(str, len, ";", 1)) {
		for (int i = 0; i < len; i++) {
			if (str[i] == '\n') {
				return { i, TokenType::Comment };
			}
		}
		return { len, TokenType::Comment };
	} else {
		return { 0 };
	}
}
parse_result tokenizeQuote(const ParserConfig & cfg, const char * str, int len)
{
	if (startswiths(str, len, "'", 1)) {
		bool escaped = false;
		for (int i = 1; i < len; i++) {
			if (str[i] == '\'' && !escaped) {
				return { i + 1, TokenType::Quote };
			}
			if (str[i] == '\\') {
				escaped = !escaped;
			} else {
				escaped = false;
			}
		}
		throw runtime_error { "Quote does not end" };
	} else {
		return { 0 };
	}
}

parse_result tokenizeName(const ParserConfig & cfg, const char * str, int len);

tokenizer tokers[] = {
	tokenizeLambdaDecl,
	tokenizeLambdaSymbol,
	tokenizeOpenBracket,
	tokenizeCloseBracket,
	tokenizeSpace,
	tokenizeNewline,
	tokenizeComment,
	tokenizeQuote,
	tokenizeName,
};
int tokers_len = sizeof(tokers) / sizeof(*tokers);

parse_result tokenizeName(const ParserConfig & cfg, const char * str, int len)
{
	for (int i = 0; i < len; i++) {
		for (int k = 0; k < tokers_len; k++) {
			if (tokers[k] == tokenizeName) { continue; }

			parse_result re = tokers[k](cfg, str + i, len - i);
			if (re.split) {
				return { i, TokenType::Name };
			}
		}
	}

	return { len, TokenType::Name };
}

svector<Token> * parse_tokens(const ParserConfig & cfg, const str text)
{
	int lineno = 1;
	int charno = 1;
	const char * buf = text.buffor;
	svector<Token> * ret = new svector<Token>{(size_t)text.length};

	for (int i = 0; i < text.length; i++) {
		for (int k = 0; k < tokers_len; k++) {
			parse_result re = tokers[k](cfg, buf + i, text.length - i);

			if (re.split) {
				str clip { text, i, i + re.split };

				Token * t = ret->get_next();

				t->text = clip;
				t->type = re.type;
				t->lineno = lineno;
				t->charno = charno;

				if (re.type == TokenType::Newline) {
					lineno++;
					charno = 1;
				} else {
					charno++;
				}

				i += re.split - 1;
				break;
			}
		}
	}

	return ret;
}
