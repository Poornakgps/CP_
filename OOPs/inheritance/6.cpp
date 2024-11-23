#include <iostream>
/*
Deleting functions in the derived class
We can also mark member functions as deleted in the derived class, which ensures they can’t be called at all through a derived object:
*/
class Base
{
private:
	int m_value {};

public:
	Base(int value)
		: m_value { value }
	{
	}

	int getValue() const { return m_value; }
};

class Derived : public Base
{
public:
	Derived(int value)
		: Base { value }
    {
	}


	int getValue() const = delete; // mark this function as inaccessible
};

int main()
{
	Derived derived { 7 };

	// The following won't work because getValue() has been deleted!
	// std::cout << derived.getValue();
    /*
    The Base version of getValue() is still accessible though. We can call Base::getValue() in one of two ways:
    */
   	// We can call the Base::getValue() function directly
	std::cout << derived.Base::getValue();
	// Or we can upcast Derived to a Base reference and getValue() will resolve to Base::getValue()
	std::cout << static_cast<Base&>(derived).getValue();
	return 0;
}