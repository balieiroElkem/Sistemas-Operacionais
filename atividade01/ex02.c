#include <stdio.h>
#include <stdlib.h>

// Protótipos de função

void func(float *, int);
float media(float *, int);
float moda(float *, int);
float mediana(float *, int);
float* bubbleSort(float *, int);
int search(float **, float, int);

// -----------------




void
func(float *n, int tam) {
    printf("Media = %.2f\n", media(n, tam));
    printf("Moda = %.2f\n", moda(n, tam));
    printf("Mediana = %.2f\n", mediana(n, tam));
}

float
media(float *n, int tam) {
    float soma = 0;

    for (int i = 0; i < tam; i++) {
        soma += n[i];
    }

    return soma/(float)tam;
}

float
moda(float *n, int tam) {
    float **ptr = calloc(tam, sizeof(float *));
    int contador = 0;
    float maior[2] = {0.0, 0.0};

    for (int i = 0; i < tam; i++) {
        ptr[i] = calloc(2, sizeof(float));
    }

    for (int i = 0; i < tam; i++) {
        int indice = search(ptr, n[i], tam);

        if (indice < 0) {
            ptr[contador][0] = n[i];
            ptr[contador][1] = 1;
            contador++;
        } else if (indice == 0 && ptr[contador][0] == 0 && ptr[contador][1] == 0) {
            ptr[contador][1] = 1;
            contador++;
        } else {
            ptr[contador][1]++;
        }
    }

    for (int i = 0; i < contador; i++) {
        if (ptr[i][1] > maior[1]) {
            maior[0] = ptr[i][0];
            maior[1] = ptr[i][1];
        }
    }

    // Liberando memória usada
    for (int i = 0; i < tam; i++) {
        free(ptr[i]);
        ptr[i] = NULL;
    }
    free(ptr);
    ptr = NULL;

    return maior[0];
}

float
mediana(float *n, int tam) {
    n = bubbleSort(n, tam);

    return n[tam/2];
}

int
search(float **n, float value, int tam) {
    for (int i = 0; i < tam; i++) {
        if (n[i][0] == value) {
            return i;
        }
    }

    return -1;
}

float*
bubbleSort(float *n, int tam) {
    for (int i = tam-1; i >= 1; i--) {
        for (int j = 0; j < i; j++) {
            if (n[j] > n[j+1]) {
                float aux = n[j];
                n[j] = n[j+1];
                n[j+1] = aux;
            }
        }
    }
    
    return n;
}

int
main(void) {
    float elementos[5] = {2, 23, 4, 2, 5};

    func(elementos, 5);

    return 0;
}