#pragma once
#include <string>
#include <iostream>
using std::string;

enum Status { WATING, DELIVERING, DONE};

class Cargo
{
protected:
	string name;

	int pay;

	int priority; // 우선도 1 ~ 10

	Status status; // 배송상태

	int delivererID; // 배송원ID 
	
public:
	Cargo();
	Cargo(string name, int priority);
	virtual ~Cargo();

	int getPriority();
	string getName();
	virtual bool IsExpress() const = 0;
	int getPay();
	Status getStatus();
	int getDelivererID();
	void setStatus(Status s);
	void setDelivererID(int id);

	bool operator>(const Cargo& other) const;
	friend std::ostream& operator<<(std::ostream& os, const Cargo& c);


};

