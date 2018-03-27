/*
2017��12��4��21:23:18��
��һ������Ϊn����������������ֶ���0��n-1�ķ�Χ�ڡ� 
������ĳЩ�������ظ��ģ�����֪���м����������ظ��ġ�
Ҳ��֪��ÿ�������ظ����Ρ�
���ҳ�����������һ���ظ������֡� 
���磬������볤��Ϊ7������{2,3,1,0,2,5,3}����ô��Ӧ������ǵ�һ���ظ�������2��
*/
#include "iostream"
#include "vector"
//#include "windef.h"
using namespace std;
#define FALSE 0
#define TRUE  1

class Solution {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int* duplication) {
		if(numbers==NULL||length<=1||duplication==NULL)
		{
			return FALSE;
		}
        vector<int>Num(length);
		for(int i =0;i<length;i++)
		{
			++Num[numbers[i]];
			if(Num[numbers[i]]>1)     //ֻҪһ�ҵ��ظ������� �������� ֹͣ��������......
			{
				*duplication = numbers[i]; 
				return TRUE;
			}
		}
		/*
		for(int i =0;i<length;i++)
		{
			if(Num[i]>1)
			{
				*duplication = i;
				return 1;
			}
		}
		*/
		return FALSE;      //��C/C++(clang++3.9)�б�������һ�� ������벻ͨ�� �ᱨ��;;;;;

    }
};

/*
��һ�ֽⷨ��
����Ҫ������������hash table ���������飬��Ŀ��д�����������ֵķ�Χ��֤��0��n-1֮�� 
���Կ������������������ñ�־����һ�����ֱ����ʹ��� �������ö�Ӧλ�ϵ���+n ֮����������ͬ����ʱ 
�ᷢ�ֶ�Ӧλ�ϵ����Ѿ����ڵ���n ��ôֱ�ӷ������������......
*/

void main_demo15()
{
	Solution s1;
	int Array[6] = {2,1,3,2,2,2};
	int result = 0;
	s1.duplicate(Array,6,&result);

	cout<<"���Ϊ:"<<result<<endl;

	system("pause");
}