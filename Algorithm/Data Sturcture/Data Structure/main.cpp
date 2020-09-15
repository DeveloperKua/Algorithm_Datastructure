#include "MyVector.h"
#include <Windows.h>
#include <vector>
// 앞에서 작성한 MyVector::GroupById 함수가 정상적으로 동작하는지를
// 검증하는 코드를 작성하세요.
// 프로그램이 컴파일이 되지 않거나 동작 도중에 오류가 발생하거나
// 검증하는 코드가 잘못된 경우 불이익을 받을 수 있습니다.
int main()
{
	// 여기에 검증하는 코드를 작성하세요.
	vector<int> STL_Vector(4);
	vector<int> STL_Vector2(8);
	//STL_Vector.push_back

	MyVector<int> MY_Vector(4);
	MyVector<int> MY_Vector2(8);
	int num = 1;
	int addID;
	int removeID;

	while (num != 0) {
		system("cls");
		printf("현재 총 용량 : %d", MY_Vector.GetCapacity());
		printf("\n현재 할당된 용량: %d", MY_Vector.GetSize());
		cout << "\nVector To String : " << MY_Vector.ToString() << endl;
		printf("\n1.벡터 추가 || 2.벡터 제거 \n3.벡터 용량제한 (총 용량을 할당된 용량으로 제한) || 0.종료\n");
		printf("|>>|"); scanf_s("%d", &num);

		switch (num)
		{
		case 0:
			num = 0;
			break;
		case 1:
			printf("\n추가할 id입력\n");
			printf("|>>|"); scanf_s("%d", &addID);
			MY_Vector.Add(addID);
			break;
		case 2:
			printf("\n제거할 id입력(입력한 id를 가진 모든 요소 삭제\n");
			printf("|>>|"); scanf_s("%d", &removeID);
			MY_Vector.RemoveAll(removeID);
			break;
		case 3:
			MY_Vector.TrimToSize();
			break;
		}
	}
	MY_Vector2.Add(1);
	MY_Vector2.Add(1);
	MY_Vector2.Add(1);
	MY_Vector2.Add(1);
	MY_Vector2.Add(1);

	//MY_Vector.Add(5);
	cout << "V1 크기, 용량" << endl;
	cout << MY_Vector.GetSize() << endl;
	cout << MY_Vector.GetCapacity() << endl;

	cout << "V2 크기, 용량" << endl;
	cout << MY_Vector2.GetSize() << endl;
	cout << MY_Vector2.GetCapacity() << endl;

	MY_Vector2.operator=(MY_Vector);
	cout << "복사 후 V1 크기, 용량" << endl;
	cout << MY_Vector2.GetSize() << endl;
	cout << MY_Vector2.GetCapacity() << endl;

	STL_Vector.clear();

	cout << "stl V1 크기, 용량" << endl;
	cout << STL_Vector.size() << endl;
	cout << STL_Vector.capacity() << endl;

	STL_Vector2.clear();
	STL_Vector2.push_back(1);
	STL_Vector2.push_back(1);
	STL_Vector2.push_back(1);
	STL_Vector2.push_back(1);
	STL_Vector2.push_back(1);
	cout << "stl V2 크기, 용량" << endl;
	cout << STL_Vector2.size() << endl;
	cout << STL_Vector2.capacity() << endl;

	STL_Vector2.operator=(STL_Vector);
	cout << "복사 후 stl V2 크기, 용량" << endl;
	cout << STL_Vector2.size() << endl;
	cout << STL_Vector2.capacity() << endl;
	/*
	MY_Vector.Add(10);
	cout << "Vector To String : " << MY_Vector.ToString() << endl;

	printf("\n현재 총 용량 : %d\n", V.GetCapacity());
	printf("현재 할당된 용량: %d\n", V.GetSize());
	Sleep(2500);

	printf("\n|벡터에 10 추가|\n");
	V.Add(10);
	cout << "Vector To String : " << V.ToString() << endl;

	printf("\n현재 총 용량 : %d\n", V.GetCapacity());
	printf("현재 할당된 용량: %d\n", V.GetSize());
	Sleep(2500);

	printf("\n|벡터에 30 추가|\n");
	V.Add(30);
	printf("\n현재 총 용량 : %d\n", V.GetCapacity());
	printf("현재 할당된 용량: %d\n", V.GetSize());
	cout << "Vector To String : " << V.ToString() << endl;
	Sleep(2500);

	printf("\n|벡터에 40,40,30 추가|\n");
	V.Add(40);
	V.Add(40);
	V.Add(30);
	cout << "Vector To String : " << V.ToString() << endl;
	printf("\n현재 총 용량 : %d\n", V.GetCapacity());
	printf("현재 할당된 용량: %d\n", V.GetSize());
	Sleep(2500);

	printf("\n|벡터에 10 제거|\n");
	V.RemoveAll(10);
	printf("\n현재 총 용량 : %d\n", V.GetCapacity());
	printf("현재 할당된 용량: %d\n", V.GetSize());

	cout << "Vector To String : " << V.ToString() << endl;
	Sleep(2500);

	printf("\n|벡터 용량을 현재 할당된 벡터 크기만큼으로 제한|\n");
	V.TrimToSize();
	printf("\n현재 총 용량 : %d\n", V.GetCapacity());
	printf("현재 할당된 용량: %d\n", V.GetSize());
	Sleep(10000);
	/*
	printf("\n|10제거|");
	V.RemoveAll(10);

	printf("\n\n%d", V.operator[](0)._id);
	printf("\n%d", V.operator[](1)._id);
	printf("\n%d", V.operator[](2)._id);
	printf("\n%d", V.operator[](3)._id);
	printf("\n현재 총 용량 : %d\n", V.GetCapacity());
	printf("현재 할당된 용량: %d\n", V.GetSize());*/
	//	V.GroupById(0);


	system("PAUSE");

	return 0;
}