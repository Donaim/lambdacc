
PROJ = example

all: $(PROJ).exe
	@echo compiled

run: all
	./$(PROJ).exe

clean:
	- rm -f $(PROJ).cc $(PROJ).exe

$(PROJ).exe: $(PROJ).cc
	g++ -o $@ $^ -O3

$(PROJ).cc: $(PROJ).ini $(PROJ)-header.cc $(PROJ)-declare.cc $(PROJ)-define.cc $(PROJ)-footer.cc
	./lambda-cpp.py --source $(PROJ).ini --dest $(PROJ).cc \
		--no-make-inline \
		--headerfile $(PROJ)-header.cc \
		--declare-file $(PROJ)-declare.cc \
		--define-file $(PROJ)-define.cc \
		--footerfile $(PROJ)-footer.cc \

	@echo translated

$(PROJ)-header.cc:
	touch $@

$(PROJ)-declare.cc:
	touch $@

$(PROJ)-define.cc:
	touch $@

$(PROJ)-footer.cc:
	touch $@
