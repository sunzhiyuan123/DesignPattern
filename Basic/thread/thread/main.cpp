#include <iostream>
#include "thread.h"
#include "singleton.h"

using namespace std;

int main( )
{
	int num = 0;
	
	while(1)
	{
		Processor1::Instance( ).Run( );
		std::this_thread::sleep_for(std::chrono::seconds(5));
		Processor1::Instance( ).Stop( );
		
		num++;
		if(num >= 5)
		{
			break;
		}
	}

	return 0;
}