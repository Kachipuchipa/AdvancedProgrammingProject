#include "CargoManager.h"
#include <Windows.h>
#include <iostream>
#include <fstream>
using namespace std;



CargoManager& CargoManager::getInstance() { //Deliverer에서 접근위해 싱글톤
	static CargoManager instance;
	return instance;
}

 int CargoManager::getMoney() { return money; }

void CargoManager::setMoney(int m) { money = m; }

void CargoManager::addCargoForm() // 잘못된입력값 예외처리 생략
{
	string name;
	bool isExpress;
	char temp;
	int priority;
	cout << "=========================================" << endl;
	cout << "                 물류 등록                " << endl;
	cout << "=========================================" << endl;
	cout << "이름 : "; cin.ignore(); getline(cin, name);
	cout << "특급여부(Y/N) : "; cin >> temp; isExpress = (temp == 'Y') ? true : false;
	cout << "우선도(1 ~ 10) : "; cin >> priority;

	addCargo(name, isExpress, priority);
}

void CargoManager::addCargo(string& name, bool isExpress, int priority)
{
	Cargo* newCargo = new Cargo(name, isExpress, priority);

	if (size >= capacity) // 용량초과시 용량2배
	{
		capacity *= 2;
		Cargo** temp = cargos;
		cargos = new Cargo * [capacity];
		for (int i = 0; i < size; i++)
		{
			cargos[i] = temp[i];
		}
	}


	cargos[size] = newCargo;
	size++;

	for (int i = size - 1; i > 0; i--)
	{
		if (cargos[i]->IsExpress() > cargos[i - 1]->IsExpress() ||
			(cargos[i]->IsExpress() == cargos[i - 1]->IsExpress() &&
				cargos[i]->getPriority() > cargos[i - 1]->getPriority()))
		{

			Cargo* temp = cargos[i];
			cargos[i] = cargos[i - 1];
			cargos[i - 1] = temp;
		}
		else break;
	}
	
}

string statusToString(Status s)
{
	if (s == Status::DELIVERING) return "배송중";
	else if (s == Status::WATING) return "대기중";
	else if (s == Status::DONE) return "배송완료";
}

void CargoManager::printCargo()
{
	cout << "=========================================" << endl;
	cout << "                 물류 조회                " << endl;
	cout << "=========================================" << endl;

	for (int i = 0; i < deliverersSize; i++)
	{
		if (deliverers[i]->IsAssigned())
			deliverers[i]->checkDeliver();
	}

	for (int i = 0; i < size; i++)
	{
		cout << i + 1 << "." << endl;;
		cout << "이름 : " << cargos[i]->getName() << endl;
		cout << "특급여부 : " << ((cargos[i]->IsExpress()) ? "특급" : "일반") << endl;
		cout << "상태 : " << statusToString(cargos[i]->getStatus()) << endl;
		cout << "담당기사 : ";
		if (cargos[i]->getDelivererID() == -1) cout << "미정";
		else cout << cargos[i]->getDelivererID() << "번 기사님"; //배송완료상태라면 배송을 담담했던 기사님
		cout << endl << endl << endl;
	}
	
}

void CargoManager::saveFile()
{
}

void CargoManager::loadFile() { // TODO 
	
}

void CargoManager::assignCargo()
{
	cout << "배송가능한 배달기사를 탐색합니다." << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << ". ";
		//Sleep(1500); TODO 주석제거
	}
	cout << endl;


	Deliverer* deliverer = nullptr;
	Cargo* cargo = nullptr;

	for (int i = 0; i < deliverersSize; i++)
	{
		if (deliverers[i]->IsAssigned() == false)
		{
			deliverer = deliverers[i];
			break;
		}
		
	}
	if (!deliverer)
	{
		cout << "현재 배송가능한 기사가 없습니다." << endl;
		return;
	}
	cout << deliverer->getId() << "번 기사님이 배정되었습니다." << endl << endl;

	cout << "대기중인 물류를 탐색합니다." << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << ". ";
		//Sleep(1500); TODO 주석제거
	}
	cout << endl;

	for (int i = 0; i < size; i++)
	{
		if (cargos[i]->getStatus() == Status::WATING)
		{
			cargo = cargos[i];
			break;
		}
	}
	if (!cargo)
	{
		cout << "현재 대기중인 물류가 없습니다." << endl;
		return;
	}
	deliverer->delegateCargo(cargo);
	cout << cargo->getName() << "을(를) 배송합니다." << endl;

	deliverer->startDelivery();


}

void CargoManager::buyDeliverer()
{

	if (money < 5000)
	{
		cout << "*잔액부족*" << endl;
		cout << 5000 - money << "원 부족합니다." << endl;
		return;
	}

	money -= 5000;

	if (deliverersSize >= delivererCapacity)
	{
		delivererCapacity *= 2;
		Deliverer** temp = deliverers;
		deliverers = new Deliverer * [delivererCapacity];
		for (int i = 0; i < deliverersSize; i++)
		{
			deliverers[i] = temp[i];
		}
		
		delete[] temp;
	}
	deliverersSize++;
	deliverers[deliverersSize - 1] = new Deliverer(deliverersSize);
	cout << "배송기사가 " << deliverersSize - 1 << "명에서 " << deliverersSize << "명이 됐습니다." << endl;
}

void CargoManager::checkAccount()
{
	cout << "현재 잔액 : " << money << "원" << endl;
}





CargoManager::CargoManager()
{
	cargos = new Cargo * [capacity];
	deliverers = new Deliverer * [delivererCapacity];
	for (int i = 0; i < delivererCapacity; i++)
	{
		deliverers[i] = new Deliverer(deliverersSize);
		deliverersSize++;
	}
}
