
#include <iostream>

#include <filesys.hh>

using namespace std;

int main() {
	auto content = readfile("example/script.ini");

	// cout << "file:" << endl << content << endl;
	cout << "Hello" << endl;
}
