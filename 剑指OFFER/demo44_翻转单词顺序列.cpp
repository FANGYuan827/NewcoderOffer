/*
2018��3��5��14:59:03
ţ���������һ����Ա��Fish��ÿ���糿���ǻ�����һ��Ӣ����־��дЩ�����ڱ����ϡ�
ͬ��Cat��Fishд�������ĸ���Ȥ����һ������Fish������������ȴ������������˼��
���磬��student. a am I����
��������ʶ������һ�ԭ���Ѿ��ӵ��ʵ�˳��ת�ˣ���ȷ�ľ���Ӧ���ǡ�I am a student.����
Cat��һһ�ķ�ת��Щ����˳��ɲ����У����ܰ�����ô��
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
	cout<<"��ת֮��Ľ��Ϊ��"<<s_output<<endl;
	system("pause");
}