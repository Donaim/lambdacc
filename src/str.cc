
#include "str.hh"

#include <iostream>
#include <exception>

using namespace std;

#include <cstring>

const char * buffor_parents(const str parent, int start, int end) {
	if (end <= start) {
		throw runtime_error {"clip range is negative"};
	}
	if (parent.length < start) {
		throw runtime_error {"clip range start is too big"};
	}
	if (parent.length < start + end) {
		throw runtime_error {"clip range end is too big"};
	}

	return parent.buffor + start;
}

str::str(str parent, int start, int end)
	: original_buffor{parent.original_buffor}, length{end - start}, buffor{buffor_parents(parent, start, end)},
	  reference_counter{parent.reference_counter}
{
	(*(this->reference_counter))++;
}

str::str(const char * buf)
	: original_buffor{buf}, length{(int)strlen(buf)}, buffor{buf},
	  reference_counter{new int{1}}
{

}

str::str(const str & copy)
	: original_buffor{copy.original_buffor}, length{copy.length}, buffor{copy.buffor},
	  reference_counter{copy.reference_counter}
{
	(*(this->reference_counter))++;
}

str str::from_cstring(const char * cstr) {
	return str{cstr};
}
str str::make_clip(str parent, int start, int end) {
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

str::~str()
{
	(*this->reference_counter)--;

	if (*(this->reference_counter) == 0) {
		free((void*)this->reference_counter);
	}
	if (*(this->reference_counter) <= 0) {
		free((void*)this->original_buffor);
	}
}
