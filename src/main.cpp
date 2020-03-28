/*
 * main.cpp
 *
 *  Created on: Mar 28, 2020
 *      Author: james
 */
#include "../header files/tester.h"

//string,numThreads,wp,timestoprint,delay
int main() {
	startThreads("tx", 2, P4, 1, 0);
	//joinThreads();
	setCancelThreads(true);
	startThreads("js", 10, P5, 2, 100);

	 joinThreads();

}


