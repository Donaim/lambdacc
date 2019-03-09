
#include "str.hh"

#include <iostream>
#include <exception>

using namespace std;

#include <cstring>

const char * buffor_parents(const str * parent, int start, int end) {
	if (parent == nullptr) {
		throw runtime_error {"clip parent is null"};
	}
	if (end <= start) {
		throw runtime_error {"clip range is negative"};
	}
	if (parent->length < start) {
		throw runtime_error {"clip range start is too big"};
	}
	if (parent->length < start + end) {
		throw runtime_error {"clip range end is too big"};
	}

	return parent->buffor + start;
}

str::str(const str * parent, int start, int end)
	: parent{parent}, length{end - start}, buffor{buffor_parents(parent, start, end)}
{

}

str::str(const char * buf)
	: parent{nullptr}, length{(int)strlen(buf)}
{

}

str str::from_cstring(const char * cstr) {
	return str{cstr};
}
str str::make_clip(const str * parent, int start, int end) {
	return str{parent, start, end};
}

char * str::to_cstr(void)
{
	return nullptr;
}

str::~str()
{
	std::cout << "kek\n";
}
