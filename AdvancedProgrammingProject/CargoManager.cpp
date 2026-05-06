#include "CargoManager.h"
#include <Windows.h>
#include <iostream>
#include <fstream>
using namespace std;

void CargoManager::addCargoForm() // 잘못된입력값 예외처리 생략
{
	string name;
	bool isExpress;
	char temp;
	int priority;
	cout << "=========================================" << endl;
	cout << "			      물류 등록                " << endl;
	cout << "=========================================" << endl;
	cout << "이름 : "; getline(cin, name); cin.ignore();
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
		if (cargos[i]->getPriority() > cargos[i - 1]->getPriority())
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
	else if (s == Status::NONE) return "미정";
}

void CargoManager::printCargo()
{
	cout << "=========================================" << endl;
	cout << "                 물류 조회                " << endl;
	cout << "=========================================" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << i + 1 << "." << endl;;
		cout << "이름 : " << cargos[i]->getName() << endl;
		cout << "특급여부 : " << ((cargos[i]->IsExpress()) ? "특급" : "일반") << endl;
		cout << "상태 : " << statusToString(cargos[i]->getStatus()) << endl;
		cout << "담당기사 : " << cargos[i]->getDelivererID() << "번 기사님" << endl << endl << endl;
	}
}

void CargoManager::saveFile()
{
	const char* filename = "cargos.txt";
	ofstream ofs(filename, ios::trunc);
	if (!ofs.is_open()) {
		cerr << "파일을 열 수 없습니다: " << filename << endl;
		return;
	}

	ofs << size << '\n';

	for (int i = 0; i < size; ++i) {
		ofs << cargos[i]->getName() << '\t'
			<< (cargos[i]->IsExpress() ? 1 : 0) << '\t'
			<< cargos[i]->getPriority() << '\t'
			<< static_cast<int>(cargos[i]->getStatus()) << '\t'
			<< cargos[i]->getDelivererID() << '\n';
	}

	ofs.close();
}

void CargoManager::loadFile() { // TODO 테스트하기
	//-tx for claude and codex-

	ifstream ifs("cargos.txt");
	if (!ifs.is_open()) return;

	int count = 0;
	ifs >> count;
	ifs.ignore();

	for (int i = 0; i < count; i++) {
		string name;
		int isExpress, priority, statusInt, delivererID;

		getline(ifs, name, '\t');
		if (!name.empty() && name.back() == '\r') name.pop_back();
		ifs >> isExpress >> priority >> statusInt >> delivererID;
		ifs.ignore();

		addCargo(name, (bool)isExpress, priority);
		cargos[size - 1]->setStatus(static_cast<Status>(statusInt));
		cargos[size - 1]->setDelivererID(delivererID);
	}
	ifs.close();
}

void CargoManager::assignCargo()
{
	cout << "배송가능한 배달기사를 탐색합니다." << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << ". ";
		Sleep(1500);
	}
	cout << endl;


	Deliverer* deliver;

	for (int i = 0; i < deliverersCount; i++)
	{
		if (deliverers[i]->IsAssigned() == false)
		{
			deliver = deliverers[i];
			break;
		}
	}

	cout << deliver->getId() << "번 기사님이 배정되었습니다." << endl;

	for (int i = 0; i < size; i++)
	{
		cargos[i].
	}
}



CargoManager::CargoManager()
{
	cargos = new Cargo * [capacity];
	deliverers = new Deliverer*[deliverersCount];
}
