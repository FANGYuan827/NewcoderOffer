#include "iostream"
#include "vector"
using namespace std;


class Solution {
public:
    int GetUglyNumber_Solution(int index) {
		if(index < 7)
		{
			return index;
		}
		vector<int>myArray(index);
		int num = 7;
		int i = 7;
		while(i<index)
		{
			if(IsUgly(num))
			{
				myArray[i-1] = num;
				i++;
			}
			num++;
		}
		return myArray[index-1];
	}
	bool IsUgly(int num)
	{
		int result = num;
		while(result%2==0)
		{
			result/=2;
		}
		while(result%3==0)
		{
			result/=3;
		}
		while(result%5==0)
		{
			result/=5;
		}
	    return (result==1?1:0);
	}

};

void main_demo20_2()
{

	Solution s1;
	int index = 100;
	int result = 0;
	result = s1.GetUglyNumber_Solution(index); 
	printf("第%d个丑数是:%d\n",index,result);
	system("pause");
}