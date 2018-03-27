/*
2018��3��5��13:39:22
�����������һ����λָ�����ѭ�����ƣ�ROL���������и��򵥵����񣬾������ַ���ģ�����ָ�����������
����һ���������ַ�����S���������ѭ������Kλ������������
���磬�ַ�����S=��abcXYZdef��,Ҫ�����ѭ������3λ��Ľ��������XYZdefabc����
�ǲ��Ǻܼ򵥣�OK���㶨����
*/

#include "iostream"
#include "string"
#include <queue>
using namespace std;



class Solution_demo43 {
public:
    string LeftRotateString_1(string str, int n) {              //ʹ�����ÿ�����Լ���ķ������ķ���
		if(str.size()<=1||n<1)
		{
			return str;
		}
		string str1;
		string str2;
		str1 = str.substr(0,n);          // @pos -- @length
		str2 = str.substr(n,str.size()-n);
		return str2+str1;
    }

/*
���ϴ���˼·��
���ݲ���n���ַ�������Ϊ�����ִ� �ֱ�������ִ�������ת ����ڶ������ַ���������ת
��Ϊ����
*/
	string LeftRotateString(string str, int n) {
		if(str.size()<=1||n<1)
		{
			return str;
		}
		n %= str.size();
		Reverse(str,0,n-1);
		Reverse(str,n,str.size()-1);
		Reverse(str,0,str.size()-1);
		return str;

	}
private:
	void Reverse(string &str,int start,int end)     //&s ����������һ������
	{
		if(str.size()<=0||start>end)
		{
			cout<<"the parameter is error"<<endl;
			return;
		}
		while(start<end)
		{
			char tmp = str[start];
			str[start] = str[end];
			str[end] = tmp;
			start++;
			end--;
		}
	}
};


void main_demo43()
{
	Solution_demo43 s1;
	string str = "abcXYZdef";
	string str_res = s1.LeftRotateString(str,12);
	cout<<"��ת֮������ַ���Ϊ��"<<str_res<<endl;
	system("pause");
}