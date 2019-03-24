mkdir -p ./bin
gcc -c ../src/crypto/blake256.c -o bin/blake256.o -std=c17 -Wpedantic -Wextra -Wall -pipe
g++ bin/blake256.o src/main.cpp src/payment_id/payment_id.cpp -o bin/main.exe -std=c++17 -Wpedantic -Wextra -Wall -pipe
