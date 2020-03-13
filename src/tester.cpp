/*
 * tester.cpp
 *
 *  Created on: Mar 11, 2020
 *      Author: james
 */
#include <thread>
#include <iostream>
#include <vector>
#include <mutex>
#include "../header files/tester.h"
#include "../header files/print_ts.h"
std::string st;
int numThread;
WHICH_PRINT w;
int timesToPrint;
int delay;
std::mutex mtx;
std::vector<std::thread> threads;
void startThreads(std::string s, int numThreads, WHICH_PRINT wp,
		int numTimesToPrint, int millisecond_delay){
	st = s;
	w = wp;
	timesToPrint = numTimesToPrint;
	delay = millisecond_delay;
	for(int i = 0;i<numThreads;i++){
		threads.push_back(std::thread(PRINT1,s));
	}
	for(int i = 0;i<numThreads;i++){
		mtx.lock();
		if(wp == P1){
			PRINT1(s);
		}else if(wp == P2){
			PRINT2(s,s);
		}else if(wp == P3){
			PRINT3(s,s,s);
		}else if(wp == P4){
			PRINT4(s,s,s,s);
		}else{
			PRINT5(s,s,s,s,s);
		}
		mtx.unlock();
	}
}
void setCancelThreads(bool bCancel){

}
void joinThreads(){
for(int i = 0;i<numThread;i++){
	threads[i].join();
}

}
int main(){
	startThreads("tx",2,P1,1,10);

}



