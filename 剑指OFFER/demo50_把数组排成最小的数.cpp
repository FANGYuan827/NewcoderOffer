/*
2018��3��10��21:13:11
����һ�����������飬����������������ƴ�������ų�һ������
��ӡ��ƴ�ӳ���������������С��һ����
������������{3��32��321}�����ӡ���������������ųɵ���С����Ϊ321323��
*/

#include "iostream"
#include <sstream>
#include <algorithm>
#include <vector>
#include "string"
using namespace std;

/*
����˼·��
�Ƚ���������ת����String���� Ȼ��String�������� ����ź�����ַ���ƴ������

string���������:
�Զ���һ���Ƚϴ�С�ĺ��� �Ƚ������ַ���s1��s2��С��ʱ�� �Ƚ�����ƴ������ 
�Ƚ�s1+s2 �� s2+s1�Ǹ��� ���s1+s2�� ˵��s2Ӧ�÷���ǰ�� ����������� s2��Ӧ������s1ǰ��
*/

class Solution_demo50 {
public:
    string PrintMinNumber(vector<int> numbers) {
        string s_res;
		if(numbers.size()<1)
		{
			return s_res;
		}
		int length = numbers.size();
		vector<string> str_tmp;
		for(int i=0;i<length;++i)
		{
			stringstream ss;
			ss<<numbers[i];
			str_tmp.push_back(ss.str());                  //��int��ת������string��
		}
		sort(str_tmp.begin(),str_tmp.end(),Compare);
		vector<string>::iterator it;
		for(it=str_tmp.begin();it!=str_tmp.end();it++)
		{
			s_res+=*it;
		}
		return s_res;
    }
private:
	static bool Compare(const string &s1,const string s2)     //�Ƚ�s1+s2 �� s2+s1�Ĵ�С     //����static  --->>>sort(str_tmp.begin(),str_tmp.end(),Compare); ���벻ͨ��
	{
		string S1 = s1+s2;
		string S2 = s2+s1;
		return S1<S2;                //(s1+s2 < s2+s1����true)
	}
	
};

/*
��Ҫ˵��:
sort�еıȽϺ���Ҫ����Ϊ��̬��Ա��������ȫ�ֺ��� ������Ϊ��ͨ��Ա���� ����������ᱨ��
��Ϊ�Ǿ�̬��Ա�����������ھ���Ķ���ģ���std::sort���ຯ����ȫ�ֵ� ����޷���sort�е��÷Ǿ�̬��Ա����
��̬��Ա��������ȫ�ֺ����ǲ������ھ������ģ����Զ������ʣ����贴���κζ���ʵ���Ϳ��Է��� 
ͬʱ��̬��Ա���������Ե�����ķǾ�̬��Ա...
���ܣ�C++������ostringstream��istringstream��stringstream�������࣬Ҫʹ�����Ǵ�������ͱ������sstream.hͷ�ļ���
istringstream������ִ��C++���Ĵ��������������
ostringstream������ִ��C���Ĵ�������������� 
stringstream��ͬʱ����֧��C���Ĵ������������������
С�᣺
1����istringstream���� �����ַ�����ʱ �ո���Ϊ�ַ����������ڲ��ֽ�
2��istringstream�������Ϊstring��������͵�ת��;��
3��ignore������������Ҫ��ȡ�ַ�������󳤶� ��Ҫ���Ե��ַ�
ʾ�����룺
http://blog.csdn.net/sophia1224/article/details/53054698
*/

void main_demo50()
{
	Solution_demo50 s1;
	vector<int> v_input;

	v_input.push_back(97);
	v_input.push_back(32);
	v_input.push_back(321);

	string res = s1.PrintMinNumber(v_input);
	cout<<"���ųɵ���С����Ϊ:"<<res<<endl;
	system("pause");
}