#include <stdio.h>
#define N 100

int scan();
int ver(int);
int fattoriale(int);
int power(int);
double radice(int);
double abs_val(double);
int binario(int, int (&a)[N]);

int main(){
  int n,fatt,pow,a[N],bin;
  double sqrt;
  n = scan();
  if (ver(n)) return 1;
  fatt = fattoriale(n);
  pow = power(n);
  sqrt = radice(n);
  bin = binario(n,a);
  printf("\n Il fattoriale di %d è: %d, %d^5=%d, la radice quadrata è: %.5f mentre in binario vale: ",n,fatt,n,pow,sqrt);
  for (int i=bin-1; i>=0; i--) printf("%d",a[i]);
}

int scan(){
  int n;
  printf("Inserisci un numero intero tra 0 e 64: ");
  scanf("%d", &n);
  return n;
}

int ver(int n){
  if (n<0||n>64) return 1;
  else return 0;
}

int fattoriale(int n){
  int fatt=1;
  for (int i=1; i<=n; i++) fatt *= i;
  return fatt;
}

int power(int n){
  int pow=1;
  for (int i=0; i<5; i++) pow *= n;
  return pow;
}

double radice(int n) {
  double x = n;
  x/=2;
  double x1;
  do {
    x1 = x;
    x = (x1 + n / x1) / 2.0;
  } while (abs_val(x - x1) > 1e-7);
  return x;
}

int binario(int n, int (&a)[N]){
  int cont=0;
  while(n){
    if (n%2) a[cont]=1;
    else a[cont]=0;
    n/=2;
    ++cont;
  }
  return cont;
}

double abs_val(double x){
  if (x<0) x*=-1;
  return x;
}
