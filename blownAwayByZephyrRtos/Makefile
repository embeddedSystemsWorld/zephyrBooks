BOOK=main
lxopt=-shell-escape

all:
	pdflatex $(lxopt) $(BOOK)

final:
	pdflatex  $(lxopt) $(BOOK)
	biber     $(BOOK)
	makeindex $(BOOK)
	pdflatex  $(lxopt) $(BOOK)
	pdflatex  $(lxopt) $(BOOK)
	cp $(BOOK).pdf BlownAwayByZephyr.pdf

clean:
	rm -f *.aux *.mtc* *.out *.idx *.bcf *.log *~ *.ptc *.toc *.run.xml *.maf *.bbl *.blg *.ilg *.ind
	rm -f $(BOOK).pdf
	rm -rf _minted-main/
