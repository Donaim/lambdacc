
#include <cstdio>
#include <cstdlib>

#include <stdexcept>

const char * readfile (const char * path)
{
	FILE *f = fopen(path, "rb");
	fseek(f, 0, SEEK_END);
	long fsize = ftell(f);
	fseek(f, 0, SEEK_SET);

	char *string = (char*)malloc(fsize + 1);
	int read = fread(string, fsize, 1, f);
	if (read != 1) {
		throw std::runtime_error { "readfile read incorrect number of bytes" };
	}
	fclose(f);

	string[fsize] = 0;

	return string;
}

