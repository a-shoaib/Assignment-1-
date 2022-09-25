#include <iostream>
#include <queue>
using namespace std;

class Car {

private:
	string Car_Brand;
	string Car_Type;
	string Car_Plate;
	int Speed;
	int Year_Model;

public:
	Car() {
		cout << "---" << endl;
	}
	Car(string brand, int Max_Speed, int Model) {
		Car_Brand = brand;
		Speed = Max_Speed;
		Year_Model = Model;
	}
	void set_Brand(string brand) {
		Car_Brand = brand;
	}
	string get_Brand() {
		return Car_Brand;
	}

	void set_Type(string type) {
		while (type != "bus" && type != "private" && type != "motorcycle" && type != "truck") {
			cout << "Incorrect Vehicle type, please enter one of the following: \n bus \n private\n motorcycle \n truck: \n";
			cin >> type;
		}
		Car_Type = type;
	}
	string get_Type() {
		return Car_Type;
	}

	void set_Plate(string plate) {
		while (plate.length() != 6) {
			cout << "Invalid plate number. Please enter plate number: ";
			cin >> plate;
		}
		Car_Plate = plate;
	}
	string get_Plate() {
		return Car_Plate;
	}

	void set_Speed(int speed) {
		Speed = speed;
	}
	int get_Speed() {
		return Speed;
	}

	void set_Model(int model) {
		Year_Model = model;
	}
	int get_Model() {
		return Year_Model;
	}


};

class Road {

private:
	char Road_Type;
	int Speed_LimitA, Speed_LimitB, Speed_LimitC;
	int countA = 0, countB = 0, countC = 0;

public:
	Road();
	Road(char type, int limit) {
		while (type != 'A' && type != 'B' && type != 'C') {
			cout << "Invalid Road Type. Enter A, B or C: ";
			cin >> type;
		}
		Road_Type = type;

		if (type == 'A')
			Speed_LimitA = limit;
		else if (type == 'B')
			Speed_LimitB = limit;
		else
			Speed_LimitC = limit;
	}
	void set_Type(char type) {
		while (type != 'A' && type != 'B' && type != 'C') {
			cout << "Invalid input. Enter A, B or C: ";
			cin >> type;
		}
		Road_Type = type;
	}
	char get_Type() {
		return Road_Type;
	}

	void set_LimitA(int limita) {
		Speed_LimitA = limita;
	}

	void set_LimitB(int limitb) {
		Speed_LimitB = limitb;
	}

	void set_LimitC(int limitc) {
		Speed_LimitC = limitc;
	}

	int get_LimitA() {
		return Speed_LimitA;
	}

	int get_LimitB() {
		return Speed_LimitB;
	}

	int get_LimitC() {
		return Speed_LimitC;
	}

	void set_countA(int c) {
		countA = c;
	}
	int get_countA() {
		return countA;
	}

	void set_countB(int c) {
		countB = c;
	}
	int get_countB() {
		return countB;
	}

	void set_countC(int c) {
		countC = c;
	}
	int get_countC() {
		return countC;
	}


	bool Radar(int speed, char type) {

		if (type == 'A') {
			if (speed > Speed_LimitA)
				return true;
		}

		else if (type == 'B') {
			if (speed > Speed_LimitB)
				return true;
		}

		else if (type == 'C') {
			if (speed > Speed_LimitC)
				return true;
		}

		return false;
	}

	void allow(string type) {

		if (type == "private") {
			cout << "Allowed in Road A and Road B" << endl;
			countA++;
			return;
		}
		if (type == "motorcycle") {
			cout << "Allowed in Road A and Road B" << endl;
			return;
		}

		if (type == "bus") {
			cout << "Allowed in Road B" << endl;
			countB++;
			return;
		}

		if (type == "truck") {
			cout << "Allowed in Road C" << endl;
			countC++;
			return;
		}

	}

	int age(int year) {

		return (2022 - year);
	}


};

int main()
{
	queue<Car> Cars;
	int numberOfCars;
	Car car1("Toyota", 90, 2016), car2("BMW", 160, 2020), car3("Mitsubishi", 80, 2014), car4("Yamaha", 120, 2019), car5("Volkswagen", 100, 2009);
	Car currentCar;
	Road road1('A', 120), road2('B', 60), road3('C', 100);
	char currentRoadType;
	int topRoad;
	int efficiencyA, efficiencyB, efficiencyC;

	car1.set_Type("truck");
	car2.set_Type("private");
	car3.set_Type("bus");
	car4.set_Type("motorcycle");
	car5.set_Type("private");

	car1.set_Plate("ABC123");
	car2.set_Plate("JK1234");
	car3.set_Plate("QT2345");
	car4.set_Plate("ALO234");
	car5.set_Plate("MSD487");

	Cars.push(car1);
	Cars.push(car2);
	Cars.push(car3);
	Cars.push(car4);
	Cars.push(car5);

	numberOfCars = 5;

	for (int i = 0; i < numberOfCars; i++) {
		currentCar = Cars.front();
		Cars.pop();

		cout << "Which road is Car " << i + 1 << " taking? ";
		cin >> currentRoadType;
		while (currentRoadType != 'A' && currentRoadType != 'B' && currentRoadType != 'C') {
			cout << "Invalid Road. Please choose A, B or C";
			cin >> currentRoadType;
		}

		if (currentRoadType == 'A') {
			if (road1.Radar(currentCar.get_Speed(), road1.get_Type())) {
				cout << "This car will be fined" << endl;
				cout << "Plate Number: " << currentCar.get_Plate() << endl;
				cout << "Car type: " << currentCar.get_Type() << endl;
				cout << "Speed: " << currentCar.get_Speed() << endl;
				cout << "Model: " << currentCar.get_Model() << endl;
				cout << "Brand: " << currentCar.get_Brand() << endl;

			}
			road1.allow(currentCar.get_Type());
			cout << "This car is " << road1.age(currentCar.get_Model()) << " years old" << endl;

		}
		else if (currentRoadType == 'B') {
			if (road2.Radar(currentCar.get_Speed(), road2.get_Type())) {
				cout << "This car will be fined" << endl;
				cout << "Plate Number: " << currentCar.get_Plate() << endl;
				cout << "Car type: " << currentCar.get_Type() << endl;
				cout << "Speed: " << currentCar.get_Speed() << endl;
				cout << "Model: " << currentCar.get_Model() << endl;
				cout << "Brand: " << currentCar.get_Brand() << endl;

			}
			road2.allow(currentCar.get_Type());
			cout << "This car is " << road2.age(currentCar.get_Model()) << " years old" << endl;

		}

		else {
			if (road3.Radar(currentCar.get_Speed(), road3.get_Type())) {
				cout << "This car will be fined" << endl;
				cout << "Plate Number: " << currentCar.get_Plate() << endl;
				cout << "Car type: " << currentCar.get_Type() << endl;
				cout << "Speed: " << currentCar.get_Speed() << endl;
				cout << "Model: " << currentCar.get_Model() << endl;
				cout << "Brand: " << currentCar.get_Brand() << endl;

			}
			road3.allow(currentCar.get_Type());
			cout << "This car is " << road3.age(currentCar.get_Model()) << " years old" << endl;

		}



	}

	cout << "The number of cars in road A is " << road1.get_countA() << endl;
	cout << "The number of cars in road B is " << road2.get_countB() << endl;
	cout << "The number of cars in road C is " << road3.get_countC() << endl;

	if (road1.get_countA() > road1.get_countB()) {
		if (road1.get_countA() > road1.get_countC())
			topRoad = road1.get_countA();
	}
	else if (road1.get_countB() > road1.get_countC())
		topRoad = road1.get_countB();
	else topRoad = road1.get_countC();

	efficiencyA = (road1.get_countA() / topRoad) * 100;
	cout << "The efficiency of road A is: " << efficiencyA << "%" << endl;

	efficiencyB = (road2.get_countB() / topRoad) * 100;
	cout << "The efficiency of road B is: " << efficiencyB << "%" << endl;

	efficiencyC = (road2.get_countC() / topRoad) * 100;
	cout << "The efficiency of road C is: " << efficiencyC << "%" << endl;


	return 0;
}




