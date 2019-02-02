
all: out.exe
	@echo compiled

out.cc:
	./lambda-cpp.py --source example.ini --dest out.cc \
		--headerfile example-header.cc \
		--declare-file example-declare.cc \
		--define-file example-define.cc \
		--footerfile example-footer.cc
	@echo translated

out.exe: out.cc
	g++ -o $@ $^

run: all
	./out.exe

clean:
	- rm -f out.cc out.exe
