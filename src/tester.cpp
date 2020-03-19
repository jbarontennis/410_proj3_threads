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
		int numTimesToPrint, int millisecond_delay) {

	st = s;
	w = wp;
	//std::thread tmp(PRINT1, std::ref(s));
	timesToPrint = numTimesToPrint;
	delay = millisecond_delay;
	//std::thread cancelthread(setCancelThreads, false);
	for (int i = 0; i < numThreads; i++) {
		if (wp == P1) {
			threads.push_back(std::thread(PRINT1, std::ref(s)));
			for (int j = 1; j < numTimesToPrint; j++) {
				PRINT1(s);
			}
		} else if (wp == P2) {
			threads.push_back(std::thread(PRINT2, std::ref(s), std::ref(s)));
			for (int j = 1; j < numTimesToPrint; j++) {
				PRINT2(s, s);
			}
		} else if (wp == P3) {
			threads.push_back(
					std::thread(PRINT3, std::ref(s), std::ref(s), std::ref(s)));
			for (int j = 1; j < numTimesToPrint; j++) {
				PRINT3(s, s, s);
			}
		} else if (wp == P4) {
			threads.push_back(
					std::thread(PRINT4, std::ref(s), std::ref(s), std::ref(s),
							std::ref(s)));
			for (int j = 1; j < numTimesToPrint; j++) {
				PRINT4(s, s, s, s);
			}
		} else {
			threads.push_back(
					std::thread(PRINT5, std::ref(s), std::ref(s), std::ref(s),
							std::ref(s), std::ref(s)));
			for (int j = 1; j < numTimesToPrint; j++) {
				PRINT5(s, s, s, s, s);
			}
		}

	}
joinThreads();
}
void setCancelThreads(bool bCancel) {

}
void joinThreads() {
	for (int i = 0; i < numThread; i++) {
		threads[i].join();
	}

}
int main() {
	startThreads("tx", 2, P1, 1, 10);

}

