#include <iostream>

using namespace std;

void info();
void vending (int, int);

int		iCoin = 0, iSelect = 0;
bool	bCheck = true;

void main()
{ 
	cout << "������: ";
	cin >> iCoin;

	while (bCheck)
	{
		system("cls");
		cout << "������: " << iCoin << endl;
		info();
		cout << "�Է�: ";
		cin >> iSelect;

		vending(iSelect,iCoin);
		system("pause");
	}

	system("cls");
	cout << "�Ž��� ���� " << iCoin << "�� �Դϴ�." << endl;
}

void info()
{
	cout << "===================================================" << endl;
	cout << "1.�ݶ�(100��) 2.���̴�(200��) 3.ȯŸ(300��) 4.��ȯ" << endl;
	cout << "===================================================" << endl;
}

void vending(int iSelect, int iCoin)
{
	switch (iSelect)
	{
	case 1:
		if (100 <= iCoin)
		{
			cout << "�ݶ� ���� �Ϸ�!" << endl;
			iCoin -= 100;
		}
		else
			cout << "������ ����!" << endl;
		break;
	case 2:
		if (200 <= iCoin)
		{
			cout << "���̴� ���� �Ϸ�!" << endl;
			iCoin -= 200;
		}
		else
			cout << "������ ����!" << endl;
		break;
	case 3:
		if (300 <= iCoin)
		{
			cout << "ȯŸ ���� �Ϸ�!" << endl;
			iCoin -= 300;
		}
		else
			cout << "������ ����!" << endl;
		break;
	case 4:
		bCheck = false;
		continue;
	default:
		continue;
	}

}

