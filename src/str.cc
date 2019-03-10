
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

str::str(str * parent, int start, int end)
	: parent{parent}, length{end - start}, buffor{buffor_parents(parent, start, end)},
	  reference_counter{1}
{

}

str::str(const char * buf)
	: parent{nullptr}, length{(int)strlen(buf)}, buffor{buf},
	  reference_counter{1}
{

}

str::str(const str & copy)
	: parent(copy.parent), length{copy.length}, buffor{copy.buffor},
	  reference_counter{copy.reference_counter + 1}
{

}

str str::from_cstring(const char * cstr) {
	return str{cstr};
}
str str::make_clip(str * parent, int start, int end) {
	return str{parent, start, end};
}

char * str::to_cstr(void) const
{
	char * ret = (char*)malloc(sizeof(char) * (this->length + 1));

	for (int i = 0; i < this->length; i++) {
		ret[i] = this->buffor[i];
	}
	ret[this->length] = 0;

	return ret;
}

void str::checkput(void)
{
	if (this->reference_counter == 0) {
		if (parent == nullptr) {
			free((void*)this->buffor);
		} else {
			parent->reference_counter--;
			parent->checkput();
		}
	}
}

str::~str()
{
	this->reference_counter--;
	this->checkput();
}
