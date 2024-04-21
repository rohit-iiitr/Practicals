#include <stdio.h>
#include<math.h>

int isArmstrong(int num) {
    int originalNum = num;
    int sum = 0;
    int digits = 0;

    // Count number of digits
    while (originalNum != 0) {
        originalNum /= 10;
        ++digits;
    }

    originalNum = num;
    
    // Calculate the sum of nth power of its digits
    while (originalNum != 0) {
        int remainder = originalNum % 10;
        sum += pow(remainder, digits);
        originalNum /= 10;
    }

    // Check if the number is Armstrong
    if (sum == num)
        return 1;
    else
        return 0;
}

int main() {
    printf("Armstrong numbers up to 1000 are:\n");
    for (int i = 0; i <= 1000; ++i) {
        if (isArmstrong(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");
    return 0;
}
