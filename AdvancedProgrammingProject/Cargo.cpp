#include "Cargo.h"

inline Cargo::Cargo()
{
	name = "EMPTY";
	isExpress = false;
	priority = -1;
	status = WATING;
	delivererID = -1;
}

Cargo::Cargo(string name, bool isExpress, int priority)
	:name(name), isExpress(isExpress), priority(priority),status(WATING),delivererID(-1) 
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

bool Cargo::IsExpress()
{
	return isExpress;
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