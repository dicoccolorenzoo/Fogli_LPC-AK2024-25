#include <stdio.h>
#define N 5

int lettura(int[][N]);
int max_val(int[][N]);
int abs_val(int);

int main(){
  int matr[5][5]={0};
  for (int i=0;i<5;i++){ //i rappresenta l'indice di colonna
    for (int j=0; j<5; j++){ //j rappresenta l'indice di riga
      if (j==i) matr[i][j]=2;
      else if ((j-1==i)||(j+1==i)) matr[i][j]= -1;
    }
  }
  max_val(matr);
  return 0;
}

int max_val(int mat2[][N]){
  int sum=0, val;
  int max1 = 0;
  int max2 = 0;
  
  for (int e=0; e<2; e++){
    val = e;
    for (int l=0; l<5; l++){
      sum = 0;
      for (int y=0; y<5; y++){
	if (!val){
	  sum += abs_val(mat2[l][y]);
	}
	else sum += abs_val(mat2[y][l]);
      }
      if (!val){
	if (max1 < sum) max1=sum;
      } else {
	if (max2 < sum) max2=sum;
      }
    }
  }
  printf("Il massimo con i fisso è %d mentre il massimo con j fisso è %d", max1, max2);
  return (0);
}

int lettura(int mat[][N]){
  for (int h=0; h<5; h++){
    printf("\n");
    for (int t=0; t<5; t++){
      printf("\t %d", mat [h][t]);
    }
  }
  return 0;
}

int abs_val(int a){
  if(a<0) a*=-1;
  return a;
}
