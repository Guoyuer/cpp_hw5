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

void f1(int &a) {
    a *= 2;
}

Counter cf(f, true);
Counter cf1(f1, true);

int main() {
    int x = 1;
    cout << cf(3) << endl << cf(3) << endl;
    cout << cf.count << endl;
    cf1(x);//x's value won't change. don't know how
    cout << x << endl;
}