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
#include <time.h>
#include <chrono>
#include "../header files/tester.h"
#include "../header files/print_ts.h"
using namespace std;
std::string st;
int numThread;
WHICH_PRINT w;
int timesToPrint;
int delay;
std::mutex mtx;
std::vector<std::thread> threads;
void startThreads(std::string s, int numThreads, WHICH_PRINT wp,
		int numTimesToPrint, int millisecond_delay) {

	st = s;
	w = wp;
	timesToPrint = numTimesToPrint;
	delay = millisecond_delay;
	for (int i = 0; i < numThreads; i++) {
		if (wp == P1) {
			threads.push_back(std::thread(PRINT1, std::ref(s)));
			this_thread::sleep_for(chrono::milliseconds(delay));
			for (int j = 1; j < numTimesToPrint; j++) {
				PRINT1(s);
				this_thread::sleep_for(chrono::milliseconds(delay));
			}
		} else if (wp == P2) {
			threads.push_back(std::thread(PRINT2, std::ref(s), std::ref(s)));
			this_thread::sleep_for(chrono::milliseconds(delay));
			for (int j = 1; j < numTimesToPrint; j++) {
				PRINT2(s, s);
				this_thread::sleep_for(chrono::milliseconds(delay));
			}
		} else if (wp == P3) {
			threads.push_back(
					std::thread(PRINT3, std::ref(s), std::ref(s), std::ref(s)));
			this_thread::sleep_for(chrono::milliseconds(delay));
			for (int j = 1; j < numTimesToPrint; j++) {
				PRINT3(s, s, s);
				this_thread::sleep_for(chrono::milliseconds(delay));
			}
		} else if (wp == P4) {
			threads.push_back(
					std::thread(PRINT4, std::ref(s), std::ref(s), std::ref(s),
							std::ref(s)));
			this_thread::sleep_for(chrono::milliseconds(delay));
			for (int j = 1; j < numTimesToPrint; j++) {
				PRINT4(s, s, s, s);
				this_thread::sleep_for(chrono::milliseconds(delay));
			}
		} else {
			threads.push_back(
					std::thread(PRINT5, std::ref(s), std::ref(s), std::ref(s),
							std::ref(s), std::ref(s)));
			this_thread::sleep_for(chrono::milliseconds(delay));
			for (int j = 1; j < numTimesToPrint; j++) {
				PRINT5(s, s, s, s, s);
				this_thread::sleep_for(chrono::milliseconds(delay));
			}
		}

	}

	threads.clear();
		}

void setCancelThreads(bool bCancel) {
	std::mutex tmp;
if(bCancel){
	for(auto& t : threads){
		tmp.lock();
		std::cout<<USER_CHOSE_TO_CANCEL<<std::endl;
		tmp.unlock();
	}
}
}
void joinThreads() {
	for(auto& t : threads){
			t.join();
		}

}
//string,numThreads,wp,timestoprint,delay
int main() {
	startThreads("tx", 10, P4, 1, 1000);
	setCancelThreads(false);
	startThreads("js", 10, P5, 2, 1000);
	std::string tm1 = "pop";
	std::string tm2 = "horn";
	PRINT3(tm1,tm2,tm1);
}

