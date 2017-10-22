rm  ./string
rm  ./vector
rm  ./deque
rm  ./stack
rm  ./queue
rm  ./list
rm  ./set
rm  ./multiset
rm  ./map
rm  ./multimap
rm  ./container_comm

g++ -o string   string.cpp   -std=c++11 -lpthread
g++ -o vector   vector.cpp   -std=c++11 -lpthread
g++ -o deque    deque.cpp    -std=c++11 -lpthread
g++ -o stack    stack.cpp    -std=c++11 -lpthread
g++ -o queue    queue.cpp    -std=c++11 -lpthread
g++ -o list     list.cpp     -std=c++11 -lpthread
g++ -o set      set.cpp      -std=c++11 -lpthread
g++ -o multiset multiset.cpp -std=c++11 -lpthread
g++ -o map      map.cpp      -std=c++11 -lpthread
g++ -o multimap multimap.cpp -std=c++11 -lpthread
g++ -o container_comm container_comm.cpp -std=c++11 -lpthread