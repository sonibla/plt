NAME=Rapport
COMPILER=pdflatex
COMPARGS=| tail -n -233 | grep -v .pfb
BIBLIO=bibtex
INDEXER=makeindex
GLOSSARY=makeglossaries

all: clean once bib glo idx
	$(COMPILER) $(NAME).tex $(COMPARGS)
	$(INDEXER) $(NAME).idx
	$(COMPILER) $(NAME).tex $(COMPARGS)

once:
	$(COMPILER) $(NAME).tex $(COMPARGS)

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

simple: once bib glo idx
	$(COMPILER) $(NAME).tex $(COMPARGS)
