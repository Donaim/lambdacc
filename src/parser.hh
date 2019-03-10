
#pragma once

#include <vector>
#include <string>
#include "str.hh"

using std::vector;
using std::string;

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
	Name,
};

struct Token {
	const str text;
	const TokenType type;
	const int charno;
	const int lineno;
};

vector<Token> parse_tokens(const str text);
