#include <stdio.h>
#include <stdbool.h>


float getProductPrice(int productCode) {
  float price;
  // Especificação Preço unitário
  // 100 Cachorro quente R$3,50
  // 101 Bauru simples R$4,00
  // 102 Bauru c/ovo R$4,50
  // 103 Hamburger R$4,00
  // 104 Cheeseburger R$3,00
  switch (productCode) {
    case 100:
      price = 3.50;
      break;
    case 101:
      price = 4.0;
      break;
    case 102:
      price = 4.50;
      break;
    case 103:
      price = 4.0;
      break;
    case 104:
      price = 3.00;
      break;
    default:
      price = 0;
      break;
  }
  return price;
}
float calculateTotal(float price, int quantity) {
  return price * quantity;
}

void printMenu() {
  printf("\nEspecificação Preço unitário");
  printf("\n100 Cachorro quente R$3,50");
  printf("\n101 Bauru simples R$4,00");
  printf("\n102 Bauru c/ovo R$4,50");
  printf("\n103 Hamburger R$4,00");
  printf("\n104 Cheeseburger R$3,00");
}

int main() {
  int productCode, quantity;
  printMenu();
  printf("\nDigite o código do produto: ");
  scanf("%d", &productCode);
  printf("\nDigite a quantidade: ");
  scanf("%d", &quantity);
  float price = getProductPrice(productCode);
  float total = calculateTotal(price, quantity);
  printf("\nO total a pagar é: %.2f", total);
}