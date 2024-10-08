#include <iostream>
using namespace std;

template <typename T1, typename T2>
class Base {
protected:
    T1 value1;
    T2 value2;

public:
    Base(T1 v1, T2 v2) : value1(v1), value2(v2) {}

    virtual void display() {
        cout << "Base values: " << value1 << ", " << value2 << endl;
    }

    virtual void delete_child(Base* ptr) {
        delete ptr;
        // delete this;
    }

    virtual ~Base() { cout << "Deleting Base class" << endl; }
};

template <typename T1, typename T2, typename T3, typename T4>
class Child : public Base<T1, T2> {
protected:
    T3 value3;
    T4 value4;
    virtual ~Child() override { cout << "Deleting Child class" << endl; }
public:
    Child(T1 v1, T2 v2, T3 v3, T4 v4) : Base<T1, T2>(v1, v2), value3(v3), value4(v4) {}

    virtual void display() override {
        Base<T1, T2>::display();
        cout << "Child values: " << value3 << ", " << value4 << endl;
    }

    virtual void delete_child(Child* ptr) {
        delete ptr;
        // delete this;
    }
};

template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
class Child2 : public Child<T1, T2, T3, T4> {
protected:
    T5 value5;
    T6 value6;
    virtual ~Child2() override { cout << "Deleting Child2 class" << endl; }
public:
    Child2(T1 v1, T2 v2, T3 v3, T4 v4, T5 v5, T6 v6) : Child<T1, T2, T3, T4>(v1, v2, v3, v4), value5(v5), value6(v6) {}

    virtual void display() override {
        Child<T1, T2, T3, T4>::display();
        cout << "Child2 values: " << value5 << ", " << value6 << endl;
    }

    virtual void delete_child(Child2* ptr) {
        delete ptr;
        // delete this;
    }
};

enum {max_objects = 100};
int main() {
    size_t count_b = 4;
    Base<int, double>* array_objects[max_objects] = { nullptr };

    array_objects[0] = new Child2<int, double, char, string, bool, float>(62, 6.5, 'W', "WIF", true, 1.4);
    array_objects[2] = new Child2<int, double, char, string, bool, float>(35, 2.5, 'E', "ETH", true, 6.3);
    array_objects[1] = new Child<int, double, char, string>(23, 8.5, 'B', "Python");
    array_objects[3] = new Child<int, double, char, string>(98, 34.8, 'C', "C++");

    for (size_t i = 0; i < count_b; i++) {
        array_objects[i]->display();
    }
    cout << endl;

    for (size_t i = 0; i < count_b; i++) {
        delete array_objects[i];
    }

    return 0;
}

/*
Base values: 62, 6.5
Child values: W, WIF
Child2 values: 1, 1.4
Base values: 23, 8.5
Child values: B, Python
Base values: 35, 2.5
Child values: E, ETH
Child2 values: 1, 6.3
Base values: 98, 34.8
Child values: C, C++

Deleting Child2 class
Deleting Child class
Deleting Base class
Deleting Child class
Deleting Base class
Deleting Child2 class
Deleting Child class
Deleting Base class
Deleting Child class
Deleting Base class

C:\Users\David\source\repos\Multi inheritance\x64\Debug\Multi inheritance.exe (процесс 12432) завершил работу с кодом 0 (0x0).
Нажмите любую клавишу, чтобы закрыть это окно:

*/