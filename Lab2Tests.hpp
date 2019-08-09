#ifndef LAB2_TESTS_HPP
#define LAB2_TESTS_HPP

#define ASSERT_TRUE(T) if (!(T)) return false;
#define ASSERT_FALSE(T) if ((T)) return false;

#include "DynamicStack.hpp"
#include "CircularQueue.hpp"

class DynamicStackTest
{
public:
    bool test1()
    {
      unsigned int size = 24;

      DynamicStack default_size_stack;
      ASSERT_TRUE(default_size_stack.empty() == true)
      ASSERT_TRUE(default_size_stack.size() == 0)

      DynamicStack stack(size);
      ASSERT_TRUE(stack.empty() == true)
      ASSERT_TRUE(stack.size() == 0)
      return true;
    }

    bool test2()
    {
      DynamicStack stack;
      stack.push(10);
      ASSERT_TRUE(stack.empty() == false)
      ASSERT_TRUE(stack.size() == 1)
      ASSERT_TRUE(stack.pop() == 10);
      ASSERT_TRUE(stack.empty() == true)
      ASSERT_TRUE(stack.size() == 0)
      return true;
    }

    bool test3()
    {
      DynamicStack stack(24);
      stack.push(10);
      stack.push(20);
      ASSERT_TRUE(stack.peek() == 20)
      ASSERT_TRUE(stack.pop() == 20)
      ASSERT_TRUE(stack.pop() == 10)
      ASSERT_TRUE(stack.pop() == DynamicStack::EMPTY_STACK)
      ASSERT_TRUE(stack.peek() == DynamicStack::EMPTY_STACK)
      return true;
    }

    bool test4()
    {
    	DynamicStack stack(0);
    	ASSERT_TRUE(stack.capacity_ == 16);
    	for (unsigned int i=1; i<=32; i++)
    	{
    		stack.push(i);
    		ASSERT_TRUE(i == stack.peek());
    	}

    	ASSERT_TRUE(stack.capacity_ == 32);
		return true;
    }

    bool test5()
    {
        DynamicStack stack;
        ASSERT_TRUE(stack.capacity_ == 16);
        for (unsigned int i=1; i<=80; i++)
        {
        	stack.push(i);
       	}
       	ASSERT_TRUE(stack.capacity_ == 128);
        for (unsigned int i=1; i<=61; i++)
        {
        	int j = stack.pop();
        }

        ASSERT_TRUE(stack.capacity_ == 64);
    	return true;
    }

    bool test6()
    {
    	DynamicStack stack;
    	for (unsigned int i=0; i<10000; i++)
    	{
    		stack.push(i);
    	}
    	for (unsigned int i=0; i<10000; i++)
    	{
    		ASSERT_TRUE(stack.pop()==10000-i-1);
    	}

    	return true;
    }

};

class CircularQueueTest
{
public:
    bool test1()
    {
      CircularQueue queue;
      ASSERT_TRUE(queue.empty() == true)
      ASSERT_TRUE(queue.full() == false)
      ASSERT_TRUE(queue.size() == 0)
      ASSERT_TRUE(queue.size_ == 0)
      ASSERT_TRUE(queue.capacity_ == 16)
      return true;
    }

    bool test2()
    {
      CircularQueue queue;
      ASSERT_TRUE(queue.enqueue(10) == true)
      ASSERT_TRUE(queue.empty() == false)
      ASSERT_TRUE(queue.full() == false)
      ASSERT_TRUE(queue.size_ == 1)
      ASSERT_TRUE(queue.head_ == 0)
      ASSERT_TRUE((queue.tail_ == 0) || (queue.tail_ == 1))
      ASSERT_TRUE(queue.dequeue() == 10);
      ASSERT_TRUE(queue.empty() == true)
      ASSERT_TRUE(queue.size_ == 0)
      return true;
    }

    bool test3()
    {
      CircularQueue queue;
      ASSERT_TRUE(queue.enqueue(10) == true)
      ASSERT_TRUE(queue.enqueue(20) == true)
      ASSERT_TRUE(queue.empty() == false)
      ASSERT_TRUE(queue.full() == false)
      ASSERT_TRUE(queue.size_ == 2)
      ASSERT_TRUE(queue.head_ == 0)
      ASSERT_TRUE((queue.tail_ == 1) || ((queue.tail_ == 2)))
      ASSERT_TRUE(queue.peek() == 10);
      ASSERT_TRUE(queue.dequeue() == 10);
      ASSERT_TRUE(queue.peek() == 20);
      ASSERT_TRUE(queue.dequeue() == 20);
      ASSERT_TRUE(queue.peek() == CircularQueue::EMPTY_QUEUE);
      ASSERT_TRUE(queue.dequeue() == CircularQueue::EMPTY_QUEUE);
      ASSERT_TRUE(queue.empty() == true)
      ASSERT_TRUE(queue.size_ == 0)
      ASSERT_TRUE(queue.head_ == 2)
      ASSERT_TRUE((queue.tail_ == 1) || (queue.tail_ == 2))
      return true;
    }

    bool test4()
    {
    	CircularQueue queue(32);
        for (unsigned int i=0; i<32; i++)
        {
        	ASSERT_TRUE(queue.enqueue(i)==true);
        }
        ASSERT_TRUE(queue.enqueue(100) == false);
        ASSERT_TRUE(queue.peek() == 0);
        ASSERT_TRUE(queue.head_ == 0);
        ASSERT_TRUE(queue.tail_ == 0);
        return true;
    }

    bool test5()
    {
    	CircularQueue queue(32);
    	for (unsigned int i=0; i<32; i++)
    	{
    		ASSERT_TRUE(queue.enqueue(i)==true);
    	}
    	for (unsigned int i=0; i<10; i++)
    	{
    		ASSERT_TRUE(queue.peek() == i);
    		ASSERT_TRUE(queue.dequeue() == i);
    		ASSERT_TRUE(queue.enqueue(i*2) == true);
    		ASSERT_TRUE(queue.peek() == i+1);
    	}
    	return true;
    }

};


#endif
