#include <stdio.h>
#define N 10

int input();
void crea_vett(double (&a)[N],int);
void ord(double (&v)[N],int);
void scambia(int,int, double (&v)[N]);

int main(){
  int n=input();
  double v[N];
  if (!n) return  1;
  crea_vett(v,n);
  ord(v,n);
  for (int i=0; i<n; i++) printf("%.2f,",v[i]);
  printf("La mediana è: ");
  if (n%2) printf("%.2f",v[n/2]);
  else printf("%.2f,%.2f",v[n/2-1],v[n/2]);
  return 0;
}

int input(){
  int n;
  printf("Inserisci un numero tra 1 e 10: ");
  scanf("%d", &n);
  if (n<0||n>10) return 0;
  return n;
}

void crea_vett(double (&a)[N],int n){
  double x;
  for (int i=0; i<n; i++){
    printf("\n Inserisci la componente n%d del vettore: ",i+1);
    scanf("%lf",&x);
    a[i]=x;
  }
}

void scambia(int i, int ind, double (&v)[N]){
  double scamb=v[i];
  v[i]=v[ind];
  v[ind]=scamb;
}

void ord(double (&v)[N],int n){
  int ind;
  for (int i=0; i<n; i++){
    ind=i;
    for (int j=i+1; j<n; j++)
      if(v[j]<v[ind]) ind=j;
    if(ind!=i) scambia(i,ind,v);
  }
}
