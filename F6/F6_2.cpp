#include <stdio.h>
#define N 10

int input();
void crea_vet(float (&v)[N], int);
float prod_vet(float [N], int);
float media_vet(float [N], int);
void scambia(float (&v)[N],int);
int min_val(float [N], int);
int max_val(float [N], int);
float abs(float);

//Main

int main(){
  int n= input();
  if (n<0||n>10) return 1;
  float v[N];
  crea_vet(v,n);
  printf("\n Il prodotto tra le componenti del vettore è: %.2f mentre la media è %.2f", prod_vet(v,n), media_vet(v,n));
  scambia(v,n);
}

//Elenco delle funzioni

int input(){
  int n;
  printf("Inserisci un numero tra 1 e 10: ");
  scanf("%d",&n);
  return n;
}

void crea_vet(float (&v)[N], int n){
  float x;
  for (int i=0; i<n; i++){
    printf("\n Inserisci la componente numero %d del vettore: ",i+1);
    scanf("%f",&v[i]);
  }
}

float prod_vet(float v[N], int n){
  float prod=1;
  for (int i=0; i<n; i++){
    prod *= v[i];
  }
  return prod;
}

float media_vet(float v[N], int n){
  float sum=0;
  for (int i=0; i<n; i++){
    sum += v[i];
  }
  return sum/n;
}

void scambia(float (&v)[N],int n){
  int min=min_val(v,n),max=max_val(v,n);
  float scambia=v[min];
  v[min]= v[max];
  v[max]= scambia;
  printf("\n Il valore massimo è %.2f che adesso è al posto %d° e il valore minimo è %.2f che ora è al %d° posto",v[min],min+1,v[max],max+1);
}

int min_val(float v[N], int n){
  float min=v[0];
  int send;
  for (int i=1; i<n; i++){
    if (abs(v[i])<abs(min)){
      min = v[i];
      send = i;
    }
  }
  return send;
}

int max_val(float v[N], int n){
  float max=v[0];
  int send;
  for (int i=1; i<n; i++){
    if (abs(v[i])>abs(max)){
      max = v[i];
      send = i;
    }
  }
  return send;
}

float abs(float x){
  if (x<0) x*=-1;
  return x;
}
