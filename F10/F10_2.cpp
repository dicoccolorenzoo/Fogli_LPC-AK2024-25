#include <stdio.h>
#include <math.h>

float funzione(float);
float funzione_derivata(float);
float richiedi(int);
float newton(float, float);

int main(){
    int ch=0;
    float a,b;
    do {
        if (ch) printf("L'estremo inferiore deve essere minore dell'estremo superiore\n");
        a = richiedi(0), b = richiedi(1);
        ch=1;
    }
    while (a>=b);
    printf("La soluzione e': %f", newton(a,0.00001));
}

float funzione(float x){
    return log(x)+x;
}

float funzione_derivata(float x){
    return 1/x+1;
}

float richiedi(int a){
    float x;
    if (!a) printf("Inserisci l'estermo inferiore");
    else printf("Inserisci l'estermo superiore");
    printf(": ");
    scanf("%f", &x);
    return x;
}

float newton(float a, float toll){
    float x=a, x1, temp;
    do {
        temp = x;
        x1 = x-funzione(x)/funzione_derivata(x);
        x = x1;
    } while (fabs(temp-x1)>toll);
    return x;
}