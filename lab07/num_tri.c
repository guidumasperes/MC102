/* Programa que determina se um numero e' triangular */

#include <stdio.h>

int main() {
  int i, n;
  
  printf("Digite o valor de n: ");
  scanf("%d",&n);
  
  /* for com comando vazio! */
  for (i = 1; i*(i+1)*(i+2) <= n; i++);
  
  if (i*(i+1)*(i+2) == n)
    printf("%d e' o produto %d*%d*%d\n", n, i, i+1, i+2);
  else
    printf("%d nao e' triangular\n", n);
  
  return 0;
}
