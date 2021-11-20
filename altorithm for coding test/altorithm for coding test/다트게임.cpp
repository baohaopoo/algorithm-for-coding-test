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

				if (((tmp[i - 1]) - 48) != 0) {	//앞의 숫자가 10이하 일 경우

					value = pow(((tmp[i - 1]) - 48), 1);

					partvalue.insert(make_pair(i, value));
				}
				else if (((tmp[i - 1]) - 48) == 0) {	//앞의 숫자가 10일 경우
					if (((tmp[i - 2]) - 48) == 1) {
						value = 10;


						partvalue.insert(make_pair(i, value));
					}
					else {
						//0인 경우
						partvalue.insert(make_pair(i, 0));
					}

				}
				break;

			case 'D':

				if (((tmp[i - 1]) - 48) != 0) {	//앞의 숫자가 10이하 일 경우
					value = pow(((tmp[i - 1]) - 48), 2);

					partvalue.insert(make_pair(i, value));
				}
				else if (((tmp[i - 1]) - 48) == 0) {	//앞의 숫자가 10일 경우
					if (((tmp[i - 2]) - 48) == 1) {
						value = 100;

						partvalue.insert(make_pair(i, value));
					}
					else {
						//찐 0일경우
						partvalue.insert(make_pair(i, 0));
					}
				}
				break;
			case 'T':

				if (((tmp[i - 1]) - 48) != 0) {	//앞의 숫자가 10이하 일 경우
					value = pow(((tmp[i - 1]) - 48), 3);

					partvalue.insert(make_pair(i, value));
				}
				else if (((tmp[i - 1]) - 48) == 0) {	//앞의 숫자가 10일 경우

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
					//전거랑 이전꺼만 캐치하기 위해 .. i 에서 하나씩 줄다가 i
					if (partvalue.end() != partvalue.find(j)) {	//찾으면.
						cnt++;
						if (cnt <= 2) {

							partvalue.find(j)->second *= 2;

						}
					}

				}



				break;
			case '#':


				//바로 직전것을 뽑아야함.
				int check;
				for (auto& m : partvalue) {
					check = 0;
					if (m.first < i) {	//마지막에 나오는 체크를 뽑기위한 과정.
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