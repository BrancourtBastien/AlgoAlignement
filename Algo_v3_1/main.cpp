#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "algo.h"
#include "arg.h"

using namespace std;


int main(int argc, char** argv){ //le programme requiert au moins un nom de fichier en argument

  string nom1, nom2, seq1, seq2;
  bool rech=false;
  bool choix=false;
  bool help=false;

  arg(argc, argv, &rech, &choix, &help);

  if(help)
    return 0;

  //on cherche toutes les séquences du fichier si l'utilisateur a entré l'option 'r'
  if(rech){
    rechSeq(argv[1], &nom1, &nom2, &seq1, &seq2);
  }
  //sinon on utilise les deux premières
  else{
    seqBasique(argv[1], &nom1, &nom2, &seq1, &seq2);
  }


  //on définit les pénalités par défaut
  int pSup=1;
  int pRemp=1;


  //on les demande à l'utilisateur si il a entré l'option 'c'
  if(choix){
    cout<<"Quelle pénalité souhaitez-vous pour un saut de caractère ? ";
    cin>>pSup;
    cout<<"Quelle pénalité souhaitez-vous pour un remplacement de caractère ? ";
    cin>>pRemp;
    cout<<endl<<endl;
  }

  
  cout<<"En appliquant une pénalité de "<<pSup<<" pour une suppression et de "<<pRemp<<" pour un remplacement, ";
  cout<<"la distance d'édition entre les séquences :"<<endl;
  cout<<"-"<<nom1<<endl<<"-"<<nom2<<endl<<"est de : ";
  alignement(seq1, seq2, pSup, pRemp);
  
  return 0;
}
