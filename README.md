# cs33211_os_assignment_1

producer-consumer problem

## Sections

### 1. Overview

This project implements the Producer-Consumer problem with POSIX threads, shared memory, mutex locks, and conditions for both of the producer and consumer processes' critical section.

### 2. Libraries Used
<iostream> - Basic I/0 operations
<queue> - Standard queue data structure, FIFO and buffer management
<pthread.h> - POSIX threading, pthread() functions, memory synchronization/execution
<unistd.h> - POSIX operating system API, sleep()

### 3. Compile
1. `g++ producer.cpp -o producer -pthread`
2. `g++ consumer.cpp -o consumer -pthread`

### 4. Run
1. `./producer & ./consumer & `

### 5. Cleanup
To kill all processes after running the program with `./producer & ./consumer & `,
run the UNIX terminal command: `killall producer; killall consumer`