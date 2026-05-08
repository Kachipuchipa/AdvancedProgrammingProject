#pragma once
#include "Cargo.h"
#include "Deliverer.h"


class CargoManager
{
	Cargo** cargos;
	int capacity = 1;
	int size = 0;
	
	Deliverer** deliverers; 
	int deliverersSize = 0; // 시작시 capacity 만큼 채워짐
	int delivererCapacity = 1;

	int money = 100000;



	CargoManager();




	void addCargo(std::string& name, bool isExpress, int priority);
public:

	static CargoManager& getInstance();

	int getMoney();

	void setMoney(int m);

	void addCargoForm(); 

	void printCargo(); // 목록조회

	void saveFile();

	void loadFile();

	void assignCargo(); // 물류를 배송기사에게 할당하면 배송기사가 배달을 시작한다

	void buyDeliverer();

	void checkAccount();
	
	//TODO 소멸자
};