/*
2018年3月4日17:32:37
输入一个递增排序的数组和一个数字S，在数组中查找两个数，
使得他们的和正好是S，如果有多对数字的和等于S，输出两个数的乘积最小的。
*/

#include "iostream"
#include <vector>
using namespace std;

/*自己的思路*/
class Solution_demo41 {
public:
	vector<int> FindNumbersWithSum(vector<int> my_array,int sum) {
		vector<int> v_res;
		if(my_array.size()<=0)
		{
			return v_res;
		}
		int i = 0,j = 0;
		for(i=0;i<my_array.size();i++)
		{
			for(j=i+1;j<my_array.size();j++)
			{
				if(my_array[i]+my_array[j]==sum)
				{
					v_res.push_back(my_array[i]);
					v_res.push_back(my_array[j]);
					goto end;
				}
			}
		}
end:
		return v_res;
	}
};

/*
网上大神的思路
利用两个指针 从两头到中间
链接：https://www.nowcoder.com/questionTerminal/390da4f7a00f44bea7c2f3d19491311b
来源：牛客网

//方法二：从数组两端向中间查找满足条件的两个数
    * i,j分辨表示数组两端下表
    * 当array[i]+array[j]>S时，j-- 尾端向前移动，两数据和增大
    * 当array[i]+array[j]=S时，将array[i],array[j]依次添加到ArrayList中
    * 当array[i]+array[j]<S时，i++前段向后移动，两数据和减小
*/
/*
数列满足递增 设头尾两个指针（在和一定的情况下，相差越远乘积越小）
*/
class Solution_demo41_1 {
public:
	vector<int> FindNumbersWithSum(vector<int> my_array,int sum) {
		vector<int> v_res;
		if(my_array.size()<=0)
		{
			return v_res;
		}
		vector<int>::iterator start = my_array.begin();
		vector<int>::iterator end = my_array.end()-1;       //m_array.end()返回的是数组最后一个元素的下一个位置
		while(start<end)
		{
			if((*start)+(*end)==sum)
			{
				v_res.push_back(*start);
				v_res.push_back(*end);
				break;
			}
			else
			{
				if((*start)+(*end)>sum)
					end--;
				else
					start++;
			}
		}
		return v_res;
	}
};


void main_demo41()
{
	vector<int>v_input;
	vector<int>v_res;
	Solution_demo41_1 s1;
	for(int i =0;i<10;i++)
	{
		v_input.push_back(i+1);
	}
	v_res = s1.FindNumbersWithSum(v_input,12);
	vector<int>::iterator it;
	cout<<"所求结果为:";
	for(it = v_res.begin();it!=v_res.end();it++)
	{
		cout<<*it<<ends;
	}
	cout<<endl;

	system("pause");
}