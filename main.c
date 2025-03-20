#include <stdio.h>
#include "stack.h"

int main() {
    int decimal;

    // Input bilangan desimal
    printf("Masukkan bilangan desimal: ");
    scanf("%d", &decimal);

    // Panggil fungsi konversi
    decimalToBinary(decimal);

    return 0;
}
