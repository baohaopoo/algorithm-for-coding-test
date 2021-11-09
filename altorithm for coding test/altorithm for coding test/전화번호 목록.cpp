
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

bool solution(vector<string> phone_book) {
	bool answer = true;
	string tmp;
	for (auto& c : phone_book)cout << c << endl;
	cout << "-------------------------------------------------" << endl;
	sort(phone_book.begin(), phone_book.end());
	for (auto& c : phone_book)cout << c << endl;
	cout << "-------------------------------------------------" << endl;
	for (int i = 0; i < phone_book.size(); ++i) {


		if (phone_book[i] == phone_book[i + 1].substr(0, phone_book[i].size()))
			return false;

	}

	return true;
}
int main()
{
	/*vector<string> p = { "77", "123", "1235", "567", "88"};

	solution(p);*/

	int		iInput = 0, iSum = 0;

	do 
	{
		cin >> iInput;

			if (0 != (iInput % 2))
				continue;

			iSum += iInput;

		} while (-1 != iInput);
		cout << "ÃÖÁ¾ ÇÕ: " << iSum << endl;
}