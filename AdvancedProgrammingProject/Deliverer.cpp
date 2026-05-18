#include "Deliverer.h"
#include "CargoManager.h"


Deliverer::Deliverer(int id)
{
	
	this->id = id;
	isAssigned = false;
	//deliver_start = 0;
}

int Deliverer::getId()
{
	return id;
}

bool Deliverer::IsAssigned()
{
	return isAssigned;
}

void Deliverer::startDelivery()
{
	deliver_start = time(nullptr);
}



void Deliverer::checkDeliver() //배송이 완료될 시간이 지나더라도 체크해주지 않으면 완료되지 않는다
{

	if (time(nullptr) - deliver_start > 5) //TODO 시간 바꾸기
	{
		CargoManager& cm = CargoManager::getInstance();
		cm.setMoney(cm.getMoney() + assignedCargo->getPay()); //TODO 특급 일반 가격 다르게 

		assignedCargo->setStatus(Status::DONE);
		assignedCargo = nullptr;
		isAssigned = false;
		
		
	}
}

void Deliverer::delegateCargo(Cargo* cargo) //TODO : start 와 합칠지 고민
{
	assignedCargo = cargo;
	isAssigned = true;
	cargo->setStatus(DELIVERING);
	cargo->setDelivererID(id);
}
