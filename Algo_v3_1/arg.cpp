#include <iostream>
#include <string>
#include <string.h>
#include "arg.h"
using namespace std;

void arg(int argc, char**argv, bool *rech, bool *choix, bool *help){

  char tabHelp[]= {'h','e','l','p'};

  
  if(strlen(argv[1])==4)
    {
      for(int i=0; i<4; i++)
	{
	  if(argv[1][i]!=tabHelp[i])
	    {
	      goto endloop;
	    }
	}
      *help=true;
      
      cout<<"Les commandes suivantes peuvent être utilisées :"<<endl;
      cout<<"r - Permet de rechercher les séquences voulues dans le fichier, par défaut les deux premières sont utilisées"<<endl;
      cout<<"c - Active l'entrée par l'utilisateur des pénalités souhaitées lors du calcul, par défaut 1 et 1 sont utilisés"<<endl;
    }
 endloop:


  if (argc>2){
    for(int i=1; i<argc; i++){
      switch(argv[i][0]){
      case 'r': *rech=true;
	break;
      case 'c': *choix=true;
	break;
      }
    }
  }
  
}



