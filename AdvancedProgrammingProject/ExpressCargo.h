#pragma once
#include "Cargo.h"

class ExpressCargo : public Cargo
{
private:
	
public://TODO cpp로 옮기기
	
	ExpressCargo(string name,int priority)
		:Cargo(name, priority)
	{
		pay = 10000;
	}

	bool IsExpress() override { return true; }
	
};