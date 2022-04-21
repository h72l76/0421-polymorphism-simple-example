// 0421-polymorphism-simple-example.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

class Base {
public: 
	// use virtual in base class function to support polymorphism
	virtual void func() const { std::cout << "hello from base. \n"; }

	// define a virtual dtor 
	virtual ~Base() = default; 

};

class Derived : public Base {
public:
	// (optional) use override keyword
	void func() const override { std::cout << "hello from derived. \n"; }
};

// use pass-by-reference to support polymorphism
void helloFunc(const Base& b) { b.func();  }

int main()
{
	Base b; 
	Derived d; 

	// using pointers (dynamic binding): polymorphism
	std::cout << "polymorphism by using pointer: \n";
	Base* pb = &b; 
	pb->func(); 

	pb = &d; 
	pb->func(); 
	std::cout << std::endl;

	// using reference (dynamic binding): polymorphism
	std::cout << "polymorphism by using reference: \n";
	helloFunc(b); 
	helloFunc(d); 
	std::cout << std::endl;

	// using object (not reference or pointer): no polymorphism
	std::cout << "no polymorphism if only using object: \n";
	auto obj = b; 
	obj.func(); 
	obj = d; 
	obj.func(); 
}
