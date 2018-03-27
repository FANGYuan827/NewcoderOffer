/*
2018年3月5日13:39:22
汇编语言中有一种移位指令叫做循环左移（ROL），现在有个简单的任务，就是用字符串模拟这个指令的运算结果。
对于一个给定的字符序列S，请你把其循环左移K位后的序列输出。
例如，字符序列S=”abcXYZdef”,要求输出循环左移3位后的结果，即“XYZdefabc”。
是不是很简单？OK，搞定它！
*/

#include "iostream"
#include "string"
#include <queue>
using namespace std;



class Solution_demo43 {
public:
    string LeftRotateString_1(string str, int n) {              //使用内置库的类以及类的方法求解的方法
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
网上大神思路：
根据参数n将字符串划分为两个字串 分别对两个字串进行旋转 最后在对整个字符串进行旋转
即为所得
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
	void Reverse(string &str,int start,int end)     //&s 参数传递是一个引用
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
	cout<<"旋转之后的新字符串为："<<str_res<<endl;
	system("pause");
}