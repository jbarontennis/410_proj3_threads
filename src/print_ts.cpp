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
	mx.lock();
	std::cout<<txt<<std::endl;
	mx.unlock();
}
void PRINT2(std::string &txt, std::string &txt1) {
	mx.lock();
		std::cout<<txt<<txt1<<std::endl;
		mx.unlock();
}
void PRINT3(std::string &txt, std::string &txt1, std::string &txt2){
	mx.lock();
		std::cout<<txt<<txt1<<txt2<<std::endl;
		mx.unlock();
}
void PRINT4(std::string &txt, std::string &txt1, std::string &txt2,
		std::string &txt3){
	mx.lock();
		std::cout<<txt<<txt1<<txt2<<txt3<<std::endl;
		mx.unlock();
}
void PRINT5(std::string &txt, std::string &txt1, std::string &txt2,
		std::string &txt3, std::string &txt4){
	mx.lock();
		std::cout<<txt<<txt1<<txt2<<txt3<<txt4<<std::endl;
		mx.unlock();
}

