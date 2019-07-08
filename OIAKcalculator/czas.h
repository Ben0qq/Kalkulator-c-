#pragma once
#ifndef CZAS_HPP_
#define CZAS_HPP_
#include <iostream>
#include <chrono>//biblioteka c++11 mierz¹ca czas z pomoc¹ procesora
using namespace std::chrono;

class czas
{
private:
	high_resolution_clock::time_point czasPoczatkowy = high_resolution_clock::now();;
	high_resolution_clock::time_point czasKoncowy = high_resolution_clock::now();;
public:
	czas();
	~czas();
	void czasStart();
	void czasStop();
	long czasWykonania();
};
#endif /* CZAS_HPP_ */
