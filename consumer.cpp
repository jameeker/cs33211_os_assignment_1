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
    while (true) {
        pthread_mutex_lock(&mutex); // Lock mutex

        while (buffer.empty()) { // If buffer is full, wait
            pthread_cond_wait(&buffer_not_empty, &mutex);
        }

        int item = buffer.front(); 
        buffer.pop(); // Remove an item from buffer
        std::cout << "Consumed: " << item << std::endl;

        pthread_cond_signal(&buffer_not_full); // Signal that the buffer isn't full
        pthread_mutex_unlock(&mutex); // Unlock mutex

        sleep(2); // Delay time to simulate the consumer's consumption of an item
    }

    pthread_mutex_destroy(&mutex);           // Cleanup mutex memory
    pthread_cond_destroy(&buffer_not_full);  // Cleanup empty buffer memory
    pthread_cond_destroy(&buffer_not_empty); // Cleanup filled buffer memory

    return 0;
}