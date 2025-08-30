#include "factoryclass.h"

int main() {
    int choice = 0;
    while(true) {
        Vehicle_type vt;
        cout << endl;
        cout << "Please enter type of vehicle you wish to create" << endl;
        cout << "1. 2 wheeler" << endl;
        cout << "2. 3 wheeler" << endl;
        cout << "3. 4 wheeler" << endl;
        cin >> choice;
        cout << endl;
        switch(choice) {
            case 1:
                vt = TWO_WHEELER;
                break;
            case 2:
                vt = THREE_WHEELER;
                break;
            case 3:
                vt = FOUR_WHEELER;
                break;
            default:
                cout << "invalid choice" << endl;
                vt = VT_UNKNOWN;
                break;
        }
        unique_ptr<IVehicle> vptr = vehicle_factory::create_vehicle(vt);
        if(vptr)
            vptr->print_vehicle();
        vptr.reset();

    }

    return 0;
}