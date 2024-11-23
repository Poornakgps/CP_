#include <iostream>
#include <string>

class Shape
{
public:
    // Pure virtual destructor
    virtual ~Shape() = 0; 

    virtual void draw() const = 0; // Pure virtual function for drawing shapes
};

Shape::~Shape() 
{
    std::cout << "Shape destructor called\n"; // Custom base class cleanup (can be empty)
}

class Circle : public Shape
{
public:
    ~Circle() override
    {
        std::cout << "Circle destructor called\n"; // Derived class cleanup
    }

    void draw() const override
    {
        std::cout << "Drawing Circle\n";
    }
};

class Rectangle : public Shape
{
public:
    ~Rectangle() override
    {
        std::cout << "Rectangle destructor called\n"; // Derived class cleanup
    }

    void draw() const override
    {
        std::cout << "Drawing Rectangle\n";
    }
};

int main()
{
    // We can't instantiate Shape directly due to it being an abstract class with a pure virtual destructor.
    // Shape shape; // This would cause a compile-time error

    Shape* shape1 = new Circle(); // Polymorphic base class pointer
    Shape* shape2 = new Rectangle();

    shape1->draw();
    shape2->draw();

    delete shape1; // Calls Circle destructor
    delete shape2; // Calls Rectangle destructor

    return 0;
}
