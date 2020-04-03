#include <iostream>

using namespace std

int *T= new int[n][m];
T[i][0]=i;
T[0][j]=j;
for (int i=0; i<n; i++)
{
    for(int j=0; j<m; j++)
    {
        int p;
        if i=j
            p=0;
        else p=1;
        T[i][j]= min(T[i-1][j]+1, T[i-1][j-1]+1, T[i][j-1]+p);
    }


};// p.13 de montréal


//
struct element {
  int valeur;
  bool en_haut;
  bool a_gauche;
  bool diag;
};


void calcule_chemin(const string & a,const string & b,
		    const vector< vector<element> > & v,
		    string fin_a, string fin_b, int pos_a, int pos_b,
		    vector<string> & alignements){
  ...
}
 if (v[pos_a][pos_b].en_haut)
    calcule_chemin(a,b,v,a[pos_a-1]+fin_a,'-'+fin_b,pos_a-1,pos_b,alignements);

