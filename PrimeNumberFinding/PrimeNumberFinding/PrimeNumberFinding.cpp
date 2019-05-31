// different types of algorithms for prime number finding

#include "pch.h"
#include <iostream>
using namespace std;


//O(log2(n))) complexity
void isPrime(int value)
{
	for (int i = 2; i <= sqrt(value)+1; i++) 
	{
		if (value % i == 0)
		{
			cout << "We haven't find'em";
			return;
		}
	}
	cout << "this is the prime number";
	
}

//kolhoz ebuchiy
void printAllPrime(int upperLimit) 
{
	int iterationAmount = 0;
	for (int value = 3; value < upperLimit; value++) {
		iterationAmount++;
		bool flag = false;
		for (int i = 2; i <= sqrt(value) + 1; i++)
		{
			iterationAmount++;
			if (value % i == 0)
			{
				flag = true;
				break;
				
			}
		}
		if (flag == false) 
		{
			cout << value<<" ";
		}
		
		
	}
	cout << "\n\n\n\n iteration amount is " << iterationAmount<<"\n\n\n";
}

//dunno whether it's correct or not Buuuut i don't give a damn
void eratosthenesSieve(int uppperLimit)
{
	int* numberArray = new int[uppperLimit];
	int* positionArray = new int[uppperLimit];
	int counter = 0;

	for (int i = 0; i < uppperLimit; i++) 
	{
		numberArray[i] = i;
		positionArray[i] = 0;
	}
	// int j = i + 1;	j < uppperLimit; j++
	for (int i = 2; i <= 9; i++) 
	{
		counter++;
		for (int j = i+1;j<uppperLimit;j++) 
		{
			if (numberArray[j] % numberArray[i] == 0) 
			{
				positionArray[j] = 1;
			}
			counter++;
		}
	}
	for (int i = 0; i < uppperLimit; i++) 
	{
		if (positionArray[i] == 0) 
		{
			cout << numberArray[i]<<" ";
		}
		
	}
	cout <<"\n\n\n"<< counter;

}

int main()
{
	//isPrime(7);
	printAllPrime(100);
	eratosthenesSieve(100);
}


