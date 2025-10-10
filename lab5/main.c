#include <stdio.h>

int decimalToBinary(int num) {
    int binary = 0;
    int pow = 1;

    while (num > 0) {
        int mod = num % 2;
        binary += mod * pow;
        num /= 2;
        pow *= 10;
    }

    return binary;
}

int main() {
    int x;
    scanf("%d", &x);
    printf("%d", decimalToBinary(x));

    return 0;
}
