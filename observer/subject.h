#include "observer.h"
#include <vector>

#pragma once

class ISubject {
protected:
    vector<weak_ptr<IObserver>> m_obs_list;
    string m_name;
public: 
    ISubject(string name): m_name(name) {}
    virtual void add_observer(weak_ptr<IObserver> obs) = 0;
    virtual void remove_observer(weak_ptr<IObserver> obs) = 0;
    virtual void notify_observer(float value) = 0;
    string get_name() { return m_name;}
    virtual ~ISubject() {}
};

class Subject: public ISubject {
public:
    Subject(string name): ISubject(name) { cout << "created concrete subject name is :" << get_name() << endl;}
    virtual void add_observer(weak_ptr<IObserver> obs) override;
    virtual void remove_observer(weak_ptr<IObserver> obs) override;
    virtual void notify_observer(float value) override; 
    virtual ~Subject() { cout << "destroyed concrete subject name is :" << get_name() << endl;}
};

void Subject::add_observer(weak_ptr<IObserver> obs) {
    cout << "register observer: " << obs.lock()->get_name() << " with subject: " << get_name() << endl;
    m_obs_list.push_back(obs);
}

void Subject::remove_observer(weak_ptr<IObserver> obs) {
    m_obs_list.erase(remove_if(m_obs_list.begin(), m_obs_list.end(), [&](weak_ptr<IObserver> &o) {
        bool is_present = false;
        auto it_o = o.lock();
        auto it_obs = obs.lock();
        if(it_obs && it_obs == it_o) {
            cout << "deregister observer: " << it_obs->get_name() << " with subject: " << get_name() << endl;
            is_present = true;
        }
        return is_present;
    }), m_obs_list.end() );
}

void Subject::notify_observer(float value) {
    for(auto it : m_obs_list) {
        if(auto obs = it.lock()) {
            obs->update(value);
        }
    }
}