/*
2017年12月4日21:23:18：
在一个长度为n的数组里的所有数字都在0到n-1的范围内。 
数组中某些数字是重复的，但不知道有几个数字是重复的。
也不知道每个数字重复几次。
请找出数组中任意一个重复的数字。 
例如，如果输入长度为7的数组{2,3,1,0,2,5,3}，那么对应的输出是第一个重复的数字2。
*/
#include "iostream"
#include "vector"
//#include "windef.h"
using namespace std;
#define FALSE 0
#define TRUE  1

class Solution {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int* duplication) {
		if(numbers==NULL||length<=1||duplication==NULL)
		{
			return FALSE;
		}
        vector<int>Num(length);
		for(int i =0;i<length;i++)
		{
			++Num[numbers[i]];
			if(Num[numbers[i]]>1)     //只要一找到重复的数字 就立马返回 停止继续遍历......
			{
				*duplication = numbers[i]; 
				return TRUE;
			}
		}
		/*
		for(int i =0;i<length;i++)
		{
			if(Num[i]>1)
			{
				*duplication = i;
				return 1;
			}
		}
		*/
		return FALSE;      //在C/C++(clang++3.9)中必须有这一句 否则编译不通过 会报错;;;;;

    }
};

/*
另一种解法：
不需要额外的数组或者hash table 来保存数组，题目里写了数组里数字的范围保证在0～n-1之间 
所以可以利用现有数组设置标志，当一个数字被访问过后 可以设置对应位上的数+n 之后在遇到相同的数时 
会发现对应位上的数已经大于等于n 那么直接返回这个数即可......
*/

void main_demo15()
{
	Solution s1;
	int Array[6] = {2,1,3,2,2,2};
	int result = 0;
	s1.duplicate(Array,6,&result);

	cout<<"结果为:"<<result<<endl;

	system("pause");
}