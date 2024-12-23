#include <stdio.h>
#include <math.h>

float funzione(float);
float funzione_derivata(float);
float richiedi(int);
float secanti(float, float, float);

int main(){
    int ch=0;
    float a,b;
    do {
        if (ch) printf("L'estremo inferiore deve essere minore dell'estremo superiore\n");
        a = richiedi(0), b = richiedi(1);
        ch=1;
    }
    while (a>=b);
    printf("La soluzione e': %f", secanti(a,b,0.00001));
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

float secanti(float a, float b, float toll){
    float x, x1=a, x2=b, temp;
    do {
        temp = x1;
        x = x1-funzione(x1)*(x2-x1)/(funzione(x2)-funzione(x1));
        x1 = x2;
        x2 = x;
    } while (fabs(x2-x1)>toll);
    return x;
}