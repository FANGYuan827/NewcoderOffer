/*
2018��2��28��14:35:37
��ʵ��һ�����������ҳ��ַ����е�һ��ֻ����һ�ε��ַ���
���磬�����ַ�����ֻ����ǰ�����ַ�"go"ʱ����һ��ֻ����һ�ε��ַ���"g"��
���Ӹ��ַ����ж���ǰ�����ַ���google"ʱ����һ��ֻ����һ�ε��ַ���"l"��

�������:
�����ǰ�ַ���û�д��ڳ���һ�ε��ַ�������#�ַ���
*/

#include "iostream"
#include "vector"			//��������
#include <string>
using namespace std;


class Solution_1{	
public:
  //Insert one char from stringstream
    void Insert(char ch)
    {
		s.push_back(ch);       //�ַ���˳�򱻱��浽��s��
		hash[ch]++;
    }
  //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
		int size = s.size();
		for(int i=0;i<size;i++)
		{
			if(hash[s[i]] == 1)
				return s[i];
		}
		return '#'; 
    }
	Solution_1()
	{
		memset(hash,0,256*sizeof(char));
	}
private:
	vector<char> s;
	char hash[256];
};


//main��������ҵ�����Ĳ��Ժ���
void main_demo36()
{
	Solution_1 s1;
	char *string_point = "googlel";
	int length = sizeof("googlel");
	//cout<<string_point<<endl;
	
	for(int i = 0;i<length-1;i++)       //ѭ�����뵥���ַ�
	{
		s1.Insert(*(string_point+i));
	}
	//cout<<*(string_point)<<endl;
	char res = s1.FirstAppearingOnce();
	cout<<"�ַ�����ֻ����һ�ε��ַ�Ϊ��"<<res<<endl;
	system("pause");
}