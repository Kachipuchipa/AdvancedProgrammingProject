#include <iostream>
#include "CargoManager.h"



using namespace std;
int main()
{
	// CargoManager 인스턴스 생성 (파일 입출력 제외, 순수 동작 테스트)
	CargoManager mgr;

	// 여러 항목 추가 -> 배열 확장 및 우선도 정렬 동작 확인
	string a = "긴급문서";		mgr.addCargo(a, true, 10);
	string b = "소형박스";		mgr.addCargo(b, false, 5);
	string c = "가전제품";		mgr.addCargo(c, false, 7);
	string d = "문서류";		mgr.addCargo(d, true, 8);
	string e = "중형박스";		mgr.addCargo(e, false, 6);
	string f = "초특급";		mgr.addCargo(f, true, 10); // 동일 우선도 항목 테스트

	cout << "=== 초기 추가 후 목록 ===" << endl;
	mgr.printCargo();

	// 중간 우선도의 항목 추가 -> 적절한 위치에 삽입되는지 확인
	string g = "후속물품";		mgr.addCargo(g, false, 9);
	cout << "\n=== 추가 삽입 후 목록 ===" << endl;
	mgr.printCargo();

	// 더 많은 항목 추가하여 capacity 재할당(확장) 확인
	string h = "여분1"; mgr.addCargo(h, false, 3);
	string i = "여분2"; mgr.addCargo(i, false, 4);
	string j = "여분3"; mgr.addCargo(j, false, 2);

	cout << "\n=== 확장 후 전체 목록 ===" << endl;
	mgr.printCargo();

	return 0;
}