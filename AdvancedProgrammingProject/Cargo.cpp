#include "Cargo.h"

inline Cargo::Cargo()
{
	name = "EMPTY";
	priority = -1;
	status = WATING;
	delivererID = -1;
}

Cargo::Cargo(string name, int priority)
	:name(name), priority(priority),status(WATING),delivererID(-1) 
	//status와 delivererID는 반드시 추후에 결정되기에 고정값
{
	
}

int Cargo::getPriority()
{
	return priority;
}

string Cargo::getName()
{
	return name;
}

int Cargo::getPay()
{
	return pay;
}

Status Cargo::getStatus()
{
	return status;
}

int Cargo::getDelivererID()
{
	return delivererID;
}

void Cargo::setStatus(Status s)
{
	status = s;
}

void Cargo::setDelivererID(int id)
{
	delivererID = id;
}