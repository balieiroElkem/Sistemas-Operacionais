/**
 * RESPOSTA: O primeiro função (impulso(int a)) não funciona
 * como deveria porque é copiado o valor da variável teste
 * para a variável a, por isso qualquer modificação que a
 * sofrer na função não afterar a variável externa. Logo
 * se faz necessário o uso de ponteiro para poder copiar o
 * endereço da variável teste para a função impulso().
 * A segunda função pode ser melhorada também com o uso 
 * de ponteiros, pois o array a está declarado com um 
 * array de inteiro com 10 posições. Logo essa variável
 * fica limitada a 10 posições. Para modificar para qualquer
 * tamanho basta declara como um ponteiro para inteiro que 
 * recebe um array de valores inteiros. Com isso ela fica 
 * mais preparada.
*/



#include <stdio.h>

void
impulso(int *a) {
  *a = 1;
}


void
impulso_vet(int *a, int total) {
  for (int i = 0; i < total; ++i) {
    a[i] = 1;
    printf("[impulso] %ld %d %d \n", sizeof(a), i, a[i]);
  }
}


int
main(void) {
  int teste = 200;
  impulso(&teste);
  printf("Impulso inicial: %d \n", teste);

  int DIM = 10;
  int sinal[DIM];
  impulso_vet(sinal, DIM);
  for (int i = 0; i < DIM; i++) {
    printf("%d.%ld %d \n", i, sizeof(sinal), sinal[i]);
  }
  
  return 0;
}