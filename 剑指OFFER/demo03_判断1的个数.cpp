/*
2017��11��22��19:23:54
����һ��������������������Ʊ�ʾ��1�ĸ��������и����ò����ʾ��
*/
#include "iostream"
using namespace std;


class Solution 
{
public:
	int  NumberOf1(int n)     //�ж�һ��int������1�ĸ���
	{
		int x = 0;
		while(n!=0)
		{
			n&=(n-1);
			++x;
		}
		return x;
	}
	int NumberOf0(int n)      //�ж�һ��int������0�ĸ���
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
	printf("��������1�ĸ���Ϊ:%d\n",count);
	count = s1.NumberOf0(1);
	printf("��������0�ĸ���Ϊ:%d\n",count);
	system("pause");
}