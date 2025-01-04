#include <stdio.h>
#include <math.h>

float richiedi();
float esponenziale_modulo_taylor(float, float);
float power(float, int);
float assoluto(float);
int fattoriale(int);

int main(){
    float x=richiedi();
    printf("Il valore di e^|%f| (con una tollerenza di e-10) è %f ", x, esponenziale_modulo_taylor(x,power(10,-10)));
}

float richiedi(){
    float x;
    do{
    printf("Inserisci un valore compreso tra -1 e 1: \n");
    scanf("%f",&x);}
    while (x<-1||x>1);
    return x;
}

float esponenziale_modulo_taylor(float x, float toll){
    float term = 1, sum = 0;
    int n=0;
    while (term > toll / M_E)
    {
        term = power(assoluto(x),n) / fattoriale(n);
        sum += term;
        n++;
    }
    return sum;
}

float power(float x, int n){
    if (!n) return 1;
    float prod=1;
    if (n>0) for (int i=0; i<n; i++) prod *= x;
    else for (int i=0; i<assoluto(n); i++) prod *= 1./x;
    return prod;
}

float assoluto(float x){
    if(x<0) return x*-1;
    return x;
}

int fattoriale(int n){
    if (!n) return 1;
    int prod=1;
    for (int i=1; i<=n; i++) prod*=i;
    return prod;
}