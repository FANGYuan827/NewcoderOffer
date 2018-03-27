/*
2018��3��1��09:23:46
��һ���ַ���(1<=�ַ�������<=10000��ȫ������ĸ���)���ҵ���һ��ֻ����һ�ε��ַ�,����������λ��
���������
-1��ʾ���ַ���������;
�ַ���λ�ô�0��ʼ;
*/

#include "iostream"
#include "string"
#include "vector"
using namespace std;

class 	Solution_demo38{
public:
    int FirstNotRepeatingChar(string str) {         //�鱾�ⷨ������hash����ͳ�Ƹ���ĸ���ֵĴ��� �ڶ���ɨ��ֱ�ӷ���hash���ô���
		if(str.size()==0)
		{
			cout<<"�ַ�������Ϊ0"<<endl;
			return -1;
		}
		for(int i=0;i<str.size();i++)
		{
			vec_res.push_back(str[i]);
			Table[str[i]]++;
		}
		for(int i=0;i<vec_res.size();i++)
		{
			if(Table[vec_res[i]] == 1)
			{
				return i;
			}
		}
		return -1;
    }
	Solution_demo38()
	{
		memset(Table,0,128);
	}
private:
	vector<char>vec_res;
	char Table[128];
};



void main_demo38()
{
	Solution_demo38 s1;
	string str = "google";
	//str = "";
	//cout<<str[0]<<endl;
	int pos = s1.FirstNotRepeatingChar(str);
	cout<<"��һ��ֻ����һ�ε��ַ���λ���ǣ�"<<pos<<endl;
	system("pause");
}