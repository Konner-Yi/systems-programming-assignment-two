//Assignment 2 Part 2
//By Konner

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) { //Remember to command line in 1000000000
    
    //Converts 1 000 000 000 to unsigned long
    unsigned long long num = strtoull(argv[1], NULL, 10);

    //All numbers sum
    unsigned long long sum_all  = 0;
    for (unsigned long long i = 1; i <= num; i++) {
        sum_all += i;
    }

    unsigned long long sum_even = 0;
    for (unsigned long long i = 2; i <= num; i += 2) {
        sum_even += i;
    }

    // Display results
    printf("Sum all nums: %llu\n", sum_all);
    printf("Sum all even: %llu\n", sum_even);
    
    //Calculate division
    double divide = (double)sum_all / (double)sum_even;
    printf("Sum1/Sum2 = %.2f\n", divide);

    return 0;
}