#include <stdio.h>
#include <stdlib.h>
#include <pthread.h> // For POSIX threads
#include <unistd.h>  // For sleep

int shared_data = 0;

// Mutex for protecting shared_data
pthread_mutex_t mutex;

// Condition variable for signaling between threads
pthread_cond_t cond;

// *** 1. Thread Creation and Joining ***
// Function executed by a thread
void *thread_function(void *arg) {
    char *message = (char *)arg;
    for (int i = 0; i < 3; i++) {
        printf("%s: %d\n", message, i);
        sleep(1);
    }
    return NULL;
}

// *** 2. Mutex for Synchronization (Race Condition Prevention) ***
void *increment_function(void *arg) {
    int *iterations = (int *)arg;
    for (int i = 0; i < *iterations; i++) {
        pthread_mutex_lock(&mutex); // Acquire lock
        shared_data++;              // Critical section
        pthread_mutex_unlock(&mutex); // Release lock
    }
    return NULL;
}

// *** 3. Condition Variables for Inter-Thread Communication ***
void *producer_function(void *arg) {
    int *value_to_produce = (int *)arg;
    sleep(2);
    pthread_mutex_lock(&mutex);
    shared_data = *value_to_produce;
    printf("Producer: Produced data = %d\n", shared_data);
    pthread_cond_signal(&cond); // Signal consumer
    pthread_mutex_unlock(&mutex);
    return NULL;
}

void *consumer_function(void *arg) {
    pthread_mutex_lock(&mutex);
    while (shared_data == 0) { // Wait until data is produced
        printf("Consumer: Waiting for data...\n");
        pthread_cond_wait(&cond, &mutex); // Release mutex and wait for signal
    }
    printf("Consumer: Consumed data = %d\n", shared_data);
    pthread_mutex_unlock(&mutex);
    return NULL;
}
void thread_creation_example();
void mutex_example();
void condition_variable_example();

int main() {
    printf("*** 1. Thread Creation and Joining ***\n");
    thread_creation_example();

    printf("\n*** 2. Mutex for Synchronization ***\n");
    mutex_example();

    printf("\n*** 3. Condition Variables ***\n");
    condition_variable_example();

    return 0;
}

void thread_creation_example() {
    pthread_t thread1, thread2;
    char *msg1 = "Thread 1";
    char *msg2 = "Thread 2";

    // Create threads
    pthread_create(&thread1, NULL, thread_function, (void *)msg1);
    pthread_create(&thread2, NULL, thread_function, (void *)msg2);

    printf("Main thread: Threads created.\n");

    // Wait for threads to finish
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Main thread: All threads finished.\n");
}

void mutex_example() {
    pthread_t tids[2];
    int iterations = 100000;
    shared_data = 0; // Reset shared data

    pthread_mutex_init(&mutex, NULL); // Initialize mutex

    // Create two threads that increment shared_data
    pthread_create(&tids[0], NULL, increment_function, (void *)&iterations);
    pthread_create(&tids[1], NULL, increment_function, (void *)&iterations);

    // Wait for threads to complete
    pthread_join(tids[0], NULL);
    pthread_join(tids[1], NULL);

    printf("Expected shared_data: %d\n", iterations * 2);
    printf("Actual shared_data (with mutex): %d\n", shared_data);

    pthread_mutex_destroy(&mutex); // Destroy mutex
}

void condition_variable_example() {
    pthread_t producer_tid, consumer_tid;
    int produced_value = 100;
    shared_data = 0; // Reset shared data

    pthread_mutex_init(&mutex, NULL);     // Initialize mutex
    pthread_cond_init(&cond, NULL);       // Initialize condition variable

    // Create producer and consumer threads
    pthread_create(&producer_tid, NULL, producer_function, (void *)&produced_value);
    pthread_create(&consumer_tid, NULL, consumer_function, NULL);

    // Wait for threads to complete
    pthread_join(producer_tid, NULL);
    pthread_join(consumer_tid, NULL);

    printf("Condition variable example finished.\n");

    pthread_mutex_destroy(&mutex); // Destroy mutex
    pthread_cond_destroy(&cond);   // Destroy condition variable
}