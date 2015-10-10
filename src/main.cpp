#include <iostream>
#include <stdexcept>
#include "Queue.h"

int main()
{
	Queue q;
	try
	{
	q.push(6);
	} catch(std::runtime_error& ex)
	{
		std::cout << "push got rekt2";
	}
	std::cout <<" Hello hello hello " <<std::endl;
	return 0;
}