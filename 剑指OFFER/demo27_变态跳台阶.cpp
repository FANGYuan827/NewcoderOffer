/*
2018年1月17日21:43:29
一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。
求该青蛙跳上一个n级的台阶总共有多少种跳法。
*/

#include "iostream"
using namespace std;
/*
解题思路：
将问题进行分解 跳上n级的台阶可以分成下面的情况
n-1 + 1 ---->>>n
n-2 + 2 ---->>>n
n-3 + 3 ---->>>n
.......
1 + n-1 ---->>>n
0 + n   ---->>>n
那么直接用递归的方法来求解

*/
class Solution {
public:
    int jumpFloorII(int number) {
        if(number<1)
        {
            return  0;
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
		while(num_tmp>=0)
		{
			total += jumpFloorII(num_tmp -1);//+jumpFloorII(number-2);
			num_tmp--;
		}
		return total+1;      // @ +1 表示的意思是：直接跳N级台阶这种情况
    }
	
	int jumpFloorII_1(int number);
};
int Solution::jumpFloorII_1(int number)
{
	{
		if(number==1)
		{
			return 1;
		}
		/*
		if(number==2)
		{
			return 2;
		}
		*/
		return 2*jumpFloorII_1(number-1);
	}
}

//已知通项公式 求n项和的问题……
/*
论坛里的解题思路：
链接：https://www.nowcoder.com/questionTerminal/22243d016f6b47f2a6928b4313c85387
来源：牛客网
关于本题，前提是n个台阶会有一次n阶的跳法。分析如下:
f(1) = 1
f(2) = f(2-1) + f(2-2)         //f(2-2) 表示2阶一次跳2阶的次数。
f(3) = f(3-1) + f(3-2) + f(3-3) 
...
f(n) = f(n-1) + f(n-2) + f(n-3) + ... + f(n-(n-1)) + f(n-n) 
说明： 
1）这里的f(n) 代表的是n个台阶有一次1,2,...n阶的 跳法数。
2）n = 1时，只有1种跳法，f(1) = 1
3) n = 2时，会有两个跳得方式，一次1阶或者2阶，这回归到了问题（1） ，f(2) = f(2-1) + f(2-2) 
4) n = 3时，会有三种跳得方式，1阶、2阶、3阶，
    那么就是第一次跳出1阶后面剩下：f(3-1);第一次跳出2阶，剩下f(3-2)；第一次3阶，那么剩下f(3-3)
    因此结论是f(3) = f(3-1)+f(3-2)+f(3-3)
5) n = n时，会有n中跳的方式，1阶、2阶...n阶，得出结论：
    f(n) = f(n-1)+f(n-2)+...+f(n-(n-1)) + f(n-n) => f(0) + f(1) + f(2) + f(3) + ... + f(n-1)
6) 由以上已经是一种结论，但是为了简单，我们可以继续简化：
    f(n-1) = f(0) + f(1)+f(2)+f(3) + ... + f((n-1)-1) = f(0) + f(1) + f(2) + f(3) + ... + f(n-2)
    f(n) = {f(0) + f(1) + f(2) + f(3) + ... + f(n-2)} + f(n-1) = f(n-1) + f(n-1)
    可以得出：
    f(n) = 2*f(n-1)
7) 得出最终结论,在n阶台阶，一次有1、2、...n阶的跳的方式时，总得跳法为：
              | 1       ,(n=0 ) 
f(n) =        | 1       ,(n=1 )
              | 2*f(n-1),(n>=2)
*/

void main_demo27()
{
	Solution s1;
//	int res = s1.jumpFloorII(4);
	int res_1 = s1.jumpFloorII_1(2);
//	printf("一共有res:%d种跳法\n",res);
	printf("一共有res_1:%d种跳法\n",res_1);
	system("pause");
}

/*
每个台阶相当于一块木板 让青蛙跳上去 n个台阶就有n块木板 最后一块是青蛙到达的地方 必须存在
其他的n-1块木板可以任意选择是否存在 则每个木板有存在和不存在两种选择 
n-1块木板就有2^(n-1)种
*/