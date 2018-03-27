/*
2018��1��23��22:14:24
HZż������Щרҵ������������Щ�Ǽ����רҵ��ͬѧ��
��������鿪����,
���ַ�����:
�ڹ��ϵ�һάģʽʶ����,������Ҫ��������������������,
������ȫΪ������ʱ��,����ܺý����
����,��������а�������,�Ƿ�Ӧ�ð���ĳ������,
�������Աߵ��������ֲ����أ�
����:{6,-3,-2,7,-15,1,2,2},
����������������Ϊ8(�ӵ�0����ʼ,����3��Ϊֹ)��
��᲻�ᱻ������ס��(�������ĳ���������1)
*/
#include "iostream"
#include <vector>
using namespace std;



class Solution {
public:
	/*
	�������ⷽ�� ֱ����������������ĺ� Ȼ���ҳ����ֵ �㷨���Ӷ�O(n^2)
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
	printf("�����:%d\n",res);
	system("pause");
}