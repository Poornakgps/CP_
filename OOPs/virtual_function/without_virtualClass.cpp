#include <iostream>

class Vehicle {
public:
    Vehicle() { std::cout << "Vehicle created\n"; }
    void startEngine() { std::cout << "Engine started\n"; }
    void stopEngine() { std::cout << "Engine stopped\n"; }
};

class Car : public Vehicle {
public:
    Car() { std::cout << "Car created\n"; }
    void openSunroof() { std::cout << "Opening sunroof\n"; }
};

class Truck : public Vehicle {
public:
    Truck() { std::cout << "Truck created\n"; }
    void loadCargo() { std::cout << "Loading cargo\n"; }
};

class Motorcycle : public Vehicle {
public:
    Motorcycle() { std::cout << "Motorcycle created\n"; }
    void kickstandStatus() { std::cout << "Checking kickstand\n"; }
};

// Diamond problem in action
class HybridVehicle : public Car, public Truck {
public:
    HybridVehicle() { std::cout << "HybridVehicle created\n"; }
};

int main() {
    HybridVehicle hv;
    hv.startEngine();  // Ambiguous! Which startEngine() should be called?
    return 0;
}
