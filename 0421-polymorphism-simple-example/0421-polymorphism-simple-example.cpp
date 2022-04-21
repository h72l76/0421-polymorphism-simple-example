// 0421-polymorphism-simple-example.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

class Base {
public: 
	void func() const { std::cout << "hello from base. \n"; }
};

class Derived : public Base {
public:
	void func() const { std::cout << "hello from derived. \n"; }
};

int main()
{
	Base b; 
	Derived d; 

	Base* pb = &b; 
	pb->func(); 
	pb = &d; 
	pb->func(); 
}
