#include "ExpressCargo.h"

ExpressCargo::ExpressCargo(string name, int priority)
	:Cargo(name, priority)
{
	pay = 10000;
}

bool ExpressCargo::IsExpress() const { return true; }

ExpressCargo::~ExpressCargo() {}
