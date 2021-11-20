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

	for (const auto& d : dartResult) {
		tmp.push_back(d);
	}

	int value = 0;

	for (int i = 0; i < tmp.size(); ++i) {

		if (tmp[i] == 'S' || tmp[i] == 'D' || tmp[i] == 'T' || tmp[i] == '*' || tmp[i] == '#') {
			switch (tmp[i])
			{
			case 'S':

				if (((tmp[i - 1]) - 48) != 0) {	//���� ���ڰ� 10���� �� ���

					value = pow(((tmp[i - 1]) - 48), 1);

					partvalue.insert(make_pair(i, value));
				}
				else if (((tmp[i - 1]) - 48) == 0) {	//���� ���ڰ� 10�� ���
					if (((tmp[i - 2]) - 48) == 1) {
						value = 10;


						partvalue.insert(make_pair(i, value));
					}
					else {
						//0�� ���
						partvalue.insert(make_pair(i, 0));
					}

				}
				break;

			case 'D':

				if (((tmp[i - 1]) - 48) != 0) {	//���� ���ڰ� 10���� �� ���
					value = pow(((tmp[i - 1]) - 48), 2);

					partvalue.insert(make_pair(i, value));
				}
				else if (((tmp[i - 1]) - 48) == 0) {	//���� ���ڰ� 10�� ���
					if (((tmp[i - 2]) - 48) == 1) {
						value = 100;

						partvalue.insert(make_pair(i, value));
					}
					else {
						//�� 0�ϰ��
						partvalue.insert(make_pair(i, 0));
					}
				}
				break;
			case 'T':

				if (((tmp[i - 1]) - 48) != 0) {	//���� ���ڰ� 10���� �� ���
					value = pow(((tmp[i - 1]) - 48), 3);

					partvalue.insert(make_pair(i, value));
				}
				else if (((tmp[i - 1]) - 48) == 0) {	//���� ���ڰ� 10�� ���

					if (((tmp[i - 2]) - 48) == 1) {
						value = 1000;

						partvalue.insert(make_pair(i, value));
					}
					else
						partvalue.insert(make_pair(i, 0));
				}
				break;
			case '*':


				int cnt; cnt = 0;
				for (int j = i - 1; j > 0; --j) {
					//���Ŷ� �������� ĳġ�ϱ� ���� .. i ���� �ϳ��� �ٴٰ� i
					if (partvalue.end() != partvalue.find(j)) {	//ã����.
						cnt++;
						if (cnt <= 2) {

							partvalue.find(j)->second *= 2;

						}
					}

				}



				break;
			case '#':


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

	for (auto& m : partvalue)
	{



		answer += m.second;

	}


	return answer;
}