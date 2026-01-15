#include <stdio.h>

void decimalToBinary(int n) {
    if (n == 0)
        return;
    decimalToBinary(n / 2);   // Recursive call
    printf("%d", n % 2);      // Print remainder (binary digit)
}

int main() {
   
    int num = 56;

    if (num == 0) {
        printf("0");
    } else {
        printf("Binary equivalent: ");
        decimalToBinary(num);
    }

    printf("\n");
    return 0;
}
