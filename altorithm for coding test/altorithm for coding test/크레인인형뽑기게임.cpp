#include <iostream>
#include <string>
#include <vector>
#include<map>
using namespace std;

//list 스택으로풀어보기
int solution(vector<vector<int>> board, vector<int> moves) {
	int answer = 0;
	vector<int> v;
	vector <int> tmp;	//list.. d.d.dㅇ.ㅇ.ㅇ.
	map<int, int> table;
	int cnt{ 0 };	//101 , 102 , 103, 104,, 105 위치값 .
	
	for (int i = 0; i <board.size(); ++i) {	//거꾸로 넣는다. 그래야 편함.. 
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
	
		table[(moves[i] + 100)] -= 1; //101,102,103,104,105 위치도 한칸씩 땡겨줘야함.

		if (0 < v[(table[(moves[i] + 100)])] && 101 > v[(table[(moves[i] + 100)])]) {
			tmp.push_back(v[(table[(moves[i] + 100)])]);
		}
	
	}
	
	//4 3  3 2 4	확인

	//여기에서 오류나는것같음.
	
		//,ㅇㅇ,ㅇ,ㅇ,ㅇ,ㅇ,ㅇ,ㅇ,ㅇ
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

//앞에서 지우는것과 뒤에서 지우는 것의 차이 : 맨 뒤에꺼 지우면 동적할당을 지우는게 아님.
