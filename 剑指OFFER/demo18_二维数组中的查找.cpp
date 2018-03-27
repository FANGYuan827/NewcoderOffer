/*
2017年12月8日20:09:27：
在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
*/

#include "iostream"
#include "vector"
using namespace std;
#define False 0
#define True 1


/*遍历的思想 时间复杂度O(n*n)*/
class Solution_my {
public:
    bool Find(int target, vector<vector<int> > myArray) {
		if(myArray.size()==0)
		{
			return False;
		}
		int length1 = myArray.size();
		int length2 = myArray[0].size();
		for(int i = 0;i<length1;i++)
			for(int j =0;j<length2;j++)
			{
				if(myArray[i][j]==target)
				{
					return True;
				}
			}
       return False;
	}

};
/* 思路
* 矩阵是有序的，从左下角来看，向上数字递减，向右数字递增，
* 因此从左下角开始查找，当要查找数字比左下角数字大时。右移
* 要查找数字比左下角数字小时，上移
*/

class Solution {
public:
    bool Find(int target, vector<vector<int> > myArray) {
		if(myArray.size()==0)
		{
			return False;
		}
		int length1 = myArray.size();      //求出矩阵的行数
		int length2 = myArray[0].size();  //求出矩阵的列数
		int i = length1-1;
		int j = 0;
		while(j<length2&&i>=0)
		{
			if(myArray[i][j]<target)
			{
				j++;
			}
			else
			{
				if(myArray[i][j]>target)
				{
					i--;
				}
				else
				{
					return true;
				}
			}
			/*
			if(j==length2||i<0)
			{
				break;
			}
			*/
		}
		return false;
	}

};
void main_demo18()
{
	//Solution_my s1;
	Solution s1;
	int result = 0;
	int Target = 0;
	printf("请输入要查找的数\n");
	scanf("%d",&Target);
	vector<vector<int>> myArray(4,5);
	int i = 0,j = 0;
	for(i=0;i<4;i++)
	{
		for(j=0;j<5;j++)
		{
			myArray[i][j] =i+j; 
		}
	}
	result = s1.Find(Target,myArray);    //
	if(result!=0)
	{
		printf("存在数:%d\n",Target);
	}
	else
	{
		printf("不存在数:%d\n",Target);
	}
	printf("行数:%d 列数:%d\n",myArray.size(),myArray[0].size());
	for(i=0;i<4;i++)
	{
		for(j=0;j<5;j++)
		{
			printf("%d ",myArray[i][j]);
		}
		printf("\n");
	}
	//printf("\n");

	system("pause");
}