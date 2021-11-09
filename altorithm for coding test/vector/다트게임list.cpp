#include<iostream>
#include<vector>
#include <string>
#include<cmath>
#include<algorithm>
#include<map>
using namespace std;

int solution(string dartResult) {
	int answer = 0;
	vector<char> tmp;
	map<int, int> partvalue;

	for (const auto& d : dartResult) 	//string�� �������� �ɰ��� vector�� �� ���ҷ� �������.
		tmp.push_back(d);
	
	int value = 0;	//�ɰ��� char�� ���Ҹ� int������ ��� �ٲ㼭 �����ϰų� �ʿ� ������ ���� �뵵�� ����.

	for (int i = 0; i < tmp.size(); ++i) {
	
		if (tmp[i] == 'S' || tmp[i] == 'D' || tmp[i] == 'T' || tmp[i] == '*' || tmp[i] == '#') {
			switch (tmp[i])
			{
			case 'S':
			
				if (((tmp[i - 1]) - 48) != 0) {	//���� ���ڰ� 10���� �� ��쿡�� 0�� �ƴ� 1,2,3,4,5,6,7,8,9 �ϱ�.
				
					value = pow(((tmp[i - 1]) - 48), 1);	
					cout << "S��" << i << "��°�� �����մϴ�. 10������ ���̰� ��ȯ����" << value<< endl;
					partvalue.insert(make_pair(i, value));
				}
				else if (((tmp[i - 1]) - 48) == 0) {	//���� ���ڰ� 10�� ���� 0�� ��츦 ���� ������. 
					if (((tmp[i - 2]) - 48) == 1) { //10�� ���� �� ���� ���ڰ� 1�� ���̰�,
						value = 10;

						cout << "S��" << i << "��°�� �����մϴ�. 10�̰� ��ȯ����" << value << endl;
						partvalue.insert(make_pair(i, value));
					}
					else 
						partvalue.insert(make_pair(i, 0)); 	//0�� ���� �׳� 0�� ������ �־��ش�.
				}
				break;

			case 'D':
				
				if (((tmp[i - 1]) - 48) != 0) {	//���� ���ڰ� 10�� ���� 0�� ��츦 ���� ������. 
					value = pow(((tmp[i - 1]) - 48), 2);
					cout << "D��" << i << "��°�� �����մϴ�. 10������ ���̰� ��ȯ����" << value << endl;
					partvalue.insert(make_pair(i, value));
				}
				else if (((tmp[i - 1]) - 48) == 0) {	//���� ���ڰ� 10�� ���
					if (((tmp[i - 2]) - 48) == 1) {	// �� ���� ���ڰ� 1�� ���̰�,
						cout << "D��" << i << "��°�� �����մϴ�. 10�̰� ��ȯ����" << value << endl;
						partvalue.insert(make_pair(i, 100));//10�� �������� ����� �ٷ� ����..
					}
					else
						partvalue.insert(make_pair(i, 0));//�� 0�ϰ��
				}
				break;
			case 'T':
				
				if (((tmp[i - 1]) - 48) != 0) {	//���� ���ڰ� 10���� �� ���
					value = pow(((tmp[i - 1]) - 48), 3);
					cout << "T��" << i << "��°�� �����մϴ�. 10������ ���̰� ��ȯ����" << value << endl;
					partvalue.insert(make_pair(i, value));
				}
				else if (((tmp[i - 1]) - 48) == 0) {	//���� ���ڰ� 10�� ���

					if (((tmp[i - 2]) - 48) == 1) {	//10
						cout << "T��" << i << "��°�� �����մϴ�. 10�̰� ��ȯ����" << value << endl;
						partvalue.insert(make_pair(i, 1000)); //10�� 3���� �ٷλ���� ����.
					}
					else //0
						partvalue.insert(make_pair(i, 0));
				}
				break;
			case '*':
				cout << "*��" << i << "��°�� �����մϴ�." << endl;
				int cnt; cnt = 0;
				for (int j = i-1 ; j > 0; --j) {	//�ϴ� j�� i���� 1�̻� �����Ŵϱ�..
					//���Ŷ� �������� ĳġ�ϱ� ���� .. i ���� �ϳ��� �ٴٰ� i
					if (partvalue.end() != partvalue.find(j)) {	//ã����.
						cnt++;
						if (cnt <= 2) partvalue.find(j)->second *= 2;//*���� ��ġ���� ������ �����Ͱ�, �� ������ *2������.	
					}
				}
				break;
			case '#':

				cout << "#��" << i << "��°�� �����մϴ�." << endl;
				//�ٷ� �������� �̾ƾ���.
				int check;
				for (auto& m : partvalue) {
					 check = 0;
					if (m.first < i) {	//�������� ������ üũ�� �̱����� ����.
						if (check < m.first)
						check = m.first;
					}
				}partvalue[check] *= -1;
				break;
			default:
				continue;
			}
		}
	}
	cout << "------------------------------------------------------" << endl;
	cout << "partvalue ���� ���캸��." << endl;

	for (auto& m : partvalue)
	{
		cout <<"key: "<<m.first<< "    value: "<<m.second << endl;
		answer += m.second;
	}
	cout << "��:" << answer;
	return answer;

}
int main()
{
	solution("1S2D*3T");
}
