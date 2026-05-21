#pragma once
#include "Cargo.h"

class NormalCargo :public Cargo
{
private:
	
public:

	NormalCargo(string name, int priority);
	virtual ~NormalCargo();
	bool IsExpress() override;
};