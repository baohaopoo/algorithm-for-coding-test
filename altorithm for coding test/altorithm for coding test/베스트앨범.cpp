#include<iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
	vector<int> answer;

	unordered_multimap<vector<string>, vector<int>> um;

	for (int i = 0; i < genres.size(); ++i) {

		if (um.find(genres[i]) == um.end()) {

			um.insert(make_pair(genres[i], plays[i]));
		}

	}
		


	for (auto& c : um)
		cout << c.first << c.second << endl;
	return answer;
}

int main()
{
	vector<string> genres{ "classic", "pop", "classic", "classic", "pop" };
	vector<int> plays{ 500, 600, 150, 800, 2500 };
	solution(genres, plays);
}