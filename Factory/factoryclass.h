#include "factory.h"

class vehicle_factory {

public:
    static unique_ptr<IVehicle> create_vehicle(Vehicle_type vt) {
        switch(vt) {
            case TWO_WHEELER:
                return make_unique<two_wheeler>();
            case THREE_WHEELER:
                return make_unique<three_wheeler>();
            case FOUR_WHEELER:
                return make_unique<four_wheeler>();
            default:
                return nullptr;
        }
    }
};