#include<iostream>
#include <string>
#include <vector>
#include<unordered_map>
using namespace std;

int solution(string s) {
	int answer = 0;
	unordered_map<string, string>  umap; //unordered map 을 string,string 인자로 만든다.  
	
	//글자수가 3인것과 5인것이 3개씩이고 4인것이 4개임으로 else를 4로 두기로 결정.
	//앞글자 3개까지 같은것이 하나도 없음으로 일괄적으로 3까지만 비교하기로 결정.

	umap.insert(make_pair("zer", "0")); //4
	umap.insert(make_pair("one", "1"));	//3
	umap.insert(make_pair("two", "2"));	//3
	umap.insert(make_pair("thr", "3"));	//5
	umap.insert(make_pair("fou", "4")); //4
	umap.insert(make_pair("fiv", "5"));	//4
	umap.insert(make_pair("six", "6"));	//3
	umap.insert(make_pair("sev", "7"));	//5
	umap.insert(make_pair("eig", "8"));	//5
	umap.insert(make_pair("nin", "9"));	//4

	for (int i = 0; i < s.size(); ++i) {

		if (isdigit(s.at(i)) == 0) {// isdigit 함수는 문자를 발견하면 false를 return 하기에 조건문 이런식으로 세움. 

			string tmp = s.substr(i, 3);	//tmp에 substr함수로 3까지만 따로 할당해놓음.

			if (umap.find(tmp) != umap.end()) {	//umap안에서 key가 tmp인 것이 존재한다면 이라는 뜻. 존재하지 않다면 하고 싶으면 ==으로 하면됨.
				if(tmp == "one" || tmp == "two" || tmp == "six")	
					s.replace(i, 3, umap[tmp]); //글자수가 3개인 애들만 해당됨.
				else if (tmp == "thr" || tmp == "sev" || tmp == "eig") //글자수가 5개인 애들만 해당됨.
					s.replace(i, 5, umap[tmp]);
				else
					s.replace(i, 4, umap[tmp]); //글자수가 4개인 애들만 해당됨.
			 }
		}

	}

	answer = stoi(s); //string 타입 s를 int형으로 바꿔줌. atoi
	return answer;
}

int main()
{
	string s = "one4seveneight";
	solution(s);

}