
/*
2017��11��30��22:06:49��
��������һ�����ֳ��ֵĴ����������鳤�ȵ�һ�룬
���ҳ�������֡���������һ������Ϊ9������{1,2,3,2,2,2,5,4,2}��
��������2�������г�����5�Σ��������鳤�ȵ�һ�룬������2��
��������������0��
*/
#include "iostream"
#include "vector"
using namespace std;


class Solution 
{
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) 
	{
		int length = numbers.size();
		vector<int>CountNum(length);
		for(int i=0;i<length;i++)       //һ��ʼ������ǲ���  ����Ϊ�����ĳ��ȸ����  ��length ����length-1.....
		{
			CountNum[numbers[i]-1]++;
		}
		//int length2 = CountNum.size();
		for(int i=0;i<length;i++)
		{
			if(CountNum[i]>length/2)
				return  i+1;
		}
		return 0;
	}
};



void main_demo09()
{
	Solution s1;
	vector<int>v1(9);
	v1[0] = 1;
	v1[1] = 2;
	v1[2] = 3;
	v1[3] = 2;
	v1[4] = 2;
	v1[5] = 2;
	v1[6] = 5;
	v1[7] = 4;
	v1[8] = 2;
	int result=0;
	result=s1.MoreThanHalfNum_Solution(v1);
	cout<<result<<endl;

	system("pause");

}