/*
2017��11��28��20:35:42��
��Ҷ�֪��쳲��������У�����Ҫ������һ������n���������쳲��������еĵ�n�
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
	cout<<"ֵΪ��"<<s1.Fibonacci(39)<<endl;;


	system("pause");
}
/*

//һ��ʼ�õݹ�����  Ч��̫���� �㷨���Ӷ�̫��......
if(n==1||n==2)
{
return 1;
}
else
return Fibonacci(n-1)+Fibonacci(n-2);
*/
