// #include <stdio.h>

// // Function to calculate the nth Fibonacci number recursively
// int fibonacciRecursion(int n) {
//     if (n <= 1)
//         return n;
//     return fibonacciRecursion(n - 1) + fibonacciRecursion(n - 2);
// }

// int main() {
//     int n = 10; // Number of Fibonacci numbers to print
//     printf("Fibonacci series using recursion:\n");
//     for (int i = 0; i < n; ++i) {
//         printf("%d ", fibonacciRecursion(i));
//     }
//     printf("\n");
//     return 0;
// }

// #include <stdio.h>

// int main() {
//     int n = 10; // Number of Fibonacci numbers to print
//     int first = 0, second = 1, next;

//     printf("Fibonacci series using for loop:\n");
//     for (int i = 0; i < n; ++i) {
//         printf("%d ", first);
//         next = first + second;
//         first = second;
//         second = next;
//     }
//     printf("\n");
//     return 0;
// }


// #include <stdio.h>

// int main() {
//     int n = 10; // Number of Fibonacci numbers to print
//     int first = 0, second = 1, next;
//     int i = 0;

//     printf("Fibonacci series using do-while loop:\n");
//     do {
//         printf("%d ", first);
//         next = first + second;
//         first = second;
//         second = next;
//         ++i;
//     } while (i < n);
//     printf("\n");
//     return 0;
// }
