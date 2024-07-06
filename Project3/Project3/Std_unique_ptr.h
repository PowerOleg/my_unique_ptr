#include <iostream>
#pragma once

template<class T>
class Std_unique_ptr
{
public:
	Std_unique_ptr(const Std_unique_ptr&) = delete;
	Std_unique_ptr(T* a_ptr) : ptr{ a_ptr } {}
	~Std_unique_ptr()
	{
		std::cout << "destructor called\n";
		delete ptr;
		ptr = nullptr;
	}

	T operator*()
	{
		return *ptr;
	}


	Std_unique_ptr& operator=(const Std_unique_ptr&) = delete;
	T* release()
	{
		T* ptr_new = this->ptr;
		this->ptr = nullptr;
		return ptr_new;
	}
	private:
		T* ptr;
};

