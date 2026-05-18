#pragma once

#include <ctime>
class Cargo;
class CargoManager; //순환참조로 인한 전방참조

class Deliverer
{
	int id ;
	Cargo* assignedCargo;
	bool isAssigned = false;

	time_t deliver_start;


public:
	
	Deliverer(int id);

	int getId();
	bool IsAssigned();
	void startDelivery();
	void checkDeliver();
	void delegateCargo(Cargo* cargo);

};

