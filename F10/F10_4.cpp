#include <stdio.h>
#include <math.h>

float funzione(float, int);
float funzione_derivata(float, int);
float richiedi(int);
float power(float, int);
int richiedi_metodo();
float soluzione_metodo(float, float, int, int);
float bisezione(float, float, float, int);
int richiedi_tipo_funzione();
float secanti(float, float, float, int);
float newton(float, float, float, int);


int main(){
    int ch=0;
    float a,b;
    do {
        if (ch) printf("L'estremo inferiore deve essere minore dell'estremo superiore\n");
        a = richiedi(0), b = richiedi(1);
        ch=1;
    }
    while (a>=b);
    int metodo;
    int n;
    do {n=richiedi_tipo_funzione();} while(n<0||n>5);
    do {metodo=richiedi_metodo();} while(metodo!=1&&metodo!=2&&metodo!=3);
    float soluzione=soluzione_metodo(a,b,metodo, n);
    printf("La soluzione e': %f", soluzione);
}

float funzione(float x, int a){
    switch (a){
        case 0: return power(x,2)-2;
        case 1: return power(x,5)-6*power(x,3)+3;
        case 2: return x-exp(-x);
        case 3: return power(x,2)-sin(x);
        case 4: return x - cos(x);
        case 5: return power(x,2)-2-log(x);
    }
    return 0;
}

float funzione_derivata(float x, int a){
    switch (a){
        case 0: return 2*x;
        case 1: return 5*power(x,4)-18*power(x,2);
        case 2: return x-exp(-x);
        case 3: return 2*x-cos(x);
        case 4: return 1+sin(x);
        case 5: return 2*x-1/x;
    }
    return 0;
}

float richiedi(int a){
    float x;
    if (!a) printf("Inserisci l'estermo inferiore");
    else printf("Inserisci l'estermo superiore");
    printf(": ");
    scanf("%f", &x);
    return x;
}

float power(float x, int a){
    float res=1;
    for (int i=0; i<a; i++) res*=x;
    return res;
}

int richiedi_metodo(){
    int x;
    printf("Scegli il metodo con cui vuoi risolvere l'equazione: \n 1. Secanti \n 2. Newton \n 3. Bisezione \n");
    printf(": ");
    scanf("%d", &x);
    return x;
}

float soluzione_metodo(float a, float b, int metodo, int n){
    switch (metodo){
        case 3: return bisezione(a,b,0.0001,n);
        case 1: return secanti(a,b,0.0001,n);
        case 2: return newton(a,b,0.0001,n);
    }
    return 0;
}

int richiedi_tipo_funzione(){
    int x;
    printf("Scegli il tipo di funzione con cui vuoi risolvere l'equazione: \n 0. x^2-2 \n 1. x^5-6x^3+3 \n 2. x-e^-x \n 3. x^2-sin(x) \n 4. x-cos(x) \n 5. x^2-2-log(x) \n");
    printf(": ");
    scanf("%d", &x);
    return x;
}

float bisezione(float a, float b, float toll, int n){
    float x=(a+b)/2;
    do {
        if (funzione(x,n)*funzione(a,n)<0) b=x;
        else a=x;
        x=(a+b)/2;
        printf("x: %f\n", x);
    } while (fabs(a-b)>toll);
    return x;
}

float secanti(float a, float b, float toll, int n){
    float x=a;
    do {
        x=a-funzione(a,n)*(b-a)/(funzione(b,n)-funzione(a,n));
        a=b;
        b=x;
    } while (fabs(a-b)>toll);
    return x;
}

float newton(float a, float b, float toll, int n){
    float x=a;
    do {
        x=a-funzione(a,n)/funzione_derivata(a,n);
        a=b;
        b=x;
    } while (fabs(a-b)>toll);
    return x;
}