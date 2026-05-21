#include "NormalCargo.h"

inline NormalCargo::NormalCargo(string name, int priority)
	:Cargo(name, priority)
{
	pay = 5000;
}

inline NormalCargo::~NormalCargo() {}

inline bool NormalCargo::IsExpress() { return false; }
