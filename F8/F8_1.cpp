#include <stdio.h>
#define N 5

void fill(float (&m)[N][N], float (&v)[N]);
void gauss(float (&a)[N][N], float (&v)[N]);
void soluzione(float [N][N], float [N], float (&s)[N]);

int main(){
  float m[N][N]={0}, v[N]={0},y[N]={0};
  fill(m,v);
  gauss(m,v);
  soluzione(m,v,y);
}

void fill(float (&m)[N][N], float (&v)[N]){
  for (int i=0; i<N; i++){
    for (int j=0; j<N; j++){
      if (i==j) m[i][j]=3;
      else if (j==i+1||j==i-1) m[i][j]=-1;
    }
  }
  for (int i=0; i<N; i++){
    if (i==0||i==N-1) v[i]=2;
    else v[i]=1;
  }
}

void gauss(float (&a)[N][N], float (&v)[N]){
  double m;
  for (int k=0; k<N-1; k++)
    for (int i=k+1; i<N; i++){
      m=a[i][k]/a[k][k];
      for (int j=k; j<N; j++)
        a[i][j]-=m*a[k][j];
      v[i]-=m*v[k];
    }
}

void soluzione(float a[N][N], float v[N], float (&s)[N]){
  for (int i=N-1; i>=0; i--) {
    for (int j=N-1; j>i; j--){
      v[i]-=a[i][j]*s[j];
    }
    s[i]=v[i]/a[i][i];
  }
  printf("Le soluzioni delle incognite sono: ");
  for (int i=0; i<N; i++){
    printf("%f, ",s[i]);
  }
}
