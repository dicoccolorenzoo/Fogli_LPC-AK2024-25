#include <stdio.h>
#define N 5

void prod(float [N][N],float [N][N], float (&mat_f)[N][N]);
void leggi(float [N][N]);

int main(){
  float mat1[N][N]={0}, mat2[N][N]={0}, mat_f[N][N]={0};
  for (int i=0;i<5;i++){ //i rappresenta l'indice di colonna
    for (int j=0; j<5; j++){ //j rappresenta l'indice di riga
      if (j==i) mat1[i][j]=2;
      else if ((j-1==i)||(j+1==i)) mat1[i][j]= -1;
    }
  }
  for (int i=0;i<5;i++){ //i rappresenta l'indice di colonna
    for (int j=0; j<5; j++){ //j rappresenta l'indice di riga
      if ((j-1==i)||(j+1==i)) mat2[i][j]= 1;
    }
  }
  prod(mat1,mat2,mat_f);
  printf("\n");
  leggi(mat_f);
}

void prod(float mat1[N][N],float mat2[N][N], float (&mat_f)[N][N]){
  for (int i=0; i<N; i++){
    for (int j=0; j<N; j++){
      for (int k=0; k<N; k++){
        mat_f[i][j]+=mat1[i][k]*mat2[k][j];
      }
    }
  }
}

void leggi(float mat_f[N][N]){
  for (int i=0; i<N; i++){
    for (int j=0; j<N; j++){
      printf("%f \t",mat_f[i][j]);
    }
    printf("\n");
  }
}
