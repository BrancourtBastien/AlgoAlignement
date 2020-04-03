#include<iostream>

class ter1
{
  int *a;
  int *b;
  struct element 
  {
    int valeur;
    bool en_haut;
    bool a_gauche;
    bool diag;
  };

  int elementAligne(int n, int m, int **T);
};