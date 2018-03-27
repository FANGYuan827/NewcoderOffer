/*
2018��3��4��12:32:06
ͳ��һ�����������������г��ֵĴ���
*/

#include "iostream"
#include <vector>
using namespace std;



/*
��������� һ����õ��Ƕ��ַ�����
*/
class Solution_demo40 {
public:
    int GetNumberOfK(vector<int> data ,int k) {
		if(data.size()<=0)
		{
			return 0;
		}
		int count = 0;
		for(int i=0;i<data.size();i++)
		{
			if(data[i]==k)
				count++;
		}
		return count;
    }
	int GetNumberOfK_2(vector<int> data ,int k){
		if(data.size()<=0||k<data[0]||k>data[data.size()-1])    //�����������
		{
			return 0;
		}
		int count = 0;
		int i = 0;
		for(i = 0;i<data.size();i++)
		{
			if(data[i]==k)
			{
				break;
			}
		}
		while(k==data[i])
		{
			count++;
			i++;
		}
		return count;
	}
};
class Solution_demo40_2{
public:
	int GetNumberOfK(vector<int> data ,int k) {
		if(data.size()<=0)
		{
			return 0;
		}
		int lower = getLower(data,k);
		int upper = getUpper(data,k);
		return upper-lower+1;
	}
private:
	int getLower(vector<int>data,int k)		//��ȡ��һ�γ��ֵ�λ��
	{
		int start = 0;
		int end = data.size()-1;
		int mid = (start+end)/2;
		while(start<=end)
		{
			if(data[mid]>=k)
			{
				end = mid -1;
			}
			else
			{
				start = mid + 1;
			}
			mid = (start+end)/2;
		}
		return start;
	}


	int getUpper(vector<int>data,int k)     //��ȡk���һ�γ��ֵ�λ��
	{
		int start = 0;
		int end = data.size()-1;
		int mid =(start+end)/2;
		while(start<=end)
		{
			if(data[mid]<=k)
			{
				start = mid + 1;
			}
			else
			{
				end = mid -1 ;
			}
			mid = (start+end)/2;
		}
		return end;
	}
};







void main_demo40()
{
	Solution_demo40_2 s1;
	vector<int>v_input;
	v_input.push_back(1);
	v_input.push_back(2);
	v_input.push_back(3);
	v_input.push_back(4);
	v_input.push_back(5);
	v_input.push_back(5);
	v_input.push_back(5);
	v_input.push_back(12);
	int res = 0;
	res = s1.GetNumberOfK(v_input,5);
	cout<<"���������������г��ֵĴ���Ϊ:"<<res<<endl;

	system("pause");
}