/*
 * print_ts.cpp
 *
 *  Created on: Mar 11, 2020
 *      Author: james
 */
#include <mutex>
#include <iostream>
#include "../header files/print_ts.h"
std::mutex mx;
void PRINT1(std::string &txt) {
	std::lock_guard<std::mutex> lock(mx);
	printf("%s\n", txt.c_str());
}
void PRINT2(std::string &txt, std::string &txt1) {
	std::lock_guard<std::mutex> lock(mx);
	std::string tmp = txt + txt1;
	printf("%s\n", tmp.c_str());
}
void PRINT3(std::string &txt, std::string &txt1, std::string &txt2){
	std::lock_guard<std::mutex> lock(mx);
	std::string tmp = txt + txt1 + txt2;
	printf("%s\n", tmp.c_str());
}
void PRINT4(std::string &txt, std::string &txt1, std::string &txt2,
		std::string &txt3){
	std::lock_guard<std::mutex> lock(mx);
	std::string tmp = txt + txt1 + txt2 + txt3;
	printf("%s\n", tmp.c_str());
}
void PRINT5(std::string &txt, std::string &txt1, std::string &txt2,
		std::string &txt3, std::string &txt4){
	std::lock_guard<std::mutex> lock(mx);
	std::string tmp = txt + txt1 + txt2 + txt3 + txt4;
	printf("%s\n", tmp.c_str());
}

