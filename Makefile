
PROJ = example

headers = $(PROJ)/header.h $(PROJ)/declare.hh $(PROJ)/define.cc $(PROJ)/footer.cc
additional-deps = Makefile  $(shell ls *.py)

CFLAGS = # -O3
TFLAGS =
CPP = clang++

run: all
	./$(PROJ).exe

all: $(PROJ).exe
	@echo compiled

test:
	$(MAKE) all PROJ=test CFLAGS=''
	test/checkout.sh
	$(MAKE) all PROJ=test   TFLAGS='--no-do-caching' CFLAGS=''
	test/checkout.sh
	$(MAKE) all PROJ=test   TFLAGS='--no-do-caching --no-use-typeid' CFLAGS=''
	test/checkout.sh
	$(MAKE) all PROJ=test   TFLAGS='--make-inline --no-do-caching --no-use-typeid' CFLAGS=''
	test/checkout.sh
	$(MAKE) all PROJ=test   TFLAGS='--make-inline --no-use-typeid'  CFLAGS=''
	test/checkout.sh

clean:
	- rm -f $(PROJ).cc $(PROJ).exe $(PROJ)/script.inline.ini

$(PROJ).exe: $(PROJ).cc
	$(CPP) -o $@ $^ $(CFLAGS)

$(PROJ).cc: $(PROJ)/script.ini $(headers) $(additional-deps)
	./lambda-cpp.py --source $(PROJ)/script.ini --dest $(PROJ).cc \
		--no-make-inline \
		--do-caching \
		--no-print-intermediate \
		--count-total-exec \
		--no-show-debug \
		--use-typeid \
		--echo-expr \
		--headerfile $(PROJ)/header.h \
		--declare-file $(PROJ)/declare.hh \
		--define-file $(PROJ)/define.cc \
		--footerfile $(PROJ)/footer.cc \
		$(TFLAGS)

	@echo translated

$(PROJ)/declare.hh $(PROJ)/define.cc: $(PROJ)/custom.cfg.py $(additional-deps)
	./customwriter.py $(PROJ)/custom.cfg.py $(PROJ)/declare.hh $(PROJ)/define.cc

.PHONY: test clean all run
