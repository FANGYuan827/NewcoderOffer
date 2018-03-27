/*
2018年3月6日08:57:47
将一个字符串转换成一个整数，要求不能使用字符串转换整数的库函数。
数值为0或者字符串不是一个合法的数值则返回0
输入描述：
输入一个字符串,包括数字字母符号,可以为空.
输出描述:
如果是合法的数值表达则返回该数字，否则返回0.
*/

#include "iostream"
#include <vector>
#include <string>
using namespace std;

class Solution_demo47 {
public:
    int StrToInt(string str) {
		if(str.size()<1)
			return 0;
		vector<int>v_tmp;
		int res = 0;
		int i = 0;
		int flag = 1;
		if(str[0]=='-')
		{
			flag = -1;
			++i;
		}
		if(str[0]=='+')
		{
			flag = 1;
			++i;
		}
		for(;i<str.size();i++)
		{
			if(str[i]>='0'&&str[i]<='9')
			{
				v_tmp.push_back((int)str[i]-48);
				continue;
			}
			else
				return 0;
			
		}
		for(int i =0;i<v_tmp.size();i++)
		{
			res += v_tmp[i]*POW_10(10,v_tmp.size()-i-1);
		}
		if((res<=2147483647&&res>0)||(res<=2147483648&&flag==-1))
			return res*flag;
		else
			return 0;
    }
private:
	int POW_10(int x,int y)
	{
		int res = 1;
		for(int i=0;i<y;i++)
		{
			res *=10; 
		}
		return res;
	}
};

void main_demo47()
{

	Solution_demo47 s1;
	int res = 0;
	res = s1.StrToInt("0000001113");
	cout<<"转换的结果为："<<res<<endl;
	system("pause");
}