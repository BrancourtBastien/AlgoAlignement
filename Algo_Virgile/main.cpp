#include <iostream>
#include <fstream>
#include <string>

#include "algo.h"

using namespace std;


int main(int argc, char** argv){ //le programme requiert au moins un nom de fichier en argument

  string nom1, nom2, seq1, seq2;

  seqBasique(argv[1], &nom1, &nom2, &seq1, &seq2);

  //on définit les pénalités (à faire : passer ça en arguments du main)
  int pSup=1;
  int pRemp=1;
  
  cout<<"En appliquant une pénalité de "<<pSup<<" pour une suppression et de "<<pRemp<<" pour un remplacement, ";
  cout<<"la distance d'édition entre les séquences :"<<endl;
  cout<<"-"<<nom1<<endl<<"-"<<nom2<<endl<<"est de : "<<distance(seq1, seq2, pSup, pRemp)<<endl;
  
  return 0;
}
