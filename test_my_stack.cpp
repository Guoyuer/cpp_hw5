#include <iostream>
#include <my_stack.h>
#include <thread>
#include <vector>
#include <chrono>

using namespace std;

template<typename T>
void thread_push(int i, MPCS51044::my_stack<T> &stk) {
    for (int k = i; k < i + 100; k++)
        stk.push(k);
}

template<typename T>
void thread_pop(MPCS51044::my_stack<T> &stk) {
    for (int i = 0; i < 100; i++)
        cout << stk.pop() << " ";
}

int main() {
    MPCS51044::my_stack<int> stk{-1, -2, -3, -4};//initializer_list. from stack bottom to top
    auto start = chrono::high_resolution_clock::now();
    vector<thread> push_threads;
    vector<thread> pop_threads;
    for (int i = 1; i < 1000; i += 100)
        push_threads.push_back(thread(thread_push<int>, i, ref(stk)));
    for (auto &thr: push_threads)
        thr.join();
    while (!stk.empty()) {
        cout << stk.pop() << " ";
    }

    /*uncomment following lines to test concurrent popping*/

//    for (int i = 1; i < 1000; i += 100)
//        pop_threads.push_back(thread(thread_pop<int>, ref(stk)));
//    for (auto &thr: pop_threads)
//        thr.join();
    return 0;
}