#pragma once
#include "Cargo.h"

class ExpressCargo : public Cargo
{
private:
	
public:
	
	ExpressCargo(string name,int priority);

	bool IsExpress() const override;
	virtual ~ExpressCargo();
};