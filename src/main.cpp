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
	try
	{
		q.pop();
	} catch (std::runtime_error& ex)
	{
		std::cout << "pop got rekt";
	}
	std::cout <<" Hello hello hello " <<std::endl;
	return 0;
}