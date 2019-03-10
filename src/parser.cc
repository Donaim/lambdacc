
#include "parser.hh"

#include <iostream>

using namespace std;

struct parse_result {
	int split;
	TokenType type;
};

typedef parse_result (*tokenizer)(const ParserConfig &, const char *, int);

parse_result tokenizeLambdaDecl(const ParserConfig & cfg, const char * str, int len)
{
	if (startswiths(str, len, cfg.LambdaDecl.c_str(), cfg.LambdaDecl.size())) {
		return { (int)cfg.LambdaDecl.size(), TokenType::LambdaDecl };
	}
	else {
		return { 0 };
	}
}
parse_result unrecognizedToken(const ParserConfig & cfg, const char * str, int len)
{
	return { 1, TokenType::Name };
}

tokenizer tokers[] = {
	tokenizeLambdaDecl,
	unrecognizedToken,
};
int tokers_len = sizeof(tokers) / sizeof(*tokers);

vector<Token> parse_tokens(const ParserConfig & cfg, const str text)
{
	int lineno = 0;
	int charno = 0;
	const char * buf = text.buffor;
	vector<Token> ret;

	cout << "tokers len: " << tokers_len << endl;

	for (int i = 0; i < text.length; i++) {
		for (int k = 0; k < tokers_len; k++) {
			parse_result re = tokers[k](cfg, buf + i, text.length - i);

			if (re.split) {
				str clip { text, i, i + re.split };

				Token t = {
					clip,
					re.type,
					charno,
					lineno,
				};

				ret.push_back(t);

				if (re.type == TokenType::Newline) {
					lineno++;
					charno = 0;
				} else {
					charno++;
				}

				i += re.split;
				break;
			}
		}
	}

	return ret;
}
