#include <iostream>
#include <string>
#include <vector>

class Base
{
    protected:
    int m_value{};

public:
    Base(int value)
        : m_value{ value }
    {
    }

    virtual ~Base() = default;

    virtual std::string getName() const { return "Base"; }
    int getValue() const { return m_value; }
};

class Derived: public Base
{
public:
    Derived(int value)
        : Base{ value }
    {
    }

   std::string getName() const override { return "Derived"; }
};

int main()
{
    Derived derived{ 5 };
    Base base{ derived }; // what happens here?
    std::cout << "base is a " << base.getName() << " and has value " << base.getValue() << '\n';
	std::vector<Base> v{};
	v.push_back(Base{ 5 });    // add a Base object to our vector
	v.push_back(Derived{ 6 }); // add a Derived object to our vector

        // Print out all of the elements in our vector
	for (const auto& element : v)
		std::cout << "I am a " << element.getName() << " with value " << element.getValue() << '\n';
    
    /*
    	std::vector<Base*> v{};

	Base b{ 5 }; // b and d can't be anonymous objects
	Derived d{ 6 };

	v.push_back(&b); // add a Base object to our vector
	v.push_back(&d); // add a Derived object to our vector

	// Print out all of the elements in our vector
    for (const auto* element : v)
		std::cout << "I am a " << element->getName() << " with value " << element->getValue() << '\n';
    */
    return 0;
}

// Output - base is a Base and has value 5

/*
What happened here?

derived has a Base part and a Derived part
When we assign a Derived object to a Base object, only the Base portion of the Derived object is copied, the Derived is not.
That Derived portion has effectively been “sliced off”.
This is called object slicing
Because base was and still is just a Base, Base’s virtual pointer still points to Base. Thus, base.getName() resolves to Base::getName().
*/