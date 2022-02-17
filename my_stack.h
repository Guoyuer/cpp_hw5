#include <memory>
#include<shared_mutex>

namespace MPCS51044 {
    template<typename T>
    class Node {
    public:
        T data;
        std::unique_ptr<Node<T>> next;

        explicit Node(T data) : data{std::move(data)}, next{nullptr} {};

    };

    template<typename T>
    class my_stack {
    private:
        std::unique_ptr<Node<T>> top;
        std::shared_mutex mtx;

    public:
        // #top --> n2 --> n3 --> n4
        void push(T val) {
            auto newNode = std::make_unique<Node<T>>(val);
            std::unique_lock lock(mtx);
            newNode->next = std::move(top);
            newNode->data = val;
            top = std::move(newNode);
        }

        T pop() {
            std::unique_lock lock(mtx);
            if (!top) {
                throw std::runtime_error("POPPING on empty my_stack");
            }
            T data = top->data;
            top = std::move(top->next);
            return data;
        }

        bool empty() {
            std::unique_lock lock(mtx);
            return top == nullptr;
        }

        my_stack() : top{nullptr} {}

        my_stack(std::initializer_list<T> list) {
            for (auto data: list) {
                push(data);
            }
        }
    };

}




