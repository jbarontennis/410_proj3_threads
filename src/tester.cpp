/*
 * tester.cpp
 *
 *  Created on: Mar 11, 2020
 *      Author: james
 */
#include <thread>
#include <iostream>
#include <vector>
#include "tester.h"
std::string st;
int numThread;
WHICH_PRINT w;
int timesToPrint;
int delay;
std::vector<std::thread> threads;
void startThreads(std::string s, int numThreads, WHICH_PRINT wp,
		int numTimesToPrint, int millisecond_delay){
	st = s;
	w = wp;
	timesToPrint = numTimesToPrint;
	delay = millisecond_delay;
	for(int i = 0;i<numThreads;i++){
		std::thread tmp;
		threads.push_back(tmp);
	}
}
void setCancelThreads(bool bCancel){

}
void joinThreads(){
for(int i = 0;i<numThread;i++){
	threads[i].join();
}
}



