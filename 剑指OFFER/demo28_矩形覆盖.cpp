/*
2018年1月18日10:15:15
我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。
请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？
*/

#include "iostream"
using namespace std;

class Solution {
public:
    int rectCover(int number) {
		if(number<=0)
		{
			return 0;
		}
		if(number == 1)
		{
			return 1;
		}
		if(number == 2)
		{
			return 2;
		}
		int total = 0;
		int num_tmp = number;
		int first = 1 ,second = 1;
		while(num_tmp>1)         //非递归实现：利用while()循环实现
		{
			total = first +second;
			first = second;
			second = total;
			num_tmp--;
		}
		return total;

    }
	int  rectCover_1(int number);   //声明放在类内 函数实现放在类外
};
int Solution::rectCover_1(int number)
{
	if(number <= 0)
	{
		return 0;
	}
	if(number == 1)
	{
		return 1;
	}
	if(number == 2)
	{
		return 2;
	}
	int total = 0;
	int num_tmp = number;

	total = rectCover_1(num_tmp-1)+rectCover_1(num_tmp-2);   //递归实现  不需要循环 递归调用 函数依次入栈 执行完毕之后 按照规则依次弹出栈

	return total;

}


void main_demo28()
{
	Solution s1;
	int res = s1.rectCover(3);
	int res_1 = s1.rectCover_1(3);
	printf("总共有res:%d种覆盖方法\n",res);
	printf("总共有res_1:%d种覆盖方法\n",res_1);
	system("pause");
}