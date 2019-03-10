
#pragma once

#include <vector>
#include <string>
#include "str.hh"

using std::vector;
using std::string;
using std::ostream;

struct ParserConfig {
	const string LambdaDecl;
	const string LambdaSymbol;
};

enum class TokenType {
	LambdaDecl,
	LambdaSymbol,
	Space,
	Newline,
	Comment,
	Quote,
	Name,
};

const char * TokenTypeCSTR(TokenType type);

struct Token {
	const str text;
	const TokenType type;
	const int charno;
	const int lineno;

	friend ostream & operator<< (ostream & os, const Token & me);
};

vector<Token> * parse_tokens(const ParserConfig & cfg, const str text);
