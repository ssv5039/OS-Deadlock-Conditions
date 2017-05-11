#pragma once
/***************************************************************
File Name: Deadlock.h
Description: Function declaration and preprocessors
***************************************************************/

#include <iostream>
#include <mutex>
#include <thread>
using namespace std;

typedef struct myStruct {
	int flag = 0; // Flags used to check if a lock is available
	int flag2 = 0;
};

// Defined Functions
void myThread1();
void myThread2();
void myThread1Cond1();
void myThread2Cond1();
void myThread1Cond2();
void myThread2Cond2();
void myThread1Cond3();
void myThread2Cond3();
void myThread1Cond4();
void myThread2Cond4();

void runThreads();
void runThreadsCond1();
void runThreadsCond2();
void runThreadsCond3();
void runThreadsCond4();