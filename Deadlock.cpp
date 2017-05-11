/***************************************************************
	File Name: Deadlock.cpp
	Description: Function implementation are created here
***************************************************************/

#include "Deadlock.h"

// Global Mutex Locks
mutex lockNum1;
mutex lockNum2;

// Instance of "myStruct"
myStruct mystruct;

// Deadlock Scenario Below
void myThread1()
{
	//unique_lock<mutex> lock(lockNum1);
	lockNum1.lock();
	cout << "This is Thread 1" << endl;
	lockNum2.lock();
	lockNum2.unlock();
	lockNum1.unlock();
}

void myThread2() // Will Deadlock because the treads are not being locked in the same order
{
	lockNum2.lock();
	cout << "This is Thread 2" << endl;
	lockNum1.lock();
	lockNum1.unlock();
	lockNum2.unlock();
} // waiting indefinitly; T1 is waiting for a resource that T2 has and vice versa

void runThreads()
{
	thread threadNum1(myThread1);
	thread threadNum2(myThread2);

	threadNum1.join();
	threadNum2.join();

	cout << "Threads have finished!!" << endl;
}

// Modifications to Deadlock code Below
//
// Preventing Mutual Exclusion Solution
void myThread1Cond1() // Have Non-Exclusive control of resources
{
	lockNum1.lock();
	cout << "This is Thread 1" << endl;
	lockNum1.unlock();
}

void myThread2Cond1()
{
	lockNum1.lock();
	cout << "This is Thread 2" << endl;
	lockNum1.unlock();
}

void runThreadsCond1()
{
	thread threadNum1(myThread1Cond1);
	thread threadNum2(myThread2Cond1);

	threadNum1.join();
	threadNum2.join();

	cout << "Threads have finished!!" << endl;
}

//
// Allowing Preemption Solution
void myThread1Cond2() // preempt resources from a thread, and give the resources to a new thread requesting it.
{
	lockNum1.lock();
	mystruct.flag = 1;
	this_thread::sleep_for(2s);
	mystruct.flag2 = 2; // Lock 2 is available for T1 to use
	lockNum2.lock();
	cout << "This is Thread 1" << endl;
	lockNum1.unlock();
	lockNum2.unlock();
}

void myThread2Cond2()
{
	unique_lock<mutex> lock2(lockNum2);

	if (mystruct.flag == 1)
	{
		lock2.release(); // breaks ownership
		lockNum2.unlock();
		this_thread::sleep_for(2s);
	}

	if (mystruct.flag2 == 2)
	{
		lockNum2.lock();
		lockNum1.lock();
		cout << "This is Thread 2" << endl;
		lockNum1.unlock();
		lockNum2.unlock();
	}
}

void runThreadsCond2()
{
	thread threadNum1(myThread1Cond2);
	thread threadNum2(myThread2Cond2);

	threadNum1.join();
	threadNum2.join();

	cout << "Threads have finished!!" << endl;
}

//
// No Hold and Wait Solution
void myThread1Cond3() // A thread requests resources only when it has none.
{
	lockNum1.lock();
	cout << "This is Thread 1" << endl;
	lockNum1.unlock();
	mystruct.flag = 1; // After unlock
}

void myThread2Cond3()
{
	lockNum1.lock();
	if (mystruct.flag == 0) // Lock 1 not available yet
	{
		this_thread::sleep_for(2s);
	}
	else if (mystruct.flag == 1) // Lock 1 is available
	{
		//lockNum1.lock();
		cout << "This is Thread 2" << endl;
		//lockNum1.unlock();
	}
	lockNum1.unlock();
}

void runThreadsCond3()
{
	thread threadNum1(myThread1Cond3);
	thread threadNum2(myThread2Cond3);

	threadNum1.join();
	threadNum2.join();

	cout << "Threads have finished!!" << endl;
}

//
// Circular Wait Solution
void myThread1Cond4() // need to lock the mutex's in the same order to avoid Deadlock
{
	lockNum1.lock(); // Lock the first mutex, and then lock the second mutex
	cout << "This is Thread 1" << endl;
	lockNum2.lock();
	lockNum1.unlock();
	lockNum2.unlock();
}

void myThread2Cond4()
{
	lockNum1.lock(); // Do the same order here too
	cout << "This is Thread 2" << endl;
	lockNum2.lock();
	lockNum1.unlock();
	lockNum2.unlock();
}

void runThreadsCond4()
{
	thread threadNum1(myThread1Cond4);
	thread threadNum2(myThread2Cond4);

	threadNum1.join();
	threadNum2.join();

	cout << "Threads have finished!!" << endl;
}
