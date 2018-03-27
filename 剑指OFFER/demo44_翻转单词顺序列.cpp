/*
2018年3月5日14:59:03
牛客最近来了一个新员工Fish，每天早晨总是会拿着一本英文杂志，写些句子在本子上。
同事Cat对Fish写的内容颇感兴趣，有一天他向Fish借来翻看，但却读不懂它的意思。
例如，“student. a am I”。
后来才意识到，这家伙原来把句子单词的顺序翻转了，正确的句子应该是“I am a student.”。
Cat对一一的翻转这些单词顺序可不在行，你能帮助他么？
*/
#include "iostream"
#include "string"
#include <list>
using namespace std;

class Solution_demo44 {
public:
    string ReverseSentence(string str) {
		string str_res;
		if(str.size()<1)
			return NULL;
		int length = str.size();
		int i = 0;
		int j = 0;
		list<string>l_res;
		for(i=0;i<length;i++)
		{
			if(str[i]==' ')
			{
				l_res.push_back(str.substr(j,i-j));
				j = i+1;
			}
		}
		l_res.push_back(str.substr(j,i-j));
		l_res.reverse();
		list<string>::iterator it;
		for(it = l_res.begin();it!=l_res.end();it++)
		{
			str_res += *it;
			str_res += ' ';
		}
		return str_res.substr(0,str_res.size()-1);
    }
};


void main_demo44()
{
	Solution_demo44 s1;
	string s_input = "student. a am I";
	string s_output = s1.ReverseSentence(s_input);
	cout<<"翻转之后的结果为："<<s_output<<endl;
	system("pause");
}