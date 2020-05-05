#ifndef ALGO_H
#define ALGO_H

#include <iostream>
#include <fstream>
#include <string>
#include "algo.cpp"

using namespace std;

void seqBasique(string fichier, string *nom1, string *nom2, string *seq1, string *seq2);
/*Fonction très basique de lecture du fichier Fasta, elle stocke les deux premiers
noms et séquences dans les string pointés
A faire: une du même genre qui prend aussi deux noms de séquences et les recherche pour
pouvoir utiliser un fichier avec plus de deux séquences*/

void distance(string seq1, string seq2, int pSup, int pRemp);
/*Fonction de calcul de la distance d'édition,on donne les deux séquences et
les pénalités qu'on veut pour une suppression ou un remplacement*/

#endif
