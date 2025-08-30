#include <iostream>
using namespace std;

class IObserver {
    string m_name;
    float m_value;
public:
    IObserver(string name): m_name(name) {}
    string get_name() {return m_name;}
    void set_value(float value) { m_value = value;}
    float get_value() { return m_value; }
    virtual void update(float value) = 0;
    virtual ~IObserver() {}
};

class Observer: public IObserver {

public:
    Observer(string name): IObserver(name) {cout << "created concrete observer name is :" << get_name() << endl;} 
    void update(float value) override;
    virtual ~Observer() {cout << "destroyed concrete observer name is :" << get_name() << endl;}  
};

void Observer::update(float value) {
    cout << "update observer: " << get_name() << " with value : " << value << endl;
}