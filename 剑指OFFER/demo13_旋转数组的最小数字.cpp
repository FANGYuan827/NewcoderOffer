/*
2017年12月4日16:37:02：
把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
输入一个非递减排序的数组的一个旋转，输出旋转数组的最小元素。 
例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。 
NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。
*/
#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;
class Solution_1 
{
public:
	int minNumberInRotateArray(vector<int> rotateArray) 
	{
		if(rotateArray.empty())
		{
			return 0;
		}
		sort(rotateArray.begin(),rotateArray.end());    //这种方法的时间复杂度太大了 题目考点不是这个...快速查找...
		return rotateArray[0];
	}
};

class Solution_2
{
public:
	int minNumberInRotateArray(vector<int> rotateArray) 
	{
		int flag = 0;
		if(rotateArray.empty())
		{
			return 0;
		}
		int length = rotateArray.size();
		for(int i =0;i<length-1;i++)
		{
			if(rotateArray[i]>rotateArray[i+1])
			{
				flag = i+1;
				break;
			}
		}
		return rotateArray[flag];
	}
};
/*
解题思路:
采用二分法解答这个问题，
mid = low + (high - low)/2
需要考虑三种情况：
(1)Array[mid] > Array[high]:
出现这种情况的Array类似[3,4,5,6,0,1,2]，此时最小数字一定在mid的右边。
low = mid + 1
(2)Array[mid] == Array[high]:
出现这种情况的Array类似 [1,0,1,1,1] 或者[1,1,1,0,1]，此时最小数字不好判断在mid左边
还是右边,这时只好一个一个试 ，
high = high - 1
(3)Array[mid] < Array[high]:
出现这种情况的Array类似[2,2,3,4,5,6,6],此时最小数字一定就是Array[mid]或者在mid的左
边。因为右边必然都是递增的。
high = mid
注意这里有个坑：如果待查询的范围最后只剩两个数，那么mid 一定会指向下标靠前的数字
比如 Array = [4,6]
Array[low] = 4 ;Array[mid] = 4 ; Array[high] = 6 ;
如果high = mid - 1，就会产生错误， 因此high = mid
但情形(1)中low = mid + 1就不会错误
*/
class Solution_3      //二分法查找.....  这个方法比我想的方法好啊....
{
public:
	int minNumberInRotateArray(vector<int> rotateArray) 
	{
		if(rotateArray.empty())
		{
			return 0;
		}
		int left =0;
		int right = 0;
		int middle = 0;
		int length = rotateArray.size();
		right = length -1;
		while(left<right)
		{
			middle = left+(right-left)/2;
			if(rotateArray[middle]>rotateArray[right])
			{
				left = middle+1;
			}
			else
			{
				if(rotateArray[middle]==rotateArray[right])
				{
					right = right-1;
				}
				else
				{
					right = middle;
				}
			}
		}

		return rotateArray[left];
	}
};

void main_demo13()     //主要考点是二分法
{
	Solution_3 s1;
	vector<int>v1(6);
	v1[0] = 4;
	v1[1] = 4;
	v1[2] = 4;
	v1[3] = 4;
	v1[4] = 1;
	v1[5] = 2;
	cout<<"结果为:"<<s1.minNumberInRotateArray(v1)<<endl;

	system("pause");
}