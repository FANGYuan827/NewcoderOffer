/*
2017��12��4��10:26:25��
����һ��double���͵ĸ�����base��int���͵�����exponent����base��exponent�η���
*/

#include "iostream"
using namespace std;

class Solution {
public:
	double Power(double base, int exponent) {
		if(base == 0)
		{
			//throw new RuntimeException("��ĸ����Ϊ0"); 
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
				while(exponent)       //����exponent������....
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
				while(tmp)       //����exponent������....
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
	cout<<"������Ϊ:"<<s1.Power(2,-1)<<endl;
	system("pause");
}

/*
���ϴ���Ĵ��룺
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
				while(exponent)       //����exponent������....
				{
					power *=base;
					--exponent;
				}
				break;
			}
		case 0:
			{
				int tmp = -exponent;
				while(tmp)       //����exponent������....
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