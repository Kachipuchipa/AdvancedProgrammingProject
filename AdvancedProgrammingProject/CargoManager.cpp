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
	Cargo* newCargo = nullptr;
	if (isExpress)
	{
		newCargo = new ExpressCargo(name, priority);
	}
	else
	{
		newCargo = new NormalCargo(name, priority);
	}

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
		cout << i + 1 << ". " << *cargos[i] << endl << endl;
	}
	
}



void CargoManager::saveFile()
{
	ofstream ofs("cargos.txt");
	if (!ofs.is_open())
	{
		cout << "파일 저장 실패" << endl;
		return;
	}
	for (int i = 0; i < size; i++)
	{
		ofs << cargos[i]->getName() << "\t"
			<< cargos[i]->IsExpress() << "\t"
			<< cargos[i]->getPriority() << "\t"
			<< (int)cargos[i]->getStatus() << "\t"
			<< cargos[i]->getDelivererID() << "\n";
	}
	ofs.close();
	cout << "저장 완료 (" << size << "건)" << endl;
}

void CargoManager::loadFile()
{
	ifstream ifs("cargos.txt");
	if (!ifs.is_open())
	{
		cout << "저장 파일 없음 (cargos.txt)" << endl;
		return;
	}
	cout << "=========================================" << endl;
	cout << "            파일 배송 현황 조회           " << endl;
	cout << "=========================================" << endl;

	string name;
	int isExpress, priority, statusInt, delivererID;
	int count = 0;

	while (ifs >> name >> isExpress >> priority >> statusInt >> delivererID)
	{
		count++;
		string statusStr = (statusInt == 0) ? "대기중" : (statusInt == 1) ? "배송중" : "배송완료";
		cout << count << ". " << name
			<< " | " << (isExpress ? "특급" : "일반")
			<< " | 우선도: " << priority
			<< " | 상태: " << statusStr
			<< " | 담당기사: ";
		if (delivererID == -1) cout << "미정";
		else cout << delivererID << "번 기사님";
		cout << endl;
	}
	ifs.close();

	if (count == 0) cout << "저장된 내역 없음" << endl;
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
	deliverers[deliverersSize] = new Deliverer(deliverersSize+1);
	deliverersSize++;
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
		deliverers[i] = new Deliverer(deliverersSize+1);
		deliverersSize++;
	}
}

CargoManager::~CargoManager()
{
	for (int i = 0; i < size; i++)
		delete cargos[i];
	delete[] cargos;

	for (int i = 0; i < deliverersSize; i++)
		delete deliverers[i];
	delete[] deliverers;
}