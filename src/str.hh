
#pragma once

#include <string>

using std::string;

class str {
private:
	const char * original_buffor;
	int * reference_counter;

public:
	str(str parent, int start, int end);
	str(const char * buf);
	str(const str & copy);

	const char * buffor;
	const int length;

	static str from_cstring(const char * cstr);
	static str make_clip(str parent, int start, int end);

	char * to_cstr(void) const; // allocates new

	bool startswith(const string & prefix) const;

	~str();
};
