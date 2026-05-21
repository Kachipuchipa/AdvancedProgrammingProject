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

inline Cargo::~Cargo() {}

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

bool Cargo::operator>(const Cargo& other) const
{
	if (IsExpress() != other.IsExpress())
		return IsExpress() > other.IsExpress();
	return priority > other.priority;
}

std::ostream& operator<<(std::ostream& os, const Cargo& c)
{
	os << c.name << " | " << (c.IsExpress() ? "특급" : "일반")
		<< " | 우선도: " << c.priority;
	return os;
}
