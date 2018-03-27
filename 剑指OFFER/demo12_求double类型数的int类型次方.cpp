/*
2017年12月4日10:26:25：
给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。
*/

#include "iostream"
using namespace std;

class Solution {
public:
	double Power(double base, int exponent) {
		if(base == 0)
		{
			//throw new RuntimeException("分母不能为0"); 
			return (double)0;
		}
		if(exponent==0&&base!=0)
		{
			return (double)1;
		}
		double power = 1.0;
		switch(exponent>0)
		{
		case 1:
			{
				while(exponent)       //考虑exponent的正负....
				{
					power *=base;
					--exponent;
				}
				return power;
				break;
			}
		case 0:
			{
				int tmp = -exponent;
				while(tmp)       //考虑exponent的正负....
				{
					power *=base;
					--tmp;
				}
				return (double)(1/power);
				break;
			}
		}
	}
};



void main_demo12()
{
	Solution s1; 
	cout<<"运算结果为:"<<s1.Power(2,-1)<<endl;
	system("pause");
}

/*
网上大神的代码：
while(exponent!=0)
{
	if((exponent&1)==1)
		res*=curr;
	curr*=curr;
	exponent>>=1;
}
return n>0?res:(1/res);

*/

/*
C/C++(clang++ 3.9)

class Solution {
public:
    double Power(double base, int exponent) {
        if(base == 0)
		{
			return (double)0;
		}
		if(exponent==0&&base!=0)
		{
			return (double)1;
		}
		double power = 1.0;
        bool flag = exponent>0;
		switch(flag)
		{
		case 1:
			{
				while(exponent)       //考虑exponent的正负....
				{
					power *=base;
					--exponent;
				}
				break;
			}
		case 0:
			{
				int tmp = -exponent;
				while(tmp)       //考虑exponent的正负....
				{
					power *=base;
					--tmp;
				}
				break;
			}
		}
        if(flag)
        {
            return power;
        }
        else
        {
            return (double)(1/power);
        }
    }
};

*/