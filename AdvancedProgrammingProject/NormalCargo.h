#pragma once
#include "Cargo.h"

class NormalCargo :public Cargo
{
private:
	
public:

	NormalCargo(string name, int priority)
		:Cargo(name, priority)
	{
		pay = 5000;
	}
	bool IsExpress() override { return false; }
};