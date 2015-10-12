#include <iostream>
#include <stdexcept>
#include "Queue.h"

int main()
{
	Queue q;
	std::cout << "create q" << std::endl;
	try
	{
	q.push(6);
	q.push(7);
	q.push(8);
	q.push(9);
	std::cout << q << std::endl;
	} catch(std::runtime_error& ex)
	{
		std::cout << "push got rekt2";
	}
	/*try
	{
		//q.pop();
		std::cout << q << std::endl;
	} catch (std::runtime_error& ex)
	{
		std::cout << "pop got rekt";
	}*/
	std::cout <<" Hello hello hello " <<std::endl;
	return 0;
}