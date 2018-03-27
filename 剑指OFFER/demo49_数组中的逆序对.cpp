/*
2018年3月6日21:07:27
在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。
输入一个数组,求出这个数组中的逆序对的总数P。
并将P对1000000007取模的结果输出。 
即输出P%1000000007
输入描述：
题目保证输入的数组中没有的相同的数字

数据范围：

对于%50的数据,size<=10^4

对于%75的数据,size<=10^5

对于%100的数据,size<=2*10^5

示例1：
输入
1，2，3，4，5，6，7，0

输出：

7

*/
#include "iostream"
#include <vector>
using namespace std;



/*
自己的思路 就是两个循环的嵌套 算法复杂度O(n^2) 测试用例不通过
网上大神思路：
归并排序
*/

/*
class Solution_demo49{
public:
	int InversePairs(vector<int> data) {
		if(data.size()<1)
			return 0;
		int count = 0;
		int count_1 = 0;
		int min_position = -1;
		int max_position = 0;
		int min = 40000;
		int max = data[0];
		int i = 0;
		while(count_1<data.size()-1)
		{
			for(i=0;i<data.size();i++)
			{
				if(min>=data[i]&&(data[i]!=-1)&&i!=min_position)
				{
					min = data[i];
					min_position = i;
					count+=min_position;
					data[i] = -1;              //已经找到的的最小值置为-1;
				}
				if(data[i]==-1)
				{
					count_1++;
				}
			}
		}
		return count%1000000007;
	}
};
*/
class Solution_demo49_1{
public:
	int InversePairs(vector<int> data) {
		if(data.size()<1)
			return 0;
		int length = data.size();
		vector<int> copy;
		for(int i=0;i<length;i++)
		{
			copy.push_back(data[i]);
		}
		long long count = InversePairsCore(data,copy,0,length-1);
		return count%1000000007;
	}
private:
	long long InversePairsCore(vector<int> &data,vector<int> &copy,int start,int end)
	{
		if(start==end)
		{
			copy[start] = data[start];
			return 0;
		}
		int length = (end-start)/2;
		long long left = InversePairsCore(data,copy,start,start+length)%1000000007;     //统计左半部分的逆序对数量   递归调用
		long long right = InversePairsCore(data,copy,start+length+1,end)%1000000007;    //统计右半部分的逆序对数量

		int i = start+length;		 //指向子数组的最后一个元素
		int j = end;				//指向子数组的最后一个元素
		int indexcopy = end;
		long long count = 0;
		while(i>=start&&j>=start+length+1)
		{
			if(data[i]>data[j])                     //这个if...else...语句是为了统计两个子数组之间的逆序对数量
			{
				copy[indexcopy--] = data[i--];
				count += j-start-length;             //data[j]以及以前的所有元素的数量
				if(count>=1000000007)
					count%=1000000007;
			}
			else
			{
				copy[indexcopy--] = data[j--];
			}
		}
		for(;i>=start;i--)
			copy[indexcopy--] = data[i];
		for(;j>=start+length+1;j--)		//
			copy[indexcopy--] = data[j];
		for(int i=start;i<=end;i++)
		{
			data[i] = copy[i];
		}
		return (left+right+count)%1000000007;
	}
};

void main_demo49()
{
	Solution_demo49_1 s1;
	int res = 0;
	vector<int>v_input;
	v_input.push_back(1);
	v_input.push_back(2);
	v_input.push_back(3);
	v_input.push_back(7);
	v_input.push_back(5);
	v_input.push_back(6);
	v_input.push_back(4);
	v_input.push_back(0);
    res = s1.InversePairs(v_input);
	cout<<"数组中逆序对的总数为："<<res<<endl;
	system("pause");
}