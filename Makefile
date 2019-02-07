
PROJ = example

headers = $(PROJ)-header.cc $(PROJ)-declare.cc $(PROJ)-define.cc $(PROJ)-footer.cc
additional-deps = Makefile  $(shell ls *.py)

run: all
	./$(PROJ).exe

all: $(PROJ).exe
	@echo compiled

clean:
	- rm -f $(PROJ).cc $(PROJ).exe $(PROJ).inline.ini

$(PROJ).exe: $(PROJ).cc
	g++ -o $@ $^ -O3

$(PROJ).cc: $(PROJ).ini $(headers) $(additional-deps)
	./lambda-cpp.py --source $(PROJ).ini --dest $(PROJ).cc \
		--no-make-inline \
		--do-caching \
		--no-print-intermediate \
		--count-total-exec \
		--no-show-debug \
		--use-typeid \
		--headerfile $(PROJ)-header.cc \
		--declare-file $(PROJ)-declare.cc \
		--define-file $(PROJ)-define.cc \
		--footerfile $(PROJ)-footer.cc \

	@echo translated

$(PROJ)-declare.cc $(PROJ)-define.cc: $(PROJ)-custom.cfg.py $(additional-deps)
	./customwriter.py $(PROJ)-custom.cfg.py $(PROJ)-declare.cc $(PROJ)-define.cc
