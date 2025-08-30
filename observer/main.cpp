#include "subject.h"

int main() {
    unique_ptr<ISubject> subPtr = make_unique<Subject>("sub1");
    shared_ptr<IObserver> obs1 = make_unique<Observer>("obs1");
    shared_ptr<IObserver> obs2 = make_unique<Observer>("obs2");
    shared_ptr<IObserver> obs3 = make_unique<Observer>("obs3");
    shared_ptr<IObserver> obs4 = make_unique<Observer>("obs4");
    shared_ptr<IObserver> obs5 = make_unique<Observer>("obs5");
    subPtr->add_observer(obs1);
    subPtr->add_observer(obs2);
    subPtr->add_observer(obs3);
    subPtr->add_observer(obs4);
    subPtr->add_observer(obs5);
    subPtr->notify_observer(10.0f);
    subPtr->remove_observer(obs2);
    subPtr->notify_observer(20.0f);

    return 0;
}