#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define N 50

double casuale();
void leggi(float [N][N],int, float [N]);
void fill(float (&a)[N][N], float (&v)[N],int);
void gauss_p(float (&a)[N][N], float (&v)[N], int);
void scambia(float (&a)[N][N], float (&v)[N], int n, int k, int kp);
int ricerca_p(float[N][N], int, int);
void back_sub(float (&a)[N][N], float (&v)[N], float (&x)[N], int n);

int main() {
  srand(time(NULL));
  int n;
  printf("Inserisci un numero intero tra 0 e 50: ");
  scanf("%d", &n);
  if (n<0||n>50) return 1;
  float a[N][N]={0}, v[N]={0}, x[N]={0};
  fill(a,v,n);
  leggi(a,n,v);
  printf("\n");
  gauss_p(a,v,n);
  leggi(a,n,v);
  back_sub(a,v,x,n);
}

void leggi(float a[N][N],int n, float v[N]){
  for (int i=0; i<n; i++){
    printf("\n");
    for (int j=0; j<n; j++){
      printf("%3f \t",a[i][j]);
    }
    printf("| %3f",v[i]);
  }
}

double casuale(){
  double rand_n = 2.0*((double)rand()/RAND_MAX)-1.0;
  return rand_n;
}

void fill(float (&a)[N][N], float (&v)[N], int n){
  for (int i=0; i<n; i++)
    for (int j=0; j<n; j++){
      a[i][j] = casuale();
      v[i] += a[i][j];
    }
}

void gauss_p(float (&a)[N][N], float (&v)[N], int n){
  double m;
  int k_p;
  for (int k=0; k<n-1; k++){
    k_p = ricerca_p(a,n,k);
    if (k_p>k) scambia(a,v,n,k,k_p);
    for (int i=k+1; i<n; i++){
      m=a[i][k]/a[k][k];
      for (int j=k; j<n; j++)
        a[i][j]-=m*a[k][j];
      v[i]-=m*v[k];
    }
  }
}

int ricerca_p(float a[N][N], int n, int k){
    double x = fabs(a[k][k]);
    int kp = k;
    for (int i = k+1; i < n; i++){
        if (fabs(a[i][k]) > x) {
            x = fabs(a[i][k]);
            kp = i;
        }
    }
    return kp;
}

void scambia(float (&a)[N][N], float (&v)[N], int n, int k, int kp){
  float sc1[N], sc2[N], sc1_v, sc2_v;
  for (int i=0; i<n; i++){
    sc1[i] = a[k][i];
    sc2[i] = a[kp][i];
    sc1_v = v[k];
    sc2_v = v[kp];
  }
  for (int i=0; i<n; i++){
    a[k][i] = sc2[i];
    a[kp][i] = sc1[i];
    v[k] = sc2_v;
    v[kp] = sc1_v;
  }
}

void back_sub(float (&a)[N][N], float (&v)[N], float (&x)[N], int n){
  for (int i=n-1; i>=0; i--){
    x[i] = v[i];
    for (int j=i+1; j<n; j++)
      x[i] -= a[i][j]*x[j];
    x[i] /= a[i][i];
  }
  
  printf("\nSoluzioni del sistema:\n");
  for(int i=0; i<n; i++){
    printf("x[%d] = %f\n", i, x[i]);
  }
}