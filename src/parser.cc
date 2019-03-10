
#include "parser.hh"

bool startswith(const string prefix, const str main)
{
	for (int i = 0, plen = prefix.size(); i < main.length; i++) {
		if (i >= plen) { return true; }
		if (prefix[i] != main.buffor[i]) { return false; }
	}
	return false;
}

vector<Token> parse_tokens(const str text)
{

}
