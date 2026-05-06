#include <iostream>
#include "CargoManager.h"
#include <Windows.h>



using namespace std;
int main()
{
	CargoManager cm;
	while (true)
	{
		system("cls");
		int opt = -1;
		cout << "=========================================" << endl;
		cout << "                   메뉴                  " << endl;
		cout << "=========================================" << endl;
		cout << "1.물류 등록 2.물류 조회 3.물류 할당 4.파일 저장 5.파일 불러오기" << endl;
		
		cin >> opt;

		system("cls");
		switch (opt)
		{
		case 1:
			cm.addCargoForm();
			break;
		case 2:
			cm.printCargo();
			break;
		case 3:
			cm.assignCargo(); //가장 우선도가 높은 대기물류 한개 할당
			break;
		case 4://TODO
			break;
		case 5://TODO
			break;
		}

		cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nPress Any Key...";
		system("pause");

	}
		return 0;
}