rm  ./sharedptr1 
rm  ./sharedptr2
g++ -o sharedptr1  sharedptr1.cpp -std=c++11 -lpthread
g++ -o sharedptr2  sharedptr2.cpp -std=c++11 -lpthread

