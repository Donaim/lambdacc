
#pragma once

class str {
private:
	const str * parent;
	const char * buffor;
	const int length;

	str(const str * parent, int start, int end);
	str(const char * buf);
public:
	static str from_cstring(const char * cstr);
	static str make_clip(const str * parent, int start, int end);

	char * to_cstr(void); // allocates new

	~str();
};
