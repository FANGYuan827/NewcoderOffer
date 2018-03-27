/*
2017��12��4��20:29:35��
����һ���������飬
ʵ��һ�����������������������ֵ�˳��
ʹ�����е�����λ�������ǰ�벿�֣�
���е�ż��λ��λ������ĺ�벿�֣�
����֤������������ż����ż��֮������λ�ò��䡣
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
			if(Array[i]%2)    //����
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

void main_demo14()     //����һ�ַ���û���� ������ð�ݷ�
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

