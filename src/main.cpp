#include <iostream>
#include <stdexcept>
#include "Queue.h"

void sample();

enum class Options
{
  EXIT = 0,
  EMPTY,
  FRONT,
  PUSH,
  POP,
  SHOW,
  SAMPLE
};

int main()
{
  bool next_invoke = true;	
  Queue queue;
  do
  {
    std::cout << 	"Please select a function: " <<
    std::endl <<	 "1.) EMPTY"	<<
    std::endl <<	 "2.) FRONT"	<<
    std::endl <<	 "3.) PUSH"		<<
    std::endl <<	 "4.) POP"		<<
    std::endl <<	 "5.) SHOW"		<<
    std::endl <<	 "6.) SAMPLE"	<<
	std::endl <<	 "7.) EXIT "	<<
	std::endl;

	unsigned int selected;
    std::cin >> selected;
    switch(static_cast<Options>(selected))
    {
      case Options::EMPTY:
        if(queue.empty())
          std::cout << "The queue is empty." << std::endl;
        else
          std::cout << "The queue is not empty." << std::endl;
        break;

      case Options::FRONT:
        try
        {
          std::cout << "The Front element of the queue is "
                    << queue.front() << std::endl;
        }
        catch(std::runtime_error & ex)
        {
          std::cout << "The queue is empty." << std::endl;
        }
        break;

      case Options::PUSH:
        std::cout << "Please add an element: ";
        int element;
        std::cin >> element;
        
        queue.push(element);
        std::cout << element << " is added into the queue." << std::endl;
        break;

      case Options::POP:
        try
        {
          queue.pop();
          std::cout << "The front elemet is poped from the queue." << std::endl;
        }
        catch(std::runtime_error & ex)
        {
          std::cout << "The queue is empty." << std::endl;
        }
        break;

      case Options::SHOW:
        std::cout << "The queue contains these elements: " << std::endl
                  << queue << std::endl;
        break;
      case Options::SAMPLE:
      	{
      		sample();
      		break;
      	}  
      case Options::EXIT:
      default:
        next_invoke = false;
        break;
    }
  } while(next_invoke);

	return 0;
}

void sample()
{
  Queue q;
  std::cout << "create q" << std::endl;
  std::cout << q;
  try
  {
  std::cout << "PUSH..."	 << std::endl;
  q.push(6);
  q.push(7);
  q.push(8);
  q.push(9);
  q.push(6);
  q.push(7);
  q.push(8);
  q.push(9);
  std::cout << q << std::endl;
  } catch(std::runtime_error& ex)
  {
    std::cout << "push got rekt";
  }
  try
  {
  	std::cout <<"POP..." << std::endl;
    q.pop();
    q.pop();
    std::cout << q << std::endl;
  } catch (std::runtime_error& ex)
  {
    std::cout << "pop got rekt";
  }

  std::cout << "CPYCTOR" << std::endl;
  Queue q2(q);
  std::cout << "q: " << q << std::endl;
  std::cout << "q2: " << q2 << std::endl;
  Queue *q4 = new Queue;
  q4->push(2);
  q4->push(3);
  q4->push(4);
  q4->push(5);
  q4->push(6);

  std::cout << "OPERATOR=()" << std::endl;
  std::cout << "q4: " << *q4 << std::endl;
  Queue *q3 = new Queue;
  q3 = q4;
  std::cout << "q3: " << *q3 << std::endl;

  delete q3;

  Queue q5;
  Queue q6;
  try
  {
  	std::cout << "OPERATOR+(...)" << std::endl;
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
}