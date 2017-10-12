#include <iostream>  
#include <memory> // shared_ptr  
#include <thread>  
#include <chrono>  
#include <mutex>
#include <vector>
#include <string>
#include <unistd.h>
using namespace std;  

struct base
{
    virtual ~base() { sleep(1); }
    virtual void func() = 0;
};

struct derived : public base
{
    virtual ~derived() { }
    virtual void func() { return; }
};

static void *thread_func(void* v)
{
    base *b = reinterpret_cast<base*>(v);
    while (true) 
	b->func();
    return 0;
}

int main()
{
    pthread_t t;
    base *b = new derived();
    pthread_create(&t, 0, thread_func, b);
    delete b;
    return 0;
}