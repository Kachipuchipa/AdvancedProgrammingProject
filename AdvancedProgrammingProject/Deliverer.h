#pragma once
#include "Cargo.h"
#include <ctime>

class Deliverer
{
	int id = 0;
	Cargo* assignedCargo;
	bool isAssigned = false;
	
	time_t deliver_start;


public:
	
	Deliverer(int id);

	void deleverSatrt();
	void checkDeliver();
	void delegateCargo(Cargo* cargo);

};

