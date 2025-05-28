#include <iostream>
#include <string>

class Car {
public:
	Car();
	Car(std::string brand, std::string model, int year);
	std::string	brand;
	std::string	model;
	int			year;
};

Car::Car(std::string brand, std::string model, int year) {
	this->brand = brand;
	this->model = model;
	this->year = year;
	return ;
}

Car::Car(void) {
	std::cout << "Wadap!" << std::endl;
	brand = "Default car";
	model = "Default model";
	year = 0;
	return ;
}

int main() {
	Car car1;
	std::cout << car1.brand << " " << car1.model << " " << car1.year << std::endl;
	return 0;
}
