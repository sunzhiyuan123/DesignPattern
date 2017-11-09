rm ./thread1
rm ./thread2
rm ./thread3
rm ./condition1
rm ./condition2

g++ -o thread1 thread1.cpp -std=c++11 -lpthread
g++ -o thread2 thread2.cpp -std=c++11 -lpthread
g++ -o thread3 thread3.cpp -std=c++11 -lpthread
g++ -o condition1 condition1.cpp -std=c++11 -lpthread
g++ -o condition2 condition2.cpp -std=c++11 -lpthread