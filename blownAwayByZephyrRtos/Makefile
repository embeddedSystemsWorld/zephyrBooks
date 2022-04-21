BOOK=main
BOOK_FN=BlownAwayByZephyr
lxopt=-shell-escape

all:
	pdflatex $(lxopt) $(BOOK)

final:
	pdflatex  $(lxopt) $(BOOK)
	biber     $(BOOK)
	makeindex $(BOOK)
	pdflatex  $(lxopt) $(BOOK)
	pdflatex  $(lxopt) $(BOOK)
	cp $(BOOK).pdf $(BOOK_FN).pdf
	
	gs -sDEVICE=pdfwrite -dPDFSETTINGS=/ebook -q  -o $(BOOK_FN)-ebook.pdf    $(BOOK).pdf

clean:
	rm -f *.aux *.mtc* *.out *.idx *.bcf *.log *~ *.ptc *.toc *.run.xml *.maf *.bbl *.blg *.ilg *.ind
	rm -f $(BOOK).pdf
	rm -rf _minted-main/
