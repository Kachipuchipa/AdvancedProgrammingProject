#pragma once
#include <string>
using std::string;

enum Status { WATING, DELIVERING, DONE};

class Cargo
{
	string name;

	bool isExpress; // 특급여부

	int priority; // 우선도 1 ~ 10

	Status status; // 배송상태

	int delivererID; // 배송원ID 
	
public:
	Cargo();
	Cargo(string name, bool isExpress, int priority);
	
	int getPriority();
	string getName();
	bool IsExpress();
	Status getStatus();
	int getDelivererID();
	void setStatus(Status s);
	void setDelivererID(int id);
};

