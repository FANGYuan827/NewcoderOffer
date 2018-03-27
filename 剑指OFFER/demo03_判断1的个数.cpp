/*
2017年11月22日19:23:54
输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。
*/
#include "iostream"
using namespace std;


class Solution 
{
public:
	int  NumberOf1(int n)     //判断一个int整数中1的个数
	{
		int x = 0;
		while(n!=0)
		{
			n&=(n-1);
			++x;
		}
		return x;
	}
	int NumberOf0(int n)      //判断一个int整数中0的个数
	{
		int x = 0;
		while(n>=0)
		{
			n|=(n+1);
			++x;
		}
		return x;
	}
};

void main_demo03()
{
	Solution s1;
	int count = 0;
	count = s1.NumberOf1(2);
	printf("该整数中1的个数为:%d\n",count);
	count = s1.NumberOf0(1);
	printf("该整数中0的个数为:%d\n",count);
	system("pause");
}