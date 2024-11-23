#include <iostream>

class Vehicle {
public:
    Vehicle() { std::cout << "Vehicle created\n"; }
    void startEngine() { std::cout << "Engine started\n"; }
    void stopEngine() { std::cout << "Engine stopped\n"; }
};

class Car : virtual public Vehicle {
public:
    Car() { std::cout << "Car created\n"; }
    void openSunroof() { std::cout << "Opening sunroof\n"; }
};

class Truck : virtual public Vehicle {
public:
    Truck() { std::cout << "Truck created\n"; }
    void loadCargo() { std::cout << "Loading cargo\n"; }
};

class Motorcycle : virtual public Vehicle {
public:
    Motorcycle() { std::cout << "Motorcycle created\n"; }
    void kickstandStatus() { std::cout << "Checking kickstand\n"; }
};

// HybridVehicle now shares a single instance of Vehicle
class HybridVehicle : public Car, public Truck {
public:
    HybridVehicle() { std::cout << "HybridVehicle created\n"; }
};

int main() {
    HybridVehicle hv;
    hv.startEngine();  // No ambiguity! One instance of Vehicle, from virtual inheritance
    return 0;
}
