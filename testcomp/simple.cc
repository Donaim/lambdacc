
#include <iostream>
#include <string>

#include <filesys.hh>
#include <parser.hh>
#include <str.hh>

using namespace std;

void test_startswith(void)
{
	auto content = readfile("example/script.ini");

	// cout << "file:" << endl << content << endl;
	cout << "Hello" << endl;

	str s{content};

	str kek = str::make_clip(s, 3, 10);

	cout << "Clip: [" << kek.to_cstr() << "]" << endl;

	string cmp = "comment";

	cout << "Startswith: " << kek.startswith(cmp) << endl;
}

void test_parse_tokens(void)
{
	auto content = readfile("example/script.ini");
	str s{content};

	ParserConfig cfg { "\\", "->" };
	vector<Token> * vec = parse_tokens(cfg, s);

	for (int i = 0; i < vec->size(); i++) {
		// cout << vec->at(i) << endl;
	}

}

int main() {
	// test_startswith();
	test_parse_tokens();

	return 0;
}
