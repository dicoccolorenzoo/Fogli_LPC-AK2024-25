#include <stdio.h>
#include <math.h>

#define D  100

double taylor(double, double, int (&k));
double power(double, int);
double fact(int);
double val_ass(double);
double richiedi(int);
void nodi(double, double, int, double (&a)[D], double (&b)[D]);
double interpolazione(double [D], double [D], int, double);

int main(){
    double t=richiedi(0), toll=richiedi(1);
    int n;
    printf("\n Valore del coseno di pi%lf è: %lf calcolato con un polinomio di %d° grado",t, taylor(t,toll, n), n);
    double x[D]={0}, y[D]={0};
    nodi(0,M_PI/2,n+1,x,y);
    for (int i = 0; i <= n; i++) printf("Nodo %d: x = %lf, y = %lf\n", i, x[i], y[i]);
    printf("Il valore calcolato con il polinomio interpolante di Lagrange è: %lf", interpolazione(x,y,n+1,M_PI*t));
}

double taylor(double x, double tau, int (&k)){
    x = M_PI * x;
    double term=1, sum=0;
    int n=0;
    do
    {
        term = power(x, 2*n) * power (-1, n) / fact(2 * n);
        sum += term;
        n++;
    } while (val_ass(term)>tau);
    k=n;
    return sum;
}

double power(double x, int n){
    if (!n) return 1;
    double prod=1;
    for (int i=0; i<n; i++) prod *= x;
    return prod;
}

double fact(int n){
    if (!n) return 1;
    double prod=1;
    for (int i=1; i<=n; i++) prod*=i;
    return prod;
}

double val_ass(double x){
    if (x<0) return x*-1;
    return x;
}

double richiedi(int n){
    double x;
    if (!n) printf("\n Inseirsci una costante: ");
    else printf("\n Inserisci una tolleranza: ");
    scanf("%lf",&x);
    return x;
}

void nodi(double x, double y, int k, double (&a)[D], double (&b)[D]){
  double h=(y-x)/(k-1);
  for (int i=0; i<k; i++) a[i] = x + h*i;
  for (int i=0; i<k; i++) b[i]=cos(a[i]);
}

double interpolazione(double x[D], double y[D], int k, double v){
  double sum=0, prod;
  for (int i=0; i<k; i++){
    prod = 1;
    for (int j=0; j<k; j++) if (j!=i) prod *= (v-x[j])/(x[i]-x[j]);
    sum += y[i] * prod;
  }
  return sum;
}
