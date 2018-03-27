/*
2017年12月20日19:13:18
把只包含因子2、3和5的数称作丑数（Ugly Number）。
例如6、8都是丑数，但14不是，因为它包含因子7。 
习惯上我们把1当做是第一个丑数。
求按从小到大的顺序的第N个丑数。
*/

#include "iostream"
#include "vector"
using namespace std;

/*
class Solution {
public:
    int GetUglyNumber_Solution(int index) {
		if(index < 7)
		{
			return index;
		}
		vector<int>myArray(index);
		myArray[0] = 1;
		int t2 = 0,t3 = 0, t5 = 0 ,i;
		for(i = 1; i< index ; ++i)
		{
			myArray[i] = min(myArray[t2]*2,min(myArray[t3]*3,myArray[t5]*5));
			if(myArray[i]==myArray[t2]*2)
				t2++;
			if(myArray[i]==myArray[t3]*3)
				t3++;
			if(myArray[i]==myArray[t5]*5)
				t5++;
		}
		return myArray[index-1];

	}	
};
*/
/*
关键是找出丑数生成的规律 如何生成丑数 并且将丑数按照顺序存放到数组中去
 下一个丑数 就是前面最小丑数*2  *3  *5 生成的,
*/
class Solution{
public:
	int GetUglyNumber_Solution(int index){
		if(index < 1)
		{
			return 0;
		}
		int i =0;
		int *myArray = new int[index];     //申请内存
		myArray[0] = 1;
		int nextUglyNum = 1;
		int *pNum2 = myArray;
		int *pNum3 = myArray;
		int *pNum5 = myArray;
		while(nextUglyNum<index)
		{
			int MinNum = Min(*pNum2*2,*pNum3*3,*pNum5*5);
			myArray[nextUglyNum] = MinNum;
			/*
			//该思路： 我们只用比较3个数：用于乘2的最小的数、用于乘3的最小的数，用于乘5的最小的数
			if(MinNum == *pNum2*2)
				++pNum2;
			if(MinNum == *pNum3*3)
				++pNum3;
			if(MinNum == *pNum5*5)
				++pNum5;
			*/
			while(*pNum2*2<=MinNum)
				++pNum2;
			while(*pNum3*3<=MinNum)
				++pNum3;
			while(*pNum5*5<=MinNum)
				++pNum5;
			++nextUglyNum;
		}
		int result = myArray[index-1];
		/*
		while(i<index)    //打印丑数数组
		{
			printf("%d  ",myArray[i]);
			i++;
		}
		*/
		delete []myArray;    //释放内存
		return result;

	}
	int Min(int Num1,int Num2,int Num3)
	{
		int min1 = Num1<Num2?Num1:Num2;
		int min2 = min1<Num3?min1:Num3;
		return min2;
	}
};
void main_demo()
{
	Solution s1;
	int index = 20;
	int result = 0;
	result = s1.GetUglyNumber_Solution(index); 
	printf("第%d个丑数是:%d\n",index,result);
	system("pause");
}

/*
说下思路，如果p是丑数，那么p=2^x * 3^y * 5^z
那么只要赋予x,y,z不同的值就能得到不同的丑数。
如果要顺序找出丑数，要知道下面几个特点。
对于任何丑数p：
（一）那么2*p,3*p,5*p都是丑数，并且2*p<3*p<5*p
（二）如果p<q, 那么2*p<2*q,3*p<3*q,5*p<5*q
现在说说算法思想：
    由于1是最小的丑数，那么从1开始，把2*1，3*1，5*1，进行比较，得出最小的就是1
的下一个丑数，也就是2*1，
    这个时候，多了一个丑数‘2’，也就又多了3个可以比较的丑数，2*2，3*2，5*2，
这个时候就把之前‘1’生成的丑数和‘2’生成的丑数加进来也就是
(3*1,5*1,2*2，3*2，5*2)进行比较，找出最小的。。。。如此循环下去就会发现，
每次选进来一个丑数，该丑数又会生成3个新的丑数进行比较。
上面的暴力方法也应该能解决，但是如果在面试官用这种方法，估计面试官只会摇头吧。
下面说一个O（n）的算法。
    在上面的特点中，既然有p<q, 那么2*p<2*q，那么
“我”在前面比你小的数都没被选上，你后面生成新的丑数一定比“我”大吧，那么你乘2
生成的丑数一定比我乘2的大吧，那么在我选上之后你才有机会选上。
其实每次我们只用比较3个数：用于乘2的最小的数、用于乘3的最小的数，用于乘5的最小的
数。也就是比较(2*x , 3*y, 5*z) ，x>=y>=z的，
重点说说下面代码中p的作用：int p[] = new int[] { 0, 0, 0 }; p[0]表示最小用于
乘2比较数在数组a中的【位置】。
*/