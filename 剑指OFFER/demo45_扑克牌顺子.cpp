/*
2018��3��5��15:49:45
LL���������ر��,��Ϊ��ȥ����һ���˿���,
���������Ȼ��2������,2��С��(һ����ԭ����54��^_^)...
��������г����5����,�����Լ�������,�����ܲ��ܳ鵽˳��,
����鵽�Ļ�,������ȥ��������Ʊ,�ٺ٣���
������A,����3,С��,����,��Ƭ5��,��Oh My God!��
����˳��.....LL��������,��������,������\С �����Կ����κ�����,����A����1,JΪ11,QΪ12,KΪ13��
�����5���ƾͿ��Ա�ɡ�1,2,3,4,5��(��С���ֱ���2��4),
��So Lucky!����
LL����ȥ��������Ʊ����
����,Ҫ����ʹ�������ģ������Ĺ���,Ȼ���������LL��������Ρ�
Ϊ�˷������,�������Ϊ��С����0��
*/
#include "iostream"
#include <vector>
using namespace std;

/*
ɵ��ʽ�Ľⷨ �����нⷨ����ٳ����� Ȼ�����ö��֧�ṹ
*/
class Solution_demo45 {
public:
	bool IsContinuous( vector<int> numbers ) {
		if(numbers.size()!=5)
			return false;
		int count = NumberOf0(numbers);
		int min = Min(numbers);
		int max = Max(numbers);
		int sum = Sum(numbers);
		switch(count)
		{
		case 0:
			{
				if(max-min==4)
				{
					if(sum==5*min+10)
						return true;
					else
						return false;
				}
				else
				{
					return false;
				}
				break;
			}
		case 1:
			{
				if(max-min==3||max-min==4)
				{
					if(sum>=4*min+6&&sum<=4*min+9)
						return true;
					else
						return false;
				}
				else
				{
					return false;
				}
				break;
			}
		case 2:
			{
				if(max-min>=2&&max-min<=4)
				{
					if(sum>=3*min+3&&sum<=3*min+7)
						return true;
					else
						return false;
				}
				else
				{
					return false;
				}
				break;
			}
		case 3:
			{
				if(max-min>=1&&max-min<=4)
				{
					if(sum>=2*min+1&&sum<=2*min+4)
						return true;
					else
						return false;
				}
				else
				{
					return false;
				}
				break;
			}
		case 4:
			{
				return true;
				break;
			}
		default:break;
		}
		return false;
	}
private:
	int Min(vector<int>input)
	{
		int min = 100;
		for(unsigned int i=0;i<input.size();i++)
		{
			if(min>input[i]&&input[i]!=0)
				min = input[i];
		}
		return min;
	}
	int Max(vector<int>input)
	{
		int max = input[0];
		for(unsigned int i=1;i<input.size();i++)
		{
			if(max<input[i])
				max = input[i];
		}
		return max;
	}
	int Sum(vector<int>input)
	{
		int sum = 0;
		for(unsigned int i=0;i<input.size();i++)
		{
			sum+=input[i];
		}
		return sum;
	}
	int NumberOf0(vector<int>input)
	{
		int count = 0;
		for(unsigned int i=0;i<input.size();i++)
		{
			if(input[i]==0)
				++count;
		}
		return count;
	}
};

/*
���ϵĽⷨ˼·��
��˳���������������
1����0���� û���ظ�������
2��max-min<=5(�����min��max�ǲ�����0��)
*/
class Solution_demo45_1 {
public:
	bool IsContinuous( vector<int> numbers ) {
		if(numbers.size()!=5)
		{
			return false;
		}
		int *flag = new int[14];
		memset(flag,0,14);
		int min = 14;
		int max = -1;
		for(unsigned int i=0;i<numbers.size();i++)
		{
			flag[numbers[i]]++;
			if(numbers[i]==0)
				continue;
			if(min>numbers[i])
			{
				min = numbers[i];
			}
			if(max<numbers[i])
			{
				max = numbers[i];
			}
			if(flag[numbers[i]]>1&&numbers[i]!=0)
			{
				return false;
			}
		}
		if(max-min>=5)
		{
			return false;
		}
		return true;

	}

};
void main_demo45()
{
	Solution_demo45_1 s1;
	vector<int>vec_input;

	vec_input.push_back(0);
	vec_input.push_back(0);
	vec_input.push_back(0);
	vec_input.push_back(0);
	vec_input.push_back(4);
	bool res = s1.IsContinuous(vec_input);
	if(res == false)
		cout<<"����˳��"<<endl;
	else
		cout<<"��˳��"<<endl;
	system("pause");
}



