
PROJ = example

all: $(PROJ).exe
	@echo compiled

$(PROJ).cc: $(PROJ).ini
	./lambda-cpp.py --source $(PROJ).ini --dest $(PROJ).cc \
		--headerfile $(PROJ)-header.cc \
		--declare-file $(PROJ)-declare.cc \
		--define-file $(PROJ)-define.cc \
		--footerfile $(PROJ)-footer.cc \

	@echo translated

$(PROJ).exe: $(PROJ).cc
	g++ -o $@ $^

run: all
	./$(PROJ).exe

clean:
	- rm -f $(PROJ).cc $(PROJ).exe
