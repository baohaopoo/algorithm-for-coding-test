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
			//pmap 에 p원소가 없으면
			pmap.insert(make_pair(p, 1));
		}
		else {
			//있으면 갯수를 늘려준다.
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