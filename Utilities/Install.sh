#!/bin/bash

#Author Matéo Rémi Script installation ubuntu



#Installations ici de la librarie boost a partir des depots et test partiel effectué
sudo apt-get install codeblocks texlive texlive-lang-french texlive-latex-extra libboost-dev biblatex


#Installation terminer test de compilation des fichiers boost
g++ -Wall -c Example.cpp && g++ -o Example Example.o -Lboost && echo "Compilation succeeded"

echo 1 2 3 | ./Example && echo "Program executed with succeed"

