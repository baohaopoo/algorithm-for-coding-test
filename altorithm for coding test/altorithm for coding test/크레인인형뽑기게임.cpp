#include <iostream>
#include <string>
#include <vector>
#include<map>
using namespace std;

//list ��������Ǯ���
int solution(vector<vector<int>> board, vector<int> moves) {
	int answer = 0;
	vector<int> v;
	vector <int> tmp;	//list.. d.d.d��.��.��.
	map<int, int> table;
	int cnt{ 0 };	//101 , 102 , 103, 104,, 105 ��ġ�� .
	
	for (int i = 0; i <board.size(); ++i) {	//�Ųٷ� �ִ´�. �׷��� ����.. 
		for (int j = board.size()-1 ; j>0; --j) {
		
			if (0 != board[j][i]) {
				
				v.push_back(board[j][i]);
				++cnt;
			}
		}
		
		v.push_back(101+i);
		++cnt;
		table[101 + i] =cnt-1 ;
	}

	for (int i = 0; i < moves.size(); ++i)
	{
	
		table[(moves[i] + 100)] -= 1; //101,102,103,104,105 ��ġ�� ��ĭ�� ���������.

		if (0 < v[(table[(moves[i] + 100)])] && 101 > v[(table[(moves[i] + 100)])]) {
			tmp.push_back(v[(table[(moves[i] + 100)])]);
		}
	
	}
	
	//4 3  3 2 4	Ȯ��

	//���⿡�� �������°Ͱ���.
	
		//,����,��,��,��,��,��,��,��
		for (int i = 0; i < tmp.size(); ++i) {
			
			if (tmp[i] == tmp[i + 1]) {
				answer += 2;
				tmp.erase(tmp.begin() + i-1,tmp.begin()+i+1); 
			}
			
		}
	
	cout << answer << endl;

return answer;
}
int main()
{
	vector<vector<int>> board = { {0,0,0,0,0} ,{0,0,1,0,3},{0,2,5,0,1}, {4, 2, 4, 4, 2},{3, 5, 1, 3, 1} };
	vector<int>moves = { 1,5,3,5,1,2,1,4 };
	solution(board, moves);
}

//�տ��� ����°Ͱ� �ڿ��� ����� ���� ���� : �� �ڿ��� ����� �����Ҵ��� ����°� �ƴ�.
