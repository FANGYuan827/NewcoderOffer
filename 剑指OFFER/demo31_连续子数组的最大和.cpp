/*
2018年1月23日22:14:24
HZ偶尔会拿些专业问题来忽悠那些非计算机专业的同学。
今天测试组开完会后,
他又发话了:
在古老的一维模式识别中,常常需要计算连续子向量的最大和,
当向量全为正数的时候,问题很好解决。
但是,如果向量中包含负数,是否应该包含某个负数,
并期望旁边的正数会弥补它呢？
例如:{6,-3,-2,7,-15,1,2,2},
连续子向量的最大和为8(从第0个开始,到第3个为止)。
你会不会被他忽悠住？(子向量的长度至少是1)
*/
#include "iostream"
#include <vector>
using namespace std;



class Solution {
public:
	/*
	暴力解题方法 直接求出所有子向量的和 然后找出最大值 算法复杂度O(n^2)
	*/
    int FindGreatestSumOfSubArray(vector<int> Array) {
		int len = Array.size();
		vector<int>v_res;
		int res = 0;
		int sum = 0;
		if(len<=0)
		{
			return NULL;
		}
		for(int i=0;i<len;i++)
		{
			for(int j =i;j<len;j++)
			{
				sum +=Array[j];
				v_res.push_back(sum);
			}
			sum = 0;
		}
		res = v_res[0];
		for(int i=1;i<v_res.size();i++)
		{
			if(res<v_res[i])
				res = v_res[i];
		}
		return res;
    }
};


void main_demo31()
{
	Solution s1;
	vector<int> Input;
	/*
	Input.push_back(6);
	Input.push_back(-3);
	Input.push_back(-2);
	Input.push_back(7);
	Input.push_back(-15);
	Input.push_back(1);
	Input.push_back(2);
	Input.push_back(2);
	*/
	Input.push_back(1);
	Input.push_back(-2);	
	Input.push_back(3);
	Input.push_back(10);
	Input.push_back(-4);
	Input.push_back(7);
	Input.push_back(2);
	Input.push_back(-5);
	int res = 0;
	res = s1.FindGreatestSumOfSubArray(Input);
	printf("结果是:%d\n",res);
	system("pause");
}