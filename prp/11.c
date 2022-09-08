#include <stdio.h>
#include <stdlib.h>

int calculateFinalPrice(int price, int customerType) {
  if (customerType == 1) {
    return price;
  } else if (customerType == 2) {
    return price * 0.9;
  } else if (customerType == 3) {
    return price * 0.95;
  } else {
    return price;
  }
}
int main() {
    float price, finalPrice;
    int customerType; // 1 for normal customer, 2 for special customer and 3 for employee
    printf("Digite o preço da compra: ");
    scanf("%f", &price);
    printf("Digite o tipo de cliente (1 para cliente normal, 2 para cliente especial e 3 para funcionário): ");
    scanf("%d", &customerType);
    if (customerType != 1 && customerType != 2 && customerType != 3) {
        printf("Tipo de cliente inválido!");
        return 1;
    }
    finalPrice = calculateFinalPrice(price, customerType);
    printf("O preço da compra com o desconto aplicado é: %.2f", finalPrice);

}