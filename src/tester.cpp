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

std::mutex mtx;
std::vector<std::thread> threads;
bool cancel;
void threadHandler(int numThreads, int numPrints, int mili, WHICH_PRINT w,
		string m) {
	for (int j = 0; j < numPrints; j++) {
		if(cancel){
			break;
		}
		else if (w == P1) {
			PRINT1(m);
		} else if (w == P2) {
			PRINT2(m, m);
		} else if (w == P3) {
			PRINT3(m, m, m);
		} else if (w == P4) {
			PRINT4(m, m, m, m);
		} else {
			PRINT5(m, m, m, m, m);
		}
		this_thread::sleep_for(chrono::milliseconds(mili));
	}
}
void startThreads(std::string s, int numThreads, WHICH_PRINT wp,
		int numTimesToPrint, int millisecond_delay) {
	setCancelThreads(false);
	for (int i = 0; i < numThreads; i++) {
		threads.push_back(
				std::thread(threadHandler, numThreads, numTimesToPrint,
						millisecond_delay, wp, s));
	}

}

void setCancelThreads(bool bCancel) {
	std::mutex tmp;
	cancel = bCancel;
	if (bCancel) {
		for (auto &t : threads) {
			lock_guard<mutex> lock(tmp);
			this_thread::sleep_for(chrono::milliseconds(100));
			printf("%s\n", USER_CHOSE_TO_CANCEL.c_str());
		}

	}
}
void joinThreads() {
	for (auto &t : threads) {
		t.join();
	}
threads.clear();
}


