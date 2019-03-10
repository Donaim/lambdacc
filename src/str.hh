
#pragma once

class str {
private:
	str * parent;
	int reference_counter;

	void checkput(void);

	str(str * parent, int start, int end);
	str(const char * buf);
	str(const str & copy);
public:
	const char * buffor;
	const int length;

	static str from_cstring(const char * cstr);
	static str make_clip(str * parent, int start, int end);

	char * to_cstr(void) const; // allocates new

	friend const char * buffor_parents(const str * parent, int start, int end);

	~str();
};
