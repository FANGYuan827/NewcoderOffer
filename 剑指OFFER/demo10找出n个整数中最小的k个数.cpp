/*
2017��12��1��09:10:00��
����n���������ҳ�������С��K��������������4,5,1,6,2,7,3,8��8�����֣�����С��4��������1,2,3,4,��
*/

#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;

class Solution {
public:
	vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
		int length = input.size();
		int tmp = 0;
		//int length2 = k;
		vector<int>output;
		if(k>length||input.empty())
		{
			//return (vector<int>)NULL;
			return output;
		}
		/*
		for(int i = 0;i<length;i++)
			for(int j =i+1;j<length;j++)
				if(input[i]>input[j])
				{
					tmp = input[i];
					input[i] = input[j];
					input[j] = tmp;
				}
		*/
		sort(input.begin(),input.end());     //��Ȼ�õ���STL������� ��ô�;�����ʵ��STL�е��㷨����������ߴ����³����
		for(int i = 0;i<k;i++)
		{
			//output[i] = input[i];
			output.push_back(input[i]);
		}
		return output;
	}
};


void main_demo10()
{
	Solution s1;
	vector<int>test(5);
	vector<int>result(2);
	test[0] = 10;
	test[1] = 0;
	test[2] = 28;
	test[3] = 7;
	test[4] = 10000;
	result = s1.GetLeastNumbers_Solution(test,2);
	for(int i =0;i<result.size();i++)
	{
		cout<<result[i]<<ends;
	}
	system("pause");
}