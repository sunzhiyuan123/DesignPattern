rm  ./sharedptr1 
rm  ./sharedptr2
rm  ./unique_ptr1
rm  ./weak_ptr1
g++ -o sharedptr1  sharedptr1.cpp  -std=c++11 -lpthread
g++ -o sharedptr2  sharedptr2.cpp  -std=c++11 -lpthread
g++ -o unique_ptr1 unique_ptr1.cpp -std=c++11 -lpthread
g++ -o weak_ptr1   weak_ptr1.cpp   -std=c++11 -lpthread

