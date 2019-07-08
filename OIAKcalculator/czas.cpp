#include "czas.h"

	czas::czas() {
		
	};
	czas::~czas() {

	};
	void czas::czasStart() {
		czasPoczatkowy = high_resolution_clock::now();
	}
	void czas::czasStop() {
		 czasKoncowy = high_resolution_clock::now();
	}
	long czas::czasWykonania() {
        return duration_cast<microseconds>(czasKoncowy - czasPoczatkowy).count();
	}

