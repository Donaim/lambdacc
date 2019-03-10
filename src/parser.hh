
#pragma once

#include <vector>
#include "str.hh"

using std::vector;

struct ParserConfig {
	const char * LambdaDecl;
	const char * LambdaSymbol;
};

enum class TokenType {
	LambdaDecl,
	LambdaSymbol,
	Space,
	Newline,
	Comment,
	Name,
};

struct Token {
	const str text;
	const TokenType type;
	const int charno;
	const int lineno;
};

vector<Token> parse_tokens(const str text);
