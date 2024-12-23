#include <stdio.h>
#include <math.h>
#define N 100

int richiedi();
float richiedi_precisione();
void fill(float (&a)[N][N], int);
void fill_vec(float (&b)[N], float [N][N], int);
int jacobi(float a[N][N], float b[N], float (&x)[N], int, float);
float norma_inf(float [N], float [N], int);
float delta_Jacobi(float [N][N], int);

int main(){
    int n=richiedi();
    float toll=richiedi_precisione();
    float a[N][N];
    fill(a,n);
    float b[N]={0};
    fill_vec(b, a, n);
    float x[N]={0};
    int iter=jacobi(a, b, x, n, toll);
    printf("La soluzione è: ");
    for (int i=0; i<n; i++) printf("%f ", x[i]);
    printf("\n");
    printf("Numero di iterazioni necessarie: %d\n", iter);
    return 0;
}

int richiedi(){
    int n;
    printf("Inserisci un numero intero tra 5 e 100: ");
    scanf("%d", &n);
    if (n<=5 || n>=100){
        printf("Numero non valido, riprova\n");
        return richiedi();
    }
    return n;
}

float richiedi_precisione(){
    float toll;
    printf("Inserisci la tolleranza tra 0 e 1e-4: ");
    scanf("%f", &toll);
    if (toll<=0||toll>1e-4){
        printf("Tollernza non valida, riprova\n");
        return richiedi_precisione();
    }
    return toll;
}

void fill(float (&a)[N][N], int n){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (i == j) a[i][j] = 12;
            else if (fabs(i - j) == 2) a[i][j] = 1;
            else a[i][j] = 0;
        }
    }
}

void fill_vec(float (&b)[N], float a[N][N], int n){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            b[i] += a[i][j];
        }
    }
}

int jacobi(float a[N][N], float b[N], float (&x)[N], int n, float toll){ 
    int iter=0;
    float nuova_sol[N], vecchia_sol[N], sum=0, delta=delta_Jacobi(a, n);
    do{
        for (int i=0; i<n; i++) vecchia_sol[i]=x[i];
        for (int i=0; i<n; i++) nuova_sol[i] = x[i];
        for (int i=0; i<n; i++)
        {
            sum = 0;
            for (int j = 0; j < n; j++)
            {
                if (i != j)
                    sum += a[i][j] * x[j];
            }
            nuova_sol[i] = (b[i] - sum) / a[i][i];
        }
        for (int i=0; i<n; i++) x[i]=nuova_sol[i];
        iter++;
    }
    while (norma_inf(vecchia_sol, nuova_sol, n)>toll*(1-delta)/delta);
    return iter;
}

float norma_inf(float x[N], float y[N], int n)
{
    float max = 0;
    for (int i = 0; i < n; i++){
        if (fabs(x[i] - y[i]) > max)
            max = fabs(x[i] - y[i]);}
    return max;
}

float delta_Jacobi(float a[N][N], int n)
{
    float max = 0, sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = 0;
        for (int j = 0; j < n; j++)
        {
            if (i != j)
                sum += a[i][j];
        }
        sum /= a[i][i];
        if (sum > max)
            max = sum;
    }
    return max;
}