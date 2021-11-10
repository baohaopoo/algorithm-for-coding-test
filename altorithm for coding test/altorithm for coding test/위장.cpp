#include<iostream>
#include <string>
#include <vector>
#include<unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
	int answer = 0;
	unordered_map<string, int> cmap;

	for (int i = 0; i < clothes.size(); ++i) {
		if (cmap.find(clothes[i][1]) == cmap.end()) //맵에 해당 종류가 없다면
		{
			cmap[clothes[i][1]] = 1;
		}
		else { //있으면 value값 추가.
			cmap[clothes[i][1]] += 1;
		}
		

	}

	for (auto& c : cmap) {
		
		answer*=c.second+1;
		
	}

	
	return answer-1;
}

int main()
{

	vector<vector<string>> clothes = { { "crowmask", "face" }, { "bluesunglasses", "face" }, { "smoky_makeup", "face" } };
	solution(clothes);

}