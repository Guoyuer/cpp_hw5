#include <iostream>
#include <string>
#include <utility>
#include <functional>
#include <memory>

using namespace std;

template<class T>
class Counter {
public:

    explicit Counter(T _func, bool _counted) : func(forward<T>(_func)), counted(_counted) {};

    template<class ...Args>
    auto operator()(Args ...args) {
        if (counted)
            count++;
        return func(args...);
    }

    int count = 0;
private:
    bool counted;
    T func;
};


double f(int a) {
    return 2 * a;
}

Counter cf(f, true);

int main() {
    cout << cf(3) << endl << cf(3) << endl;
    cout << cf.count;
}