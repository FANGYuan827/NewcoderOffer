/*
2017年11月28日20:35:42：
大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项。
n<=39
*/

#include "iostream"
using namespace std;

class Solution {
public:
	int Fibonacci(int n) {
		if(n<=0||n>39)
		{
			return 0;
		}

		int count = 0;
		int value0 = 1;
		int value1 = 1;
		int i = 0;
		if(n<=2)
		{
			return 1;
		}
		for(i=2;i<n;i++)
		{
			count = value0+value1;
			value0 = value1;
			value1 = count;
		}
		return count;
	}
};

void main_demo06()
{
	Solution s1;
	cout<<"值为："<<s1.Fibonacci(39)<<endl;;


	system("pause");
}
/*

//一开始用递归来做  效率太低了 算法复杂度太高......
if(n==1||n==2)
{
return 1;
}
else
return Fibonacci(n-1)+Fibonacci(n-2);
*/
