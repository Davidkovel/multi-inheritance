#include <iostream>
using namespace std;

class BaseFigure
{
public:
    virtual void displayInfo() = 0;
};

class Circle : virtual public BaseFigure
{
protected:
    double radius;
public:
    Circle()
    {
        radius = 0;
    }

    Circle(double radius)
    {
        this->radius = radius;
    }

    void displayInfo() override {
        cout << "Circle with radius: " << radius << endl;
    }
};

class Square : virtual public BaseFigure
{
protected:
    double sides;
public:
    Square()
    {
        sides = 0;
    }

    Square(double sides)
    {
        this->sides = sides;
    }

    void displayInfo() override {
        cout << "Square with sides: " << sides << endl;
    }
};

class SubClass : public Circle, public Square
{
public: 
    SubClass()
    {
        cout << "SubClass constructor" << endl;
    }
    SubClass(double value) : Circle(value), Square(value)
    {
        cout << "SubClass constructor with value" << endl;
    }

    SubClass(double value, double value2) : Circle(value), Square(value2)
    {
        cout << "SubClass constructor with 2 different values" << endl;
    }

    void displayInfo()
    {
        cout << "Circle inscribed in a Square class:" << endl;
        Circle::displayInfo();
        Square::displayInfo();
    }

    ~SubClass()
    {
        cout << "SubClass destructor" << endl;
    }
};

int main()
{
    SubClass* subclass = new SubClass(1.2, 3.6);
    subclass->displayInfo();

    return 0;
}

/*
SubClass constructor with 2 different values
Circle inscribed in a Square class:
Circle with radius: 1.2
Square with sides: 3.6

C:\Users\David\source\repos\Multi inheritance\x64\Debug\Multi inheritance.exe (процесс 10864) завершил работу с кодом 0 (0x0).
Нажмите любую клавишу, чтобы закрыть это окно:

*/