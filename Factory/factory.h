#include <iostream>

using namespace std;

enum Vehicle_type {
    TWO_WHEELER,
    THREE_WHEELER,
    FOUR_WHEELER,
    VT_UNKNOWN
};

class IVehicle {

public:
    IVehicle() {}
    virtual void print_vehicle() = 0;
    virtual ~IVehicle() {}
};

class two_wheeler : public IVehicle {

public:
    two_wheeler() = default;
    void print_vehicle() override {
        cout << "Two Wheeler" << endl;
    }
    virtual ~two_wheeler() {}
};

class three_wheeler : public IVehicle {

public:
    three_wheeler() = default;
    void print_vehicle() override {
        cout << "Three Wheeler" << endl;
    }
    virtual ~three_wheeler() {}
};

class four_wheeler : public IVehicle {

public:
    four_wheeler() = default;
    void print_vehicle() override {
        cout << "Four Wheeler" << endl;
    }
    virtual ~four_wheeler() {}
};