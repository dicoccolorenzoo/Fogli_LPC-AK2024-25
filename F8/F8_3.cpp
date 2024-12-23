#include <stdio.h>
#include <math.h>
#define N 5

void fill_a(float (&a)[N][N]);
void fill_b(float (&b)[N][N]);
void leggi(float [N][N]);
void prodotto(float [N][N], float [N][N], float (&c)[N][N]);
void gauss_p(float (&a)[N][N], int);
void scambia(float (&a)[N][N], int n, int k, int kp);
int ricerca_p(float[N][N], int, int);
float det(float [N][N], int);

int main() {
  float a[N][N] = {0}, b[N][N]={0}, c[N][N]={0};
  fill_a(a);
  fill_b(b);
  printf("Determinante di A: %f\n", det(a,N));
  printf("Determinante di B: %f\n", det(b,N));
  prodotto(a,b,c);
  printf("Determinante di C prodotto tra A e B: %f\n", det(c,N));
}

void fill_a(float (&a)[N][N]){
  for (int i=0; i<N; i++){
    for (int j=0; j<N; j++)
      if (i==j) a[i][j] = 3;
      else if (j==i+1 || j==i-1) a[i][j] = -1;
  }
}

void fill_b(float (&b)[N][N]){
  for (int i=0; i<N; i++){
    for (int j=0; j<N; j++)
      if (i==j) b[i][j] = -1;
      else if (j==i+1) b[i][j] = 0.5;
  }
}

void leggi(float a[N][N]){
  for (int i=0; i<N; i++){
    for (int j=0; j<N; j++)
      printf("%3f \t", a[i][j]);
    printf("\n");
  }
}

 void prodotto(float a[N][N], float b[N][N], float (&c)[N][N]){
  for (int i=0; i<N; i++){
    for (int j=0; j<N; j++){
      for (int k=0; k<N; k++) {
        c[i][j] += b[i][k]*a[k][j];
      }
    }
  }
}
void gauss_p(float (&a)[N][N], int n)
{
  double m;
  int k_p;
  for (int k = 0; k < n - 1; k++)
  {
    k_p = ricerca_p(a, n, k);
    if (k_p > k)
      scambia(a, n, k, k_p);
    for (int i = k + 1; i < n; i++)
    {
      m = a[i][k] / a[k][k];
      for (int j = k; j < n; j++)
        a[i][j] -= m * a[k][j];
    }
  }
}

int ricerca_p(float a[N][N], int n, int k)
{
  double x = fabs(a[k][k]);
  int kp = k;
  for (int i = k + 1; i < n; i++)
  {
    if (fabs(a[i][k]) > x)
    {
      x = fabs(a[i][k]);
      kp = i;
    }
  }
  return kp;
}

void scambia(float (&a)[N][N], int n, int k, int kp)
{
    float temp;
    for (int i = 0; i < n; i++) {
        temp = a[k][i];
        a[k][i] = a[kp][i];
        a[kp][i] = temp;
    }
}

float det(float a[N][N], int n){
  float temp[N][N];
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      temp[i][j] = a[i][j];   
  float det_value = 1;
  gauss_p(temp,n);
  for (int i=0; i<n; i++)
    det_value *= temp[i][i];
  return det_value;
}