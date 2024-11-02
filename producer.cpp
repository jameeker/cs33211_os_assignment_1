#include <iostream>
#include <pthread.h>
#include <queue>
#include <unistd.h>
#include "shared_buffer.h"

std::queue<int> buffer;                                     // Define a shared memory buffer
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;          // Define mutex lock for mutual exclusion
pthread_cond_t buffer_not_full = PTHREAD_COND_INITIALIZER;  // Define buffer not full
pthread_cond_t buffer_not_empty = PTHREAD_COND_INITIALIZER; // Define buffer not empty

int main() {
    int item = 0; // Declare and initialize an item
    while (true) {
        item++;  // Produce an item
        pthread_mutex_lock(&mutex); // Lock mutex

        while (buffer.size() == BUFFER_SIZE) { // If buffer is full, wait
            pthread_cond_wait(&buffer_not_full, &mutex);
        }

        buffer.push(item); // Add an item to the buffer
        std::cout << "Produced: " << item << std::endl;

        pthread_cond_signal(&buffer_not_empty); // Signal that the buffer isn't empty
        pthread_mutex_unlock(&mutex); // Unlock mutex

        sleep(1); // Delay time to simulate the producer producing an item
    }

    pthread_mutex_destroy(&mutex);           // Cleanup mutex memory
    pthread_cond_destroy(&buffer_not_full);  // Cleanup empty buffer memory
    pthread_cond_destroy(&buffer_not_empty); // Cleanup filled buffer memory

    return 0;
}