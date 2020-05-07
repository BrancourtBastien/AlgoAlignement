#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <bits/stdc++.h> 
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
	if(str[0]=='>')
	  break;
	else
	  *seq2+=str;
      }

}

  else
    cout<<"Impossible d'ouvrir le fichier"<<fichier<<endl;

}

void rechSeq(string fichier, string *nom1, string *nom2, string *seq1, string *seq2){
  vector<string> sequences;

  ifstream flux(fichier);

  if(flux)
    {
      int i=-1;
      string str;
      while(getline(flux, str)){
	  if (str[0]=='>'){
	    sequences.push_back(str);
	    sequences.push_back("");
	    i+=2;
	  }
	  else{
	    sequences[i] = sequences[i] + str;
        }
      }
    }
  else{
    cout<<"Impossible d'ouvrir le fichier"<<endl;
  }

  cout<<"Les séquences suivantes ont été trouvées dans le fichier :"<<endl;
  for(int i=0; i<sequences.size(); i+=2){
    cout<<(i/2)+1<<sequences[i]<<endl;
  }
  cout<<endl<<"Choisissez les deux séquences à comparer :"<<endl;

  int x,y;
  
  cin>>x;
  cin>>y;

  *nom1=sequences[(x-1)*2].erase(0,1);
  *seq1=sequences[(x*2)-1];
  *nom2=sequences[(y-1)*2].erase(0,1);
  *seq2=sequences[(y*2)-1];
  
  
}


void alignement(string seq1, string seq2, int pSup, int pRemp){
  int m=seq1.size();
  int n=seq2.size();
  
  int matrice [m+1] [n+1]; //on créé la matrice de distance

  for(int i=0; i<= m; i++){ //on initalise les cases avec une coordonnée 0
    matrice[i][0]=i*pSup;
  }
  for(int i=0; i<=n; i++){
    matrice[0][i]=i*pSup;
  }

  //on applique l'algo simple
  for(int i=1; i<=m; i++){
    for(int j=1; j<=n; j++){
      if(seq1[i-1] == seq2[j-1])
	matrice[i][j]=matrice[i-1][j-1];
      else
	matrice[i][j]=min({matrice[i-1][j] +pSup
	      , matrice[i][j-1] +pSup
	      , matrice [i-1][j-1]+pRemp});
    }
  }
  
  /*for(int i=0; i<=m; i++){
    for(int j=0; j<=n; j++){
      cout<<matrice[i][j];
    }
    cout<<endl;
    }*/
  
  cout<<matrice[m][n]<<endl;
  

  //ALIGNEMENT
  cout<<"ici";
  int l=m+n; //la longueur maximale de la séquence reconstruite

  int pos1=l; //les coordonées pour le parcours des séquences
  int pos2=l;

  char seqAl1[l+1], seqAl2[l+1];  //séquences alignées, on leur donne la longueur max pour le moment

  int i=m;
  int j=n;

  
  while (i>0 || j>0){ //on utilise l'algo de reconstruction à partir de la matrice
    if (seq1[i-1] == seq2[j-1])
      {
	seqAl1[pos1--] = seq1[i-1];
	seqAl2[pos2--] = seq2[j-1];
	i--; j--;
      }
    else if (matrice[i-1][j-1] + pRemp == matrice[i][j])
      {
	seqAl1[pos1--] = seq1[i-1];
	seqAl2[pos2--] = seq2[j-1];
	i--; j--;
      }
    else if (matrice[i-1][j] + pSup == matrice[i][j])
      {
	seqAl1[pos1--] = seq1[i-1];
	seqAl2[pos2--] = '_';
	i--;
      }
    else if (matrice[i][j-1] + pSup == matrice[i][j])
      {
	seqAl1[pos1--] = '_';
	seqAl2[pos2--] = seq2[j-1];
	j--;
      }
  }


    //on complète les cases non couvertes par l'algo
    while(pos1 > 0)
      {
	if (i>0) seqAl1[pos1--]=seq1[--i];
	else seqAl1[pos1--]='_';
      }
    while(pos2 > 0)
      {
	if (j>0) seqAl2[pos2--]=seq2[--j];
	else seqAl2[pos2--]='_';
      }


    //les tableaux font m+n de long mais on n'utilise surement pas tout
    //donc on calcule à partir de quand il faut afficher
    int deb=1;
    for(i = l; i>=1; i--)
      {
	if(seqAl1[i]=='_' && seqAl2[i]=='_')
	  {
	    deb+=i;
	    break;
	  }
      }

    //on peut alors afficher l'alignement
    cout<<endl<<"Les séquences alignées sont :"<<endl;
    
    int k=deb;
    while (k<l){
      if(l-k>=70){
	for(j=k; j<=k+70; j++)
	  {
	    cout<<seqAl1[j];
	  }
	cout<<endl;
	for(j=k; j<=k+70; j++)
	  {
	    cout<<seqAl2[j];
	  }
	k+=70;
	cout<<endl<<endl;
      }
      
      else{
	for(j=k; j<=l; j++)
	  {
	    cout<<seqAl1[j];
	  }
	cout<<endl;
	for(j=k; j<=l; j++)
	  {
	    cout<<seqAl2[j];
	  }
	k+=70;
	cout<<endl;
      }
    }
    cout<<endl;
    
}
