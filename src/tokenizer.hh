
#pragma once

#include <string>
#include "str.hh"
#include "svector.hpp"

using std::string;
using std::ostream;

struct ParserConfig {
	const string LambdaDecl;
	const string LambdaSymbol;
};

enum class TokenType {
	LambdaDecl,
	LambdaSymbol,
	OpenBracket,
	CloseBracket,
	Space,
	Newline,
	Comment,
	Quote,
	Name,
};

const char * TokenTypeCSTR(TokenType type);

struct Token {
	str text;
	TokenType type;
	int charno;
	int lineno;

	friend ostream & operator<< (ostream & os, const Token & me);
};

svector<Token> * parse_tokens(const ParserConfig & cfg, const str text);
