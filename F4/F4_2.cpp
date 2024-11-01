/* Programma che approssima il pi greco tramite l'algoritmo di archimede*/

#import <stdio.h>
#import <math.h>

float absVal(float x){
  if (x<0)x=-x;
  return x;
}

int main(){
  int m=4;
  double l=M_SQRT2;
  for (int i=2;i<=25;i++){
    l=l/sqrt(2+sqrt(4-l*l));
    m*=2;
    printf("Un poligono di %d lati approssima il pi greco a %.15f \n",m,l*m/2);
  }
  printf("L'approssimazione del pi greco è di %.15f mentre il pi greco di math.h è %.15f l'errore relativo è di %.15f su 15 cifre decimali",l*m/2,M_PI,absVal(M_PI-l*m/2));
  return 0;
}
