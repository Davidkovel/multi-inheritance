#include <iostream>
using namespace std;

class Base
{
public:
	virtual void displayInfo() = 0;
	virtual ~Base()
	{
		cout << "Base class deleting" << endl;
	}
};

class Wheels : virtual public Base
{
protected:
	int number_of_wheels;
public:
	Wheels() {
		number_of_wheels = 0;
	}
	
	Wheels(int number_of_wheels)
	{
		this->number_of_wheels = number_of_wheels;
	}

	void displayInfo() override
	{
		cout << "Quantity of wheels" << number_of_wheels << endl;
	}

	~Wheels() override
	{
		cout << "Wheels class deleting" << endl;
	}
	
};

class Engine : virtual public Base
{
protected:
	int horse_power;
public:
	Engine() {
		horse_power = 0;
	}

	Engine(int horse_power)
	{
		this->horse_power = horse_power;
	}

	void displayInfo() override
	{
		cout << "Quantity of horse power: " << horse_power << endl;
	}

	~Engine() override
	{
		cout << "Engine class deleting" << endl;
	}

};

class Doors : virtual public Base
{
protected:
	int number_of_doors;
public:
	Doors() {
		number_of_doors = 0;
	}

	Doors(int number_of_doors)
	{
		this->number_of_doors = number_of_doors;
	}

	void displayInfo() override
	{
		cout << "Quantity of doors: " << number_of_doors << endl;
	}

	~Doors() override
	{
		cout << "Doors class deleting" << endl;
	}
};

class Car : public Doors, public Engine, public Wheels
{
public:
	Car() : Doors(), Engine(), Wheels()
	{

	};
	Car(int num_doors, int engine_power, int num_wheels) : Doors(num_doors), Engine(engine_power), Wheels(num_wheels)
	{
		cout << "Car created with params" << endl;
	};

	void displayInfo() override
	{
		Wheels::displayInfo();
		Engine::displayInfo();
		Doors::displayInfo();
	}

	~Car() override
	{
		cout << "Car class deleting" << endl;
	}


public:

};
int main()
{
	Car* car = new Car(4, 560, 4);
	car->displayInfo();

	cout << endl;

	delete car;
	return 0;
}

/*
Car created with params
Quantity of wheels4
Quantity of horse power: 560
Quantity of doors: 4

Car class deleting
Wheels class deleting
Engine class deleting
Doors class deleting
Base class deleting

C:\Users\David\source\repos\Multi inheritance\x64\Debug\Multi inheritance.exe (процесс 5212) завершил работу с кодом 0 (0x0).
Нажмите любую клавишу, чтобы закрыть это окно:
*/