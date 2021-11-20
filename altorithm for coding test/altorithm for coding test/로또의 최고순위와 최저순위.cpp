#include<iostream>
#include <string>
#include <vector>
#include<map>
using namespace std;

int res(int&);
vector<int> solution(vector<int> lottos, vector<int> win_nums) {

	vector<int> answer;

	map<int, int> wmap;

	int max{ 0 }, min{ 0 };

	for (auto& w : win_nums)
		wmap.insert(make_pair(w, 0));


	for (int i = 0; i < lottos.size(); ++i) {
		if (lottos[i] == 0)
			++max;

		if (wmap.find(lottos[i]) != wmap.end())
			++min;

	}

	max += min;

	answer.emplace_back(res(max));
	answer.emplace_back(res(min));

	return answer;
}

int res(int& v)
{
	switch (v)
	{
	case 6:return 1; break;
	case 5:return 2; break;
	case 4:return 3; break;
	case 3:return 4; break;
	case 2:return 5; break;
	default: return 6; break;
	}

}