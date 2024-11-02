# cs33211_os_assignment_1
producer-consumer problem

1. Compile
g++ producer.cpp -o producer -pthread
g++ consumer.cpp -o consumer -pthread

2. Run
./producer & ./consumer & 

- Kill all processes:
UNIX terminal cmd: `killall producer; killall consumer`