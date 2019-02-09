
PROJ = example

headers = $(PROJ)/header.hh $(PROJ)/declare.hh $(PROJ)/define.cc $(PROJ)/footer.cc
additional-deps = Makefile  $(shell ls *.py)

CFLAGS = -O3
TFLAGS =

run: all
	./$(PROJ).exe

all: $(PROJ).exe
	@echo compiled

clean:
	- rm -f $(PROJ).cc $(PROJ).exe $(PROJ)/script.inline.ini

$(PROJ).exe: $(PROJ).cc
	g++ -o $@ $^ $(CFLAGS)

$(PROJ).cc: $(PROJ)/script.ini $(headers) $(additional-deps)
	./lambda-cpp.py --source $(PROJ)/script.ini --dest $(PROJ).cc \
		--no-make-inline \
		--do-caching \
		--no-print-intermediate \
		--count-total-exec \
		--no-show-debug \
		--use-typeid \
		--echo-expr \
		--headerfile $(PROJ)/header.hh \
		--declare-file $(PROJ)/declare.hh \
		--define-file $(PROJ)/define.cc \
		--footerfile $(PROJ)/footer.cc \
		$(TFLAGS)

	@echo translated

$(PROJ)/declare.hh $(PROJ)/define.cc: $(PROJ)/custom.cfg.py $(additional-deps)
	./customwriter.py $(PROJ)/custom.cfg.py $(PROJ)/declare.hh $(PROJ)/define.cc
