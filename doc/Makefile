# Copyright Larry Tyree, N6TR
# Modified for macOS by ChatGPT, 2025

# Detect TeX binaries (works with Homebrew or MacTeX)
TEXBIN := $(shell which pdflatex 2>/dev/null | xargs dirname)
# --- macOS-safe PATH + SHELL setup ---
PATH := $(PATH):/usr/local/texlive/bin/universal-darwin
SHELL := /bin/sh
export PATH

# If you installed circuit_macros via Homebrew, it's usually under /opt/homebrew/share/circuit_macros
# or /usr/local/share/circuit_macros. You can override this by running:
#   make HOMELIB=/path/to/circuit_macros
HOMELIB ?= /opt/homebrew/share/circuit_macros
ifeq ("$(wildcard $(HOMELIB))","")
HOMELIB := /usr/local/share/circuit_macros
endif

M4 = m4 \
    $(HOMELIB)/gpic.m4 \
    $(HOMELIB)/libgen.m4 \
    $(HOMELIB)/libcct.m4 \
    $(HOMELIB)/liblog.m4 \
    $(HOMELIB)/lib3D.m4 \
    $(HOMELIB)/darrow.m4

BASE = trloglinux

.SUFFIXES: .tex .m4 .jpg .eps .ps .pdf

# === PDF target ===
$(BASE).pdf: $(BASE).tex
	find . -name '*.eps' -exec epstopdf {} \;
	pdflatex $(BASE)
	makeindex $(BASE)
	pdflatex $(BASE)
	pdflatex $(BASE)

# === DVI target (legacy) ===
$(BASE).dvi: $(BASE).tex
	latex $(BASE)
	latex $(BASE)
	latex $(BASE)

# === Clean targets ===
distclean:
	rm -f *.pdf *.log *.end
	rm -f *.aux *.toc *.lof
	rm -f *.bbl *.blg *.dvi
	rm -f *.ilg *.idx *.ind

clean:
	rm -f *.log *.end
	rm -f *.aux *.toc *.lof
	rm -f *.bbl *.blg *.dvi
	rm -f *.ilg *.idx *.ind

# === M4 -> TeX rule ===
.m4.tex:
	$(M4) $< | gpic -t > $@
	echo '\centerline{\box\graph}' >> $@

# === TeX -> EPS rule ===
.tex.eps:
	echo "Generating EPS for $*"
	echo "\documentclass[12pt]{article}" > temp.tex
	echo "\usepackage{graphicx}" >> temp.tex
	echo "\pagestyle{empty}" >> temp.tex
	echo "\begin{document}" >> temp.tex
	echo "\begin{figure}[h]" >> temp.tex
	echo "\include{$*}" >> temp.tex
	echo "\end{figure}" >> temp.tex
	echo "\end{document}" >> temp.tex
	latex temp.tex
	dvips -E -o $@ temp.dvi

# === EPS -> PDF rule ===
.eps.pdf:
	epstopdf $<
