#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
using namespace std;
#define N 50
#define R 15

void leggi(int [N][N], int, int [N]);
void creaMat(int (&arr)[N][N], int);
void creaVett(int [N][N], int (&vett)[N], int);
void calcolaSol(int [N][N], int, int [N]);

int main(){
  int b[N], A[N][N]={0}, n, sum;
  printf("Inserisci la grandezza della matrice: ");
  scanf("%d", &n);
  creaMat(A,n);
  creaVett(A,b,n);
  printf("\n Il sistema: ");
  leggi(A,n,b);
  printf("\n Ha soluzioni: \n");
  calcolaSol(A,n,b);
  return 0;
}

void leggi(int mat[][N],int n0, int vect[N]){
  for (int k0=0; k0<n0; k0++){
    printf("\n");
    for (int k1=0; k1<n0+1; k1++){
      if (k1<n0) printf("%d(x%d) \t", mat[k1][k0], k1+1);
      else printf("=%d \t", vect[k0]);
    }
  }
}

void creaMat(int (&arr)[N][N], int n1) {
  srand(time(0));
  for (int k2=0; k2<n1; k2++){
    for (int k3=0; k3<n1; k3++){
      if (k3>=k2) arr[k2][k3] = rand()%R+1;
    }
  }
}

void creaVett(int array[N][N], int (&vett)[N], int n2) {
  int sum;
  for (int k4=0; k4<n2; k4++){
    sum = 0;
    for (int k5=0; k5<n2; k5++){
      sum += array[k5][k4];
    }
    vett[k4]=sum;
  }
}

void calcolaSol(int matrice[N][N], int n3, int vettore[N]){
  int somma, soluzione[N]={0};
  soluzione[0] = vettore[0]/matrice[0][0];
  printf("\n La soluzione x1 è: %d", soluzione[0]);
  for (int k6=1; k6<n3; k6++){
    somma = 0;
    for (int k7=0; k7<k6; k7++){
      somma += soluzione[k7]*matrice[k7][k6];
    }
    soluzione[k6] = (vettore[k6]-somma)/matrice[k6][k6];
    printf("\n La soluzione x%d è: %d", k6+1, soluzione[k6]);
  }
}
