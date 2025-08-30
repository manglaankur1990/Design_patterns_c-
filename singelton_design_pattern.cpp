#include <iostream>
#include <memory>
#include <mutex>
#include <thread>

using namespace std;


class singelton {
    static unique_ptr<singelton> m_instance;
    static mutex mtx;
    static atomic<int> m_use_cnt;
    /* private constructor to manage creation of object connstruction */
    singelton() { cout << "created singelton instance" << endl;}
public:
    /* delete following fuctions to disable copy/move
     * copy constructor
     * copy assignment
     * move constructor
     * move assignment    
     */
    singelton(const singelton& obj) = delete;
    singelton& operator= (const singelton& obj) = delete;
    singelton(singelton &&obj) = delete;
    singelton& operator= (const singelton&& obj) = delete;
    static singelton& get_instance();
    void display() {
        cout << "m_use_cnt is : " << m_use_cnt.load() << endl;
    }
};
unique_ptr<singelton> singelton::m_instance = nullptr;
mutex singelton::mtx;
atomic<int> singelton::m_use_cnt(0);
singelton& singelton::get_instance() {
    if(nullptr == m_instance) {
        lock_guard<mutex> lock(mtx);
        if(nullptr == m_instance) {
            m_instance = unique_ptr<singelton>(new singelton());
        }
    }
    ++m_use_cnt;
    return *m_instance;
}


int main() {
    const int NUM_THREADS = 10000;
    vector<thread> threads;

    // spawn threads
    for (int i = 0; i < NUM_THREADS; i++) {
        threads.emplace_back([] {
            singelton& instance = singelton::get_instance();
            // optionally do something with instance
        });
    }

    // join all threads
    for (auto& t : threads) {
        t.join();
    }

    // check result
    singelton::get_instance().display();

    return 0;
}