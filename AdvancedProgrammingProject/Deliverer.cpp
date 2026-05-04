#include "Deliverer.h"



Deliverer::Deliverer(int id)
{
	
	this->id = id;
	isAssigned = false;
	//deliver_start = 0;
}

void Deliverer::deleverSatrt()
{
	deliver_start = time(nullptr);
}



void Deliverer::checkDeliver()
{
	if (time(nullptr) - deliver_start < 10)
	{
		assignedCargo->setStatus(Status::DONE);
		isAssigned = false;
	}
}

void Deliverer::delegateCargo(Cargo* cargo)
{
	assignedCargo = cargo;
	isAssigned = true;
}
