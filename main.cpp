/***************************************************************
Name: Shawn Varughese
File Name: main.cpp
Description: main function to execute code
***************************************************************/

#include "Deadlock.h"
/*#include <iostream>
#include <thread>
#include <mutex>
using namespace std;*/

int main(int argc, char* argv[])
{
	int userInput;
	cout << "Enter '0' for Deadlock Scenario" << endl;
	cout << "Enter '1' for Non Mutual Exclusion Solution" << endl;
	cout << "Enter '2' for Preemption Solution" << endl;
	cout << "Enter '3' for No Hold and Wait Solution" << endl;
	cout << "Enter '4' for Circular Wait Solution" << endl;
	cin >> userInput;

	if (userInput == 0)
	{
		runThreads(); // Program Hangs, Indefinite Waiting
	}
	else if (userInput == 1)
	{
		runThreadsCond1(); // Preventing Mutual Exclusion
	}
	else if (userInput == 2)
	{
		runThreadsCond2(); // Allow Preemption
	}
	else if (userInput == 3)
	{
		runThreadsCond3(); // Removing Hold and Wait
	}
	else if (userInput == 4)
	{
		runThreadsCond4(); // Lock in the Same Order
	}
	
	cout << endl;
	cout << "Exiting Program..." << endl;
	system("pause");
	return 0;
}
