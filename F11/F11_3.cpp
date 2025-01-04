#include <stdio.h>
#include <math.h>

#define N 100

int richiedi();
void nodi(double (&x)[N], double (&y)[N], int);
double scegli();
double interpolazione(double [N], double [N], int, double);

int main(){
  int n=richiedi();
  double temp[N],x[N]={0},y[N]={0};
  nodi(x,y,n);
  double z=scegli();
  printf("Il valore è %.10lf ",interpolazione(x,y,n,z));
}

int richiedi(){
  int x;
  do{ printf("\n Inserisci il grado del polinomio calcolato nel file F11_2: ");
  scanf("%d", &x); }
  while (x<0||x>100);
  return x;
}

void nodi(double (&x)[N], double (&y)[N], int n){
  for (int i=0; i<=n; i++){
    x[i] = M_PI*(1+ cos((2.0 * i + 1) / (2.0 * n + 2) * M_PI));
  }
  for (int i=0; i<=n; i++){
    y[i]=cos(x[i]);
  }
}

double scegli(){
  int x;
  printf("\n Il programma è creato per testare valori di 0.4 (1) e 0.1 (2)");
  printf("\n Scegli il valore che preferisci e inserisci l'intero tra parentesi: ");
  do {scanf("%d",&x);} while (x!=1 && x!=2);
  switch (x) {
    case 1:
        return 0.4*M_PI; break;
    case 2:
        return 0.1*M_PI; break;
  }
  printf("\n Non avendo scelto nessun valore la scelta è stata impostata automaticamente su 0.1 \n");
  return 0.1;
}

double interpolazione(double a[N], double b[N], int n, double x){
    double sum = 0, prod=1;
    for (int i=0; i<=n; i++){
      prod = 1;
      for (int j=0; j<=n; j++) if (i!=j) prod *= (x - a[j]) / (a[i] - a[j]);
      sum += b[i] * prod;
    }
    return sum;
}
