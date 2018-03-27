/*
2017年11月22日19:26:50：
求1+2+3+...+n，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）;
*/

#include "iostream"
using namespace std;


class Solution {
public:
    int Sum_Solution(int n) {
		/*
		int sum1 = 0;
		int value = 1+n;
		int count = 0;
		sum1 += value<<6;
		sum1 += value<<5;
		sum1 += value<<2;
		//sum1 += value<<1;
		*/
		int value = n;
		n && (value+=Sum_Solution(n-1));     //会在这里把所要的结果计算出来
		return value;                      //最后通过return 语句将最后的答案甩出来。
		
        
    }
};



void main_demo04()
{
	Solution s1;
	int sum = 0;
	sum = s1.Sum_Solution(100);
	printf("所求和为：sum = %d\n",sum);
	system("pause");
}