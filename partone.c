//Assignment 2 Part 1
//By Konner

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

//Initialize unsigned long long values used in functions
unsigned long long num = 0; //Expected: 1 000 000 000
unsigned long long sum_all = 0;
unsigned long long sum_even = 0;

// Thread functions

//All numbers, child 1
void* calc_all(void* arg) {
    printf("Child Thread 1: ID = %lu\n", pthread_self());
    unsigned long long sum = 0;
    for (unsigned long long i = 1; i <= num; i++) {
        sum += i;
    }
    sum_all = sum;
    pthread_exit(NULL);
}

//All evens, child 2
void* calc_even(void* arg) {
    printf("Child Thread 2: ID = %lu\n", pthread_self());
    unsigned long long sum = 0;
    for (unsigned long long i = 2; i <= num; i += 2) {
        sum += i;
    }
    sum_even = sum;
    pthread_exit(NULL);
}

int main(int argc, char *argv[]) { //Remember to command line in 1000000000
    //Variables for time and initializing threads
    clock_t start_time, end_time;
    double time_spent;
    pthread_t thread1, thread2;
    
    //Converts 1 000 000 000 to unsigned long
    num = strtoull(argv[1], NULL, 10);
    
    start_time = clock();
    printf("Parent Thread: ID = %lu\n", pthread_self());

    // Create both threads
    pthread_create(&thread1, NULL, calc_all, NULL);
    pthread_create(&thread2, NULL, calc_even, NULL);

    // Wait for both threads to complete
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    // Display results
    printf("Child 1 sum all nums: %llu\n", sum_all);
    printf("Child 2 sum all even: %llu\n", sum_even);
    
    //Calculate division
    double divide = (double)sum_all / (double)sum_even;
    printf("Sum1/Sum2 = %.2f\n", divide);

    //Ends the time and calculates the final time IN SECONDS
    end_time = clock();
    time_spent = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("Final time:%.6f", time_spent);

    return 0;
}