/*
2018��3��29��16:21:56
����һ���ַ���,���ֵ����ӡ�����ַ������ַ����������С�
���������ַ���abc,���ӡ�����ַ�a,b,c�������г����������ַ���abc,acb,bac,bca,cab��cba��
*/
#include "iostream"
#include "vector"
#include "string"
using namespace std;


class Solution_demo22 {
public:
    vector<string> Permutation(string str) {
		vector<string> v_res;
		if(str.size()<=1)
		{
			v_res.push_back(str);
			return v_res;
		}


		return v_res;
        
    }
};


//VS������������  ��û���������cpp�ļ��µ�main()����  ���������һ��cpp�ļ� һ�������� ��֪��Ϊʲô
void main_demo22()
{
	string str = "a";
	vector<string>v_res;
	Solution_demo22 s1;
	v_res = s1.Permutation(str);
	vector<string>::iterator it;
	for(it=v_res.begin();it!=v_res.end();it++)
	{
		cout<<*it<<endl;
	}
	system("pause");
}