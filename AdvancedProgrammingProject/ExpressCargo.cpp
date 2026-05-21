#include "ExpressCargo.h"

inline ExpressCargo::ExpressCargo(string name, int priority)
	:Cargo(name, priority)
{
	pay = 10000;
}

inline bool ExpressCargo::IsExpress() const { return true; }

inline ExpressCargo::~ExpressCargo() {}
