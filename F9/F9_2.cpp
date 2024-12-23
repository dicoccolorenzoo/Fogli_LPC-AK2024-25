#include <stdio.h>
#include <math.h>
#define N 5

int richiedi();
void fill(float (&a)[N][N], int);
void leggi(float [N][N], int);
int verifica(float [N][N], int);
void fill_vec(float (&b)[N], int);
void jacobi(float a[N][N], float b[N], float (&x)[N], int);
int iterazione_Jacobi(float a[N][N], float b[N], float x[N], int, float);


int main(){
    int n=richiedi();
    float a[N][N];
    printf("Inserisci i valori della matrice diagonale dominante\n");
    do {fill(a,n);} while (verifica(a,n));
    float b[N];
    printf("Inserisci i valori del vettore soluzione\n");
    fill_vec(b,n);
    float x[N] = {0};
    float toll = 1e-4;
    int iter = iterazione_Jacobi(a, b, x, n, toll) + 1;
    printf("Numero di iterazioni necessarie: %d\n", iter);
    while (iter > 0){
        jacobi(a, b, x, n);
        iter--;
    }
    printf("La soluzione è: ");
    for (int i=0; i<n; i++) printf("%f ", x[i]);
    printf("\n");
    return 0;
}

int richiedi(){
    int n;
    printf("Inserisci un numero intero tra 1 e 5: ");
    scanf("%d", &n);
    if (n<1 || n>5){
        printf("Numero non valido, riprova\n");
        return richiedi();
    }
    return n;
}

void fill(float (&a)[N][N], int n){
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            printf("Inserisci il valore per la posizione %d,%d: ", i, j);
            scanf("%f", &a[i][j]);
        }
    }
}

void leggi(float a[N][N], int n){
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            printf("%f ", a[i][j]);
        }
        printf("\n");
    }
}

int verifica(float a[N][N], int n){
    for (int i=0; i<n; i++){
        float sum=0;
        for (int j=0; j<n; j++){
            if (i!=j) sum += fabsf(a[i][j]);
        }
        if (fabsf(a[i][i]) <= sum) {
            printf("La matrice non è diagonale dominante\n");
            return 1;
        };
    }
    return 0;
}

void fill_vec(float (&b)[N], int n){
    for (int i=0; i<n; i++){
        printf("Inserisci il valore per la posizione %d: ", i);
        scanf("%f", &b[i]);
    }
}

void jacobi(float a[N][N], float b[N], float (&x)[N], int n){
    float n_sol[N], sum=0;
    for (int i=0; i<n; i++){
        sum=0;
        for (int j=0; j<n; j++){
            if (i!=j) sum += a[i][j] * x[j];
        }
        n_sol[i] = (b[i] - sum) / a[i][i];
    }
    for (int i=0; i<n; i++) x[i] = n_sol[i];
}

int iterazione_Jacobi(float a[N][N], float b[N], float x[N], int n, float toll){
    float max=0, sum=0;
    for (int i=0; i<n; i++){
        sum=0;
        for (int j=0; j<n; j++){
            if (i!=j) sum += a[i][j];
        }
        sum /= a[i][i];
        if (sum > max) max = sum;
    }
    float temp[N]={0};
    jacobi(a, b, temp, n);
    float max_diff=0;
    for (int i=0; i<n; i++) if (fabs(temp[i]-x[i]) > max_diff) max_diff = fabs(temp[i]-x[i]);
    int iter=log10((toll/max_diff)*(1-max))/log10(max);
    return iter;
}