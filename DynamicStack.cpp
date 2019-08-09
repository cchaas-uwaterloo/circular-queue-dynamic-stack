#include "DynamicStack.hpp"
#include <iostream>

using namespace std;

typedef DynamicStack::StackItem StackItem;  // for simplicity
const StackItem DynamicStack::EMPTY_STACK = -999;

DynamicStack::DynamicStack()
{
	init_capacity_= 16;
	capacity_ = 16;
	size_ = 0;
	items_ = new StackItem[init_capacity_];
}

DynamicStack::DynamicStack(unsigned int capacity)
{
	if (capacity == 0)
	{
		init_capacity_= 16;
		capacity_ = 16;
	}

	else
	{
		init_capacity_= capacity;
		capacity_ = capacity;
	}
	size_ = 0;
	items_ = new StackItem[init_capacity_];
}

DynamicStack::~DynamicStack()
{
	delete[] items_;
	items_ = nullptr;
}

bool DynamicStack::empty() const
{
	if (size_ == 0)
		return true;
	return false;
}

int DynamicStack::size() const
{
	return size_;
}

void DynamicStack::push(StackItem value)
{
	if (size_ == capacity_)
	{
		StackItem* temp = new StackItem[capacity_];
		for (unsigned int i=0; i<capacity_; i++)
		{
			temp[i] = items_[i];
		}
		delete[] items_;
		capacity_ *= 2;
		items_ = new StackItem[capacity_];
		for (unsigned int i=0; i<size_; i++)
		{
			items_[i] = temp[i];
		}
		delete[] temp;
		temp = nullptr;
	}

	items_[size_] = value;
	size_++;
}

StackItem DynamicStack::pop()
{
	if (this->empty())
		return EMPTY_STACK;

	StackItem toReturn = items_[size_-1];
	items_[size_-1] = 0; //not strictly necessary but its cleaner
	size_--;

	if (size_ <= capacity_/4 && capacity_/2 > init_capacity_)
	{
		StackItem* temp = new StackItem[capacity_];
		for (unsigned int i=0; i<size_; i++)
		{
			temp[i] = items_[i];
		}
		delete[] items_;
		capacity_ /= 2;
		items_ = new StackItem[capacity_];
		for (unsigned int i=0; i<size_; i++)
		{
			items_[i] = temp[i];
		}
		delete[] temp;
		temp = nullptr; //probably not necessary but better to make sure
	}

	return toReturn;
}

//array resizing not necessary here since it is always handled by the pop or push functions
StackItem DynamicStack::peek() const
{
	if (this->empty())
			return EMPTY_STACK;
	return items_ [size_-1];

}

void DynamicStack::print() const
{
	for (unsigned int i = size_-1; i>=0; i--)
	{
		cout << items_[i] << endl;
	}
}


