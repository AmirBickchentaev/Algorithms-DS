// Operators and Operator Overloading.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
using namespace std;


struct Vector 
{
	double x, y;

	Vector(double x, double y) :x(x), y(y) {}
	Vector Add(const Vector& other) const 
	{
		return Vector(x + other.x, y + other.y);
	}
	Vector Multiply(const Vector& other) const
	{
		return Vector(x * other.x, y * other.y);
	}


	Vector operator+(const Vector&other) const 
	{
		//implementaion using subFuction Add above
		
		//return Add(other);

		return Vector(x + other.x, y + other.y);

	}

	Vector operator*(const Vector&other) const 
	{
		//implementation using subFunction Multiply above
		//return Multiply(other); 

		return Vector(x* other.x, y*other.y);
	}


	bool operator ==(const Vector&other) const 
	{
		return x == other.x && y == other.y;
	}

	bool operator!=(const Vector&other) const 
	{
		return !operator ==(other);
		//`return !(*this == other);
	}
};


ostream& operator<<(ostream& stream, const Vector&other) 
{
	stream << other.x << " , " << other.y;
	return stream;
}


int main()
{
	Vector position(4.0, 5.0);
	Vector speed(3.0, 1.0);
	Vector result = position;


	cout << position;

}
