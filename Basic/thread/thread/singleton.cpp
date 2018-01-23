#include <iostream>
#include "singleton.h"

using namespace std;

std::unique_ptr<Processor1> Processor1::instance = nullptr;

void Processor1::Process( )
{
	while (IsRunning( ))
	{
		cout<<"enter test"<<endl;
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
	
	cout<<"exit StartProcess"<<endl;
}
