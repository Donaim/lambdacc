
#include <iostream>
#include <string>

#include <filesys.hh>
#include <parser.hh>
#include <str.hh>

using namespace std;

int main() {
	auto content = readfile("example/script.ini");

	// cout << "file:" << endl << content << endl;
	cout << "Hello" << endl;

	str s{content};

	str kek = str::make_clip(s, 3, 10);

	cout << "Clip: [" << kek.to_cstr() << "]" << endl;

	string cmp = "comment";

	cout << "Startswith: " << kek.startswith(cmp) << endl;

}
