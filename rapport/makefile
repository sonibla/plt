NAME=Rapport
COMPILER=pdflatex
LATEX=latex
PDFVIEWER=evince
BIBLIO=bibtex
INDEXER=makeindex
GLOSSARY=makeglossaries

simple: clean twice view

all: clean once bib glo idx twice view
	
once:
	$(COMPILER) --shell-escape -synctex=1 -interaction=nonstopmode $(NAME).tex

twice:
	$(COMPILER) --shell-escape -synctex=1 -interaction=nonstopmode $(NAME).tex
	$(COMPILER) --shell-escape -synctex=1 -interaction=nonstopmode $(NAME).tex

clean:
	rm -rf $(NAME).toc $(NAME).lot $(NAME).lof
	rm -rf $(NAME).blg $(NAME).bbl
	rm -rf $(NAME).glo $(NAME).glg $(NAME).gls $(NAME).ist $(NAME).xdy $(NAME).acn
	rm -rf $(NAME).idx $(NAME).ilg $(NAME).ind
	rm -rf *.log *.aux *.out
	rm -rf $(NAME).synctex.gz

glo: once
	$(GLOSSARY) $(NAME).glo

idx: once
	$(INDEXER) $(NAME).idx

bib: once
	$(BIBLIO) $(NAME).aux

latex:
	$(LATEX) -interaction=nonstopmode $(NAME).tex

view:
	$(PDFVIEWER) $(NAME).pdf
