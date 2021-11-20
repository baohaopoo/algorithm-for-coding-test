#include<iostream>
#include <string>
#include <vector>
#include<unordered_map>
using namespace std;

int solution(string s) {
	int answer = 0;
	unordered_map<string, string>  umap; //unordered map �� string,string ���ڷ� �����.  
	
	//���ڼ��� 3�ΰͰ� 5�ΰ��� 3�����̰� 4�ΰ��� 4�������� else�� 4�� �α�� ����.
	//�ձ��� 3������ �������� �ϳ��� �������� �ϰ������� 3������ ���ϱ�� ����.

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

		if (isdigit(s.at(i)) == 0) {// isdigit �Լ��� ���ڸ� �߰��ϸ� false�� return �ϱ⿡ ���ǹ� �̷������� ����. 

			string tmp = s.substr(i, 3);	//tmp�� substr�Լ��� 3������ ���� �Ҵ��س���.

			if (umap.find(tmp) != umap.end()) {	//umap�ȿ��� key�� tmp�� ���� �����Ѵٸ� �̶�� ��. �������� �ʴٸ� �ϰ� ������ ==���� �ϸ��.
				if(tmp == "one" || tmp == "two" || tmp == "six")	
					s.replace(i, 3, umap[tmp]); //���ڼ��� 3���� �ֵ鸸 �ش��.
				else if (tmp == "thr" || tmp == "sev" || tmp == "eig") //���ڼ��� 5���� �ֵ鸸 �ش��.
					s.replace(i, 5, umap[tmp]);
				else
					s.replace(i, 4, umap[tmp]); //���ڼ��� 4���� �ֵ鸸 �ش��.
			 }
		}

	}

	answer = stoi(s); //string Ÿ�� s�� int������ �ٲ���. atoi
	return answer;
}

int main()
{
	string s = "one4seveneight";
	solution(s);

}