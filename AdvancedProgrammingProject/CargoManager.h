#pragma once
#include "Cargo.h"
#include "Deliverer.h"

class CargoManager
{
	Cargo** cargos;
	//TODO 배달기사 , 배달기사 수 
	int capacity = 1;
	int size = 0;

public:
	void addCargoForm(); //TODO 등록시 우선도 순으로 정렬하면서 등록

	void addCargo(std::string& name, bool isExpress, int priority);

	void printCargo(); // 목록조회

	void saveFile();

	void loadFile();

	void assignCargo(); // 물류를 배송기사에게 할당하면 배송기사가 배달을 시작한다

	CargoManager();
};