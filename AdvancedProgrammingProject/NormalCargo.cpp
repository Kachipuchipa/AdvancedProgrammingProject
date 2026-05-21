#include "NormalCargo.h"

NormalCargo::NormalCargo(string name, int priority)
	:Cargo(name, priority)
{
	pay = 5000;
}

NormalCargo::~NormalCargo() {}

bool NormalCargo::IsExpress() const { return false; }
