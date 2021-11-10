#include<iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include<algorithm>
using namespace std;

bool solution(vector<string> phone_book) {

	sort(phone_book.begin(), phone_book.end(), [](string s1, string s2) {return s1.length() < s2.length(); });
	unordered_map<string, int> pmap;

	bool answer = true;

	for (auto& p : phone_book) {

		pmap[p] = 1;
	}


	for (auto& p : pmap) {


		if (pmap.count(p.first) > 1) {
			if (p.first.length() == p.second) {

				answer = false;
			}
		}

	}



	return answer;
}
int main()
{

	vector<string> p = { "119", "114", "112", "123223123", "1231231234" };
	vector<string> pp = { "934793", "34", "44", "9347" };
	vector<string> ppp = { "119", "97674223", "1195524421" };
	solution(pp);

}