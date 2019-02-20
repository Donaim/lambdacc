
PROJ = example

headers = $(PROJ)/header.h $(PROJ)/declare.hh $(PROJ)/define.c $(PROJ)/footer.c
additional-deps = Makefile  $(shell ls *.py)

CFLAGS = # -O3
TFLAGS =
CPP = clang

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
	- rm -f $(PROJ).c $(PROJ).exe $(PROJ)/script.inline.ini

$(PROJ).exe: $(PROJ).c $(PROJ)/header.c
	$(CPP) -o $@ $^ $(CFLAGS)

$(PROJ).c: $(PROJ)/script.ini $(headers) $(additional-deps)
	./lambda-cpp.py --source $(PROJ)/script.ini --dest $(PROJ).c \
		--no-make-inline \
		--do-caching \
		--no-print-intermediate \
		--count-total-exec \
		--no-show-debug \
		--use-typeid \
		--echo-expr \
		--headerfile $(PROJ)/header.h \
		--declare-file $(PROJ)/declare.hh \
		--define-file $(PROJ)/define.c \
		--footerfile $(PROJ)/footer.c \
		$(TFLAGS)

	@echo translated

$(PROJ)/declare.hh $(PROJ)/define.c: $(PROJ)/custom.cfg.py $(additional-deps)
	./customwriter.py $(PROJ)/custom.cfg.py $(PROJ)/declare.hh $(PROJ)/define.c

.PHONY: test clean all run
