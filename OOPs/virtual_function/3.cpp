#include<iostream>
#include<string>

class Animal{
    protected:
        std::string m_name;
        Animal(std::string name)
            :m_name{name}
        {
        }
    public:
        const std::string& getName() const { return m_name; }
        virtual std::string speak() const { return "???"; }
};

class Cat: public Animal
{
    public:
        Cat(std::string name)
            :Animal{name}
        {
        }

        virtual std::string speak() const { return "Meow"; }

};

class Dog: public Animal
{
    public:
        Dog(std::string name)
            :Animal{name}
        {
        }
        virtual std::string speak() const { return "woof"; }
};

void report(const Animal& animal)
{
    std::cout << animal.getName() << " says " << animal.speak() << '\n';
}

int main(){
    Cat fred{"Fred"};
    Cat misty{"Misty"};
    Cat zeke{ "Zeke" };
    
    Dog garbo{ "Garbo" };
    Dog pooky{ "Pooky" };
    Dog truffle{ "Truffle" };

    // Set up an array of pointers to animals, and set those pointers to our Cat and Dog objects
    Animal* animals[]{ &fred, &garbo, &misty, &pooky, &truffle, &zeke };
    
    for (const auto* animal : animals)
        std::cout << animal->getName() << " says " << animal->speak() << '\n';
    
    return 0;
}
// Return types of virtual functions
// Generally, the return type of a virtual function and its override must match.
/***
Output - 

Fred says Meow
Garbo says Woof
Misty says Meow
Pooky says Woof
Truffle says Woof
Zeke says Meow
*/