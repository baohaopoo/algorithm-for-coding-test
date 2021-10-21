#include<iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
	string answer = "";


	map <string, int> pmap;

	for (auto& p : participant) {

		if (pmap.end() == pmap.find(p)) {
			//pmap �� p���Ұ� ������
			pmap.insert(make_pair(p, 1));
		}
		else {
			//������ ������ �÷��ش�.
			pmap[p] += 1;
		}

	}

	for (auto& c : completion) {

		if (pmap.end() != pmap.find(c)) {
			pmap[c] -= 1;
		}
	}

	for (auto& p : pmap) {
		if (p.second > 0)
			answer = p.first;

	}

	return answer;
}

int main()
{
	vector<string> p = { "mimi","dodo","sunny","sunny" };
	vector<string> c = { "mimi","dodo","sunny" };
	solution(p, c);

}