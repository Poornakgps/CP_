#include <iostream>
#include <string_view>

/*
Covariant return types
There is one special case in which a derived class virtual function override can have a different return 
type than the base class and still be considered a matching override. If the return type of a virtual 
function is a pointer or a reference to some class, override functions can return a pointer or a reference 
to a derived class. These are called covariant return types.
*/
class Base
{
public:
	// This version of getThis() returns a pointer to a Base class
	virtual Base* getThis() { std::cout << "called Base::getThis()\n"; return this; }
	void printType() { std::cout << "returned a Base\n"; }
};

class Derived : public Base
{
public:
	// Normally override functions have to return objects of the same type as the base function
	// However, because Derived is derived from Base, it's okay to return Derived* instead of Base*
	Derived* getThis() override { std::cout << "called Derived::getThis()\n";  return this; }
	void printType() { std::cout << "returned a Derived\n"; }
};

int main()
{
	Derived d{};
	Base* b{ &d };
	d.getThis()->printType(); // calls Derived::getThis(), returns a Derived*, calls Derived::printType
	b->getThis()->printType(); // calls Derived::getThis(), returns a Base*, calls Base::printType

	return 0;
}

/***
Output:
called Derived::getThis()
returned a Derived
called Derived::getThis()
returned a Base
***/

/*
We then call b->getThis().
Variable b is a Base pointer to a Derived object.
Base::getThis() is a virtual function, so this calls Derived::getThis().
Although Derived::getThis() returns a Derived*, because Base version of the function returns a Base*, the returned Derived* is upcast to a Base*.
Because Base::printType() is non-virtual, Base::printType() is called.
You only get a Derived* if you call getThis() with an object that is typed as a Derived object in the first place.
If printType() were virtual instead of non-virtual, the result of b->getThis() (an object of type Base*) would have undergone virtual function resolution, and Derived::printType() would have been called.
*/