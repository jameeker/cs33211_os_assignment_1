#include <iostream>
#include <thread>
#include <cstring>

#include <semaphore.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>

using namespace std;

int r1, total_produced = 0, total_consumed = 0;

// 'semaphore type'
sem_t notEmpty;

// Producer
void* producer(void *arg){ 
    while(1) { 
      cout << "Producer produces item." << endl; 
      cout << "Total produced = " << ++total_produced << " Total consume = "<<total_consumed*-1<<endl; 
      sem_post(&notEmpty);     
      sleep(rand()%100*0.01); 
    } 
} 