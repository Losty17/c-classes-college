#include <stdio.h>
#include <stdbool.h>

/**
 * @brief Escreve os valores A, B e C na tela em ordem crescente
 * 
 * @param A 
 * @param B 
 * @param C 
 */
void option1(float A, float B, float C) {
    if (A < B && A < C) {
        printf("%.2f ", A);
        if (B < C) {
            printf("%.2f %.2f", B, C);
        } else {
            printf("%.2f %.2f", C, B);
        }
    } else if (B < A && B < C) {
        printf("%.2f ", B);
        if (A < C) {
            printf("%.2f %.2f", A, C);
        } else {
            printf("%.2f %.2f", C, A);
        }
    } else {
        printf("%.2f ", C);
        if (A < B) {
            printf("%.2f %.2f", A, B);
        } else {
            printf("%.2f %.2f", B, A);
        }
    }
}

/**
 * @brief Escreve os valores A, B e C na tela em ordem decrescente
 * 
 * @param A 
 * @param B 
 * @param C 
 */
void option2(float A, float B, float C) {
    if (A > B && A > C) {
        printf("%.2f ", A);
        if (B > C) {
            printf("%.2f %.2f", B, C);
        } else {
            printf("%.2f %.2f", C, B);
        }
    } else if (B > A && B > C) {
        printf("%.2f ", B);
        if (A > C) {
            printf("%.2f %.2f", A, C);
        } else {
            printf("%.2f %.2f", C, A);
        }
    } else {
        printf("%.2f ", C);
        if (A > B) {
            printf("%.2f %.2f", A, B);
        } else {
            printf("%.2f %.2f", B, A);
        }
    }
}

/**
 * @brief Escreve os valores A, B e C na tela de forma que o maior valor fique entre os outros dois
 * 
 * @param A 
 * @param B 
 * @param C 
 */
void option3(float A, float B, float C) {
    if (A > B && A > C) {
        printf("%.2f %.2f %.2f", C, A, B);
    } else if (B > A && B > C) {
        printf("%.2f %.2f %.2f", C, B, A);
    } else {
        printf("%.2f %.2f %.2f", B, C, A);
    }
}

void readValue(float *value, char numberIdentifier) {
  printf("Digite o valor de %c: ", numberIdentifier);
  scanf("%f", value);
}
void printValues(float A, float B, float C) {
  printf("Os valores de A, B e C são respectivamente: %.2f, %.2f e %.2f", A, B, C);
}
int main() {
  int I;
  float A, B, C;
  readValue(&A, 'A');
  readValue(&B, 'B');
  readValue(&C, 'C');
  printValues(A, B, C);
  printf("\nDigite um valor para I (1, 2 ou 3): ");
  scanf("%d", &I);
  if (I == 1) {
    option1(A, B, C);
  } else if (I == 2) {
    option2(A, B, C);
  } else if (I == 3) {
    option3(A, B, C);
  } else {
    printf("\nOpção inválida");
  }
}