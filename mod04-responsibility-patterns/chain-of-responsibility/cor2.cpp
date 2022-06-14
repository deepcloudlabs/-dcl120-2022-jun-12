#include <iostream>
#include <vector>

using namespace std;

template<class T>
class Component {
    T value;
    Component<T> *left;
    Component<T> *right;
public:
    Component(T value) {
        this->value = value;
        this->left = nullptr;
        this->right = nullptr;
    }

    Component(T value, Component<T> *left, Component<T> *right) {
        this->value = value;
        this->left = left;
        this->right = right;
    }

    virtual void add(T value) {
        if (value < this->value) {
            if (this->left == nullptr)
                this->left = new Component(value);
            else
                this->left->add(value);
        } else if (value > this->value) {
            if (this->right == nullptr)
                this->right = new Component(value);
            else
                this->right->add(value);
        }
    }

    virtual bool find(int value) {
        if (this->value == value) {
            cout << "Finally we have found the value " << value << endl;
            return true;
        }
        if (value < this->value) {
            if (left == nullptr) return false;
            return left->find(value);
        }
        if (right == nullptr) return false;
        return right->find(value);
    }
};

int main() {
    Component<int> numbers(15);
    numbers.add(8);
    numbers.add(42);
    numbers.add(4);
    numbers.add(16);
    numbers.add(23);
    numbers.find(23);
    numbers.find(55);
}
