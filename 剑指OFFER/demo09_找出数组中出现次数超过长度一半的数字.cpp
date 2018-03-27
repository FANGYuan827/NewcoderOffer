
/*
2017年11月30日22:06:49：
数组中有一个数字出现的次数超过数组长度的一半，
请找出这个数字。例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。
由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。
如果不存在则输出0。
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
		for(int i=0;i<length;i++)       //一开始结果总是不对  是因为遍历的长度搞错了  是length 不是length-1.....
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