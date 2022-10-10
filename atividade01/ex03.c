/**
 * RESPOSTA: Primeiro é criada uma variável do tipo float.
 * Essa variável recebe o valor 10.88. Posteriormente é feita
 * uma chamada para a função mult() com os parâmetros 33 e f.
 * O valor desses parâmetros é copiado para as variáveis de
 * parâmetro da função mult(). Mas durante essa passagem de
 * parâmetro acontece um cast nos dois valores, pois são de
 * tipos diferentes. Logo, a variável num recebe um cast de
 * 33, mas como o tamanho de uma variável do tipo float é maior
 * que o tamanho de uma variável do tipo int, não há perda de 
 * informação, logo num vale 33. Por outro lado, acontece o
 * oposto com o segundo parâmetro, pois, na função principal,
 * o valor é copiado o valor do tipo float para uma variável
 * do tipo int, logo acontece uma perda de informação e, por
 * conta disso, a variável num_02 recebe apenas o valor antes
 * do ponto decimal, ou seja, o valor 10. Na função mult(), a
 * variável aux deve ser atribuida o valor de 33*10, logo 330.00.
*/


#include <stdio.h>

void mult(float num, int num_02);

int
main(void) {
  float f = 10.88;
  mult(33, f);
  return 0;
}

void
mult(float num, int num_02) {
  float aux;
  aux = num*num_02;
  printf("O resultado da multiplicação eh %3.23f", aux);
}