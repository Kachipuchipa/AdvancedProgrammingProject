#include <iostream>
#include "CargoManager.h"
#include <Windows.h>

using namespace std;

int main()
{
	CargoManager& cm = CargoManager::getInstance();

	while (true)
	{
		system("cls");
		int opt = -1;
		cout << "=========================================" << endl;
		cout << "                   메뉴                  " << endl;
		cout << "=========================================" << endl;
		cout << "1.물류 등록" << endl;
		cout << "2.물류 조회" << endl;
		cout << "3.배송 배정" << endl;
		cout << "4.배송원 구매" << endl;
		cout << "5.잔액 조회" << endl;
		cout << "6.파일 저장" << endl;
		cout << "7.파일 불러오기" << endl;
		cout << "0.종료" << endl;

		cin >> opt;
		system("cls");

		switch (opt)
		{
		case 0:
			return 0;
		case 1:
			cm.addCargoForm();
			break;
		case 2:
			cm.printCargo();
			break;
		case 3:
			cm.assignCargo();
			break;
		case 4:
			cm.buyDeliverer();
			break;
		case 5:
			cm.checkAccount();
			break;
		case 6:
			cm.saveFile();
			break;
		case 7:
			cm.loadFile();
			break;
		default:
			cout << "잘못된 입력입니다." << endl;
			break;
		}

		cout << "\n\nPress Any Key...";
		system("pause");
	}

	return 0;
}