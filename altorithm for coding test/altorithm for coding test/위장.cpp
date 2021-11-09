#include <iostream>

using namespace std;

void info();
void vending (int, int);

int		iCoin = 0, iSelect = 0;
bool	bCheck = true;

void main()
{ 
	cout << "소지금: ";
	cin >> iCoin;

	while (bCheck)
	{
		system("cls");
		cout << "소지금: " << iCoin << endl;
		info();
		cout << "입력: ";
		cin >> iSelect;

		vending(iSelect,iCoin);
		system("pause");
	}

	system("cls");
	cout << "거스름 돈은 " << iCoin << "원 입니다." << endl;
}

void info()
{
	cout << "===================================================" << endl;
	cout << "1.콜라(100원) 2.사이다(200원) 3.환타(300원) 4.반환" << endl;
	cout << "===================================================" << endl;
}

void vending(int iSelect, int iCoin)
{
	switch (iSelect)
	{
	case 1:
		if (100 <= iCoin)
		{
			cout << "콜라 구매 완료!" << endl;
			iCoin -= 100;
		}
		else
			cout << "소지금 부족!" << endl;
		break;
	case 2:
		if (200 <= iCoin)
		{
			cout << "사이다 구매 완료!" << endl;
			iCoin -= 200;
		}
		else
			cout << "소지금 부족!" << endl;
		break;
	case 3:
		if (300 <= iCoin)
		{
			cout << "환타 구매 완료!" << endl;
			iCoin -= 300;
		}
		else
			cout << "소지금 부족!" << endl;
		break;
	case 4:
		bCheck = false;
		continue;
	default:
		continue;
	}

}

