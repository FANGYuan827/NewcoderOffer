/*
2017年12月21日10:22:47
一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法。
*/
#include "iostream"
using namespace std;


/*
解题思路：
链接：https://www.nowcoder.com/questionTerminal/8c82a5b80378478f9484d87d1c5f12a4
来源：牛客网

对于本题,前提只有 一次 1阶或者2阶的跳法。

a.如果两种跳法，1阶或者2阶，那么假定第一次跳的是一阶，那么剩下的是n-1个台阶，跳法是f(n-1);

b.假定第一次跳的是2阶，那么剩下的是n-2个台阶，跳法是f(n-2)

c.由a\b假设可以得出总跳法为: f(n) = f(n-1) + f(n-2) 

d.然后通过实际的情况可以得出：只有一阶的时候 f(1) = 1 ,只有两阶的时候可以有 f(2) = 2

e.可以发现最终得出的是一个斐波那契数列：
              | 1, (n=1)

f(n) =     | 2, (n=2)

              | f(n-1)+f(n-2) ,(n>2,n为整数)
*/
class Solution {
public:
    int jumpFloor(int number) {
		if(number<1)
		{
			return 0;
		}
		if(number==1)
		{
			return 1;
		}
		if(number==2)
		{
			return 2;
		}
		int num_tmp = number;
		int total = 0,count=0;
		//total = 2 + jumpFloor(number-1) + jumpFloor(number-2);
		total = jumpFloor(number -1)+jumpFloor(number-2);
		return total;
        
    }
};

class Solution_1 {
public:
    int jumpFloor(int number) {
		if(number<1)
		{
			return 0;
		}
		if(number==1)
		{
			return 1;
		}
		int count1 = 1;
		int count2 = 1;
		int count3 = 0;
		while(number>1)
		{
			count3 = count1+count2;
		    count1 = count2;
			count2 = count3;
	        number--;
		}
		return count3;
    }
};

void main_demo21()
{
	Solution_1 s1;
	int res = 0;
	res =  s1.jumpFloor(4);
	printf("一共有%d种跳法\n",res);


	system("pause");
}