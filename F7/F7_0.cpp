#include <stdio.h>
#define N 5

int lettura(int[][N]);

int main(){
  int A[5][5]={0};
  for (int i=0;i<5;i++){ //i rappresenta l'indice di colonna
    for (int j=0; j<5; j++){ //j rappresenta l'indice di riga
      if (j==i) A[i][j]=2;
      else if ((j-1==i)||(j+1==i)) A[i][j]= -1;
    }
  }
  int B[5][5]={0};
  for (int h=0; h<N; h++){
    for (int m=0;m<N;m++){
      if((m-1==h)||(m+1==h)) B[h][m]=1;
    }
  }
  lettura(B);
  return 0;
}

int lettura(int mat[][N]){
  for (int r=0; r<5; r++){
    printf("\n");
    for (int t=0; t<5; t++){
      printf("\t %d", mat [r][t]);
    }
  }
  return 0;
}

