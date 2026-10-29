LATEXCMD = pdflatex -shell-escape -output-directory build/
export TEXINPUTS=.:content/tex/:
export max_print_line = 1048576

help:
	@echo "This makefile builds KACTL (KTH Algorithm Competition Template Library)"
	@echo ""
	@echo "Available commands are:"
	@echo "	make fast		- to build KACTL, quickly (only runs LaTeX once)"
	@echo "	make kactl		- to build KACTL"
	@echo "	make clean		- to clean up the build process"
	@echo "	make veryclean		- to clean up and remove kactl.pdf"
	@echo "	make test		- to run all the stress tests in stress-tests/"
	@echo "	make test-compiles	- to test compiling all headers"
	@echo "	make help		- to show this information"
	@echo "	make showexcluded	- to show files that are not included in the doc"
	@echo ""
	@echo "For more information see the file 'doc/README'"

fast: | build
	$(LATEXCMD) content/kactl.tex </dev/null
	cp build/kactl.pdf kactl.pdf

kactl: test-session.pdf | build
	$(LATEXCMD) content/kactl.tex && $(LATEXCMD) content/kactl.tex
	cp build/kactl.pdf kactl.pdf

colored: | build
	$(LATEXCMD) -jobname=kactl_colored '\def\KACTLColorBuild{1}\input{content/kactl.tex}'
	$(LATEXCMD) -jobname=kactl_colored '\def\KACTLColorBuild{1}\input{content/kactl.tex}'
	cp build/kactl_colored.pdf kactl_colored.pdf

build-all:
	@$(MAKE) test-compiles; compile_status=$$?; \
	$(MAKE) test; stress_status=$$?; \
	$(MAKE) kactl; mono_status=$$?; \
	$(MAKE) colored; color_status=$$?; \
	if [ $$compile_status -ne 0 ] || [ $$stress_status -ne 0 ] || \
	   [ $$mono_status -ne 0 ] || [ $$color_status -ne 0 ]; then \
	  echo "One or more test suites or PDF builds failed"; exit 1; \
	fi

clean:
	cd build && rm -f kactl.aux kactl.log kactl.tmp kactl.toc kactl.pdf kactl.ptc kactl.out \
		kactl_colored.aux kactl_colored.log kactl_colored.tmp kactl_colored.toc \
		kactl_colored.pdf kactl_colored.ptc kactl_colored.out

veryclean: clean
	rm -f kactl.pdf test-session.pdf

.PHONY: help fast kactl colored build-all clean veryclean

build:
	mkdir -p build/

test:
	./doc/scripts/run-all.sh .

test-compiles:
	./doc/scripts/compile-all.sh .

test-session.pdf: content/test-session/test-session.tex content/test-session/chapter.tex | build
	$(LATEXCMD) content/test-session/test-session.tex
	cp build/test-session.pdf test-session.pdf

showexcluded: build
	grep -RoPh '^\s*\\kactlimport{\K.*' content/ | sed 's/.$$//' > build/headers_included
	find ./content -name "*.h" -o -name "*.py" -o -name "*.java" | grep -vFf build/headers_included
