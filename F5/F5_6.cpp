#include <stdio.h>
#define N 1000

int main(){
  int crivello[N+1];
  for (int k=0; k<N+1; k++)
    crivello[k]=1;
  for (int i=2; i*i<=N; i++)
    if (crivello[i])
      for (int j=i*i; j<=N; j+=i)
        crivello[j]=0;
  for (int p=1; p<=N; p++)
    if (crivello[p])
      printf("%d ",p);
}
