#include <iostream>
#include <stdexcept>
#include "Queue.h"

int main()
{
	Queue q;
	std::cout << "create q" << std::endl;
	std::cout << q;
	try
	{
	q.push(6);
	q.push(7);
	q.push(8);
	q.push(9);
	q.push(6);
	q.push(7);
	q.push(8);
	q.push(9);
	std::cout << q << std::endl;
	std::cout << q << std::endl;
	std::cout << q << std::endl;
	} catch(std::runtime_error& ex)
	{
		std::cout << "push got rekt";
	}
	try
	{
		q.pop();
		q.pop();
		std::cout << q << std::endl;
	} catch (std::runtime_error& ex)
	{
		std::cout << "pop got rekt";
	}
	std::cout <<" Hello hello hello " <<std::endl;

	Queue q2(q);
	std::cout << "q2: " << q2 << std::endl;
	Queue *q4 = new Queue;
	q4->push(2);
	q4->push(3);
	q4->push(4);
	q4->push(5);
	q4->push(6);
	std::cout << "q4: " << *q4 << std::endl;
	Queue *q3 = new Queue;
	q3 = q4;
	std::cout << "q3: " << *q3 << std::endl;

	delete q3;

	Queue q5;
	Queue q6;
	try
	{
		q5.push(11);
		q5.push(22);
		q5.push(33);
		q6.push(44);
		q6.push(55);
		q6.push(66);
		std::cout << "q5: " << q5 << std::endl;
		std::cout << "q6: " << q6 << std::endl;
		q5 + q6;
		std::cout << "q5 + q6: " << q5 << std::endl;
	}
	catch(std::runtime_error& ex)
	{
		std::cout << "push got rekt again" << std::endl;
	}

	return 0;
}