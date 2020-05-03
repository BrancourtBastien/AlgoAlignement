#include <iostream>
#include <fstream>
#include <string>
#include "algo.h"

using namespace std;



void seqBasique(string fichier, string *nom1, string *nom2, string *seq1, string *seq2){
  //Cette fonction stocke les deux premiers noms et séquences dans des strings
  ifstream flux(fichier);
  
  if(flux)
    {
      string str;

      flux.get();  //on saute le premier caractère puis on stocke le nom dans nom1
      getline(flux, *nom1);  

      while(flux.get() != '>'){
	flux.seekg(-1, ios::cur); //il faut retourner à gauche d'un caractère à cause du get() dans le test
	getline(flux, str);
	*seq1+=str;  //on récupère chaque ligne puis on l'ajoute dans seq1
      }


      //même chose pour nom2 et seq2
      getline(flux, *nom2);

      while(getline(flux, str)){
	*seq2+=str;
      }

}

  else
    cout<<"Impossible d'ouvrir le fichier"<<endl;

}


int distance(string seq1, string seq2, int pSup, int pRemp){
  int m=seq1.size();
  int n=seq2.size();
  
  int matrice [m+1] [n+1]; //on créé la matrice de distance

  for(int i=0; i<= max(n,m); i++){ //on initalise les cases avec une coordonnée 0
    matrice[i][0]=i*pSup;
    matrice[0][i]=i*pSup;
  }

  //on applique l'algo simple
  for(int i=1; i<=m; i++){
    for(int j=1; j<=n; j++){
      if(seq1[i-1] == seq2[j-1])
	matrice[i][j]=matrice[i-1][j-1];
      else
	matrice[i][j]=min(matrice[i-1][j] +pSup, min(matrice[i][j-1] +pSup, matrice [i-1][j-1]+pRemp));
    }
}
return matrice[m][n];
}
