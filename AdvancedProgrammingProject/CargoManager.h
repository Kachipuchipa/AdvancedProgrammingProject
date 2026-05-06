#pragma once
#include "Cargo.h"
#include "Deliverer.h"

class CargoManager
{
	Cargo** cargos;
	Deliverer** deliverers;
	int deliverersCount = 1;
	int capacity = 1;
	int size = 0;

public:
	void addCargoForm(); 

	void addCargo(std::string& name, bool isExpress, int priority);

	void printCargo(); // 목록조회

	void saveFile();

	void loadFile();

	void assignCargo(); // 물류를 배송기사에게 할당하면 배송기사가 배달을 시작한다

	CargoManager();
	//TODO 소멸자
};