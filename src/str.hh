
#pragma once

class str {
private:
	str * parent;
	const char * buffor;
	const int length;

	int reference_counter;

	void checkput(void);

	str(str * parent, int start, int end);
	str(const char * buf);
public:
	static str from_cstring(const char * cstr);
	static str make_clip(str * parent, int start, int end);

	char * to_cstr(void); // allocates new

	friend const char * buffor_parents(const str * parent, int start, int end);

	~str();
};
