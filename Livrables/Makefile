################################################################################
#Author : Matéo Rémi
################################################################################i


################################################################################
#Variables
################################################################################


TGT=Rapport


all : $(TGT) 
	mv -f $(TGT).pdf ../
	echo " Le PDF est dans le repertoire au dessus du votre"

$(TGT): $(TGT).tex
	pdflatex $(TGT).tex	
	bibtex $(TGT)
	pdflatex $(TGT).tex


clean :
	rm -f *.aux *.out *.toc *.blg *.log *.bbl ../*.pdf Rapport-blx.bib Rapport.run.xml
