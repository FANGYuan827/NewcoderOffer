/*
2017年12月4日20:29:35：
输入一个整数数组，
实现一个函数来调整该数组中数字的顺序，
使得所有的奇数位于数组的前半部分，
所有的偶数位于位于数组的后半部分，
并保证奇数和奇数，偶数和偶数之间的相对位置不变。
*/

#include "iostream"
#include "vector"
#include "stack"
#include "list"
using namespace std;

class Solution {
public:
    void reOrderArray(vector<int> &Array) {
        if(Array.empty())
        {
            return ;
        }
		list<int>s1,s2;
		int length = Array.size();
		for(int i = 0;i<length;i++)
		{
			if(Array[i]%2)    //奇数
			{
				s1.push_back(Array[i]);
			}
			else
			{
				s2.push_back(Array[i]);
			}
		}
		int length1 = s1.size();
		int length2 = s2.size();
		for(int i =0;i<length;i++)
		{
			if(i<length1)
			{
				Array[i] = s1.front();
				s1.pop_front();
			}
			else
			{
				Array[i] = s2.front();
				s2.pop_front();
			}
		}
    }
};

class Solution_1 {
public:
    void reOrderArray(vector<int> &Array) {
        if(Array.empty())
        {
            return ;
        }
		int length = Array.size();
		for(int i =0;i<length-1;i++)
		{
			if(Array[i]%2==0&&Array[i+1]%2!=0)
			{
				int tmp = Array[i];
				Array[i] = Array[i+1];
				Array[i+1] = tmp;
			}
		}
		
    }
};

void main_demo14()     //还有一种方法没掌握 类似于冒泡法
{
	Solution_1 s1;
	vector<int>num(10);
	for(int i=0;i<10;i++)
	{
		num[i] = i;
	}
	s1.reOrderArray(num);
	
	for(int i=0;i<10;i++)
	{
		cout<<num[i]<<ends;
	}




	system("pause");
}

