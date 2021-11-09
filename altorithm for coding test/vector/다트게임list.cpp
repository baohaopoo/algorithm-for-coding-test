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

	for (const auto& d : dartResult) 	//string을 한음절씩 쪼개서 vector의 각 원소로 집어넣음.
		tmp.push_back(d);
	
	int value = 0;	//쪼개진 char형 원소를 int형으로 잠시 바꿔서 제곱하거나 맵에 넣을때 쓰는 용도의 변수.

	for (int i = 0; i < tmp.size(); ++i) {
	
		if (tmp[i] == 'S' || tmp[i] == 'D' || tmp[i] == 'T' || tmp[i] == '*' || tmp[i] == '#') {
			switch (tmp[i])
			{
			case 'S':
			
				if (((tmp[i - 1]) - 48) != 0) {	//앞의 숫자가 10이하 일 경우에는 0이 아닌 1,2,3,4,5,6,7,8,9 니까.
				
					value = pow(((tmp[i - 1]) - 48), 1);	
					cout << "S가" << i << "번째에 존재합니다. 10이하의 값이고 변환값은" << value<< endl;
					partvalue.insert(make_pair(i, value));
				}
				else if (((tmp[i - 1]) - 48) == 0) {	//앞의 숫자가 10일 경우와 0일 경우를 따로 빼야함. 
					if (((tmp[i - 2]) - 48) == 1) { //10일 경우는 그 앞의 숫자가 1일 것이고,
						value = 10;

						cout << "S가" << i << "번째에 존재합니다. 10이고 변환값은" << value << endl;
						partvalue.insert(make_pair(i, value));
					}
					else 
						partvalue.insert(make_pair(i, 0)); 	//0인 경우는 그냥 0을 값으로 넣어준다.
				}
				break;

			case 'D':
				
				if (((tmp[i - 1]) - 48) != 0) {	//앞의 숫자가 10일 경우와 0일 경우를 따로 빼야함. 
					value = pow(((tmp[i - 1]) - 48), 2);
					cout << "D가" << i << "번째에 존재합니다. 10이하의 값이고 변환값은" << value << endl;
					partvalue.insert(make_pair(i, value));
				}
				else if (((tmp[i - 1]) - 48) == 0) {	//앞의 숫자가 10일 경우
					if (((tmp[i - 2]) - 48) == 1) {	// 그 앞의 숫자가 1일 것이고,
						cout << "D가" << i << "번째에 존재합니다. 10이고 변환값은" << value << endl;
						partvalue.insert(make_pair(i, 100));//10의 제곱값을 상수로 바로 넣음..
					}
					else
						partvalue.insert(make_pair(i, 0));//찐 0일경우
				}
				break;
			case 'T':
				
				if (((tmp[i - 1]) - 48) != 0) {	//앞의 숫자가 10이하 일 경우
					value = pow(((tmp[i - 1]) - 48), 3);
					cout << "T가" << i << "번째에 존재합니다. 10이하의 값이고 변환값은" << value << endl;
					partvalue.insert(make_pair(i, value));
				}
				else if (((tmp[i - 1]) - 48) == 0) {	//앞의 숫자가 10일 경우

					if (((tmp[i - 2]) - 48) == 1) {	//10
						cout << "T가" << i << "번째에 존재합니다. 10이고 변환값은" << value << endl;
						partvalue.insert(make_pair(i, 1000)); //10의 3제곱 바로상수로 넣음.
					}
					else //0
						partvalue.insert(make_pair(i, 0));
				}
				break;
			case '*':
				cout << "*가" << i << "번째에 존재합니다." << endl;
				int cnt; cnt = 0;
				for (int j = i-1 ; j > 0; --j) {	//일단 j는 i보다 1이상 작을거니까..
					//전거랑 이전꺼만 캐치하기 위해 .. i 에서 하나씩 줄다가 i
					if (partvalue.end() != partvalue.find(j)) {	//찾으면.
						cnt++;
						if (cnt <= 2) partvalue.find(j)->second *= 2;//*보다 위치값이 작으면 이전것과, 그 전것을 *2해주자.	
					}
				}
				break;
			case '#':

				cout << "#가" << i << "번째에 존재합니다." << endl;
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
	cout << "------------------------------------------------------" << endl;
	cout << "partvalue 맵을 살펴보자." << endl;

	for (auto& m : partvalue)
	{
		cout <<"key: "<<m.first<< "    value: "<<m.second << endl;
		answer += m.second;
	}
	cout << "답:" << answer;
	return answer;

}
int main()
{
	solution("1S2D*3T");
}
