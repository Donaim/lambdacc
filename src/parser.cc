
#include "parser.hh"
#include <vector>

bool startswith(const char * prefix, const char * main)
{
	for (int i = 0; main[i] != 0; i++) {
		if (prefix[i] == 0) { return true; }
		if (prefix[i] != main[i]) { return false; }
	}
	return false;
}

vector<Token> parse_tokens(const str text)
{

}
