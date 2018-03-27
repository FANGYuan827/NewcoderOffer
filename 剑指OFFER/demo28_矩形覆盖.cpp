/*
2018��1��18��10:15:15
���ǿ�����2*1��С���κ��Ż�������ȥ���Ǹ���ľ��Ρ�
������n��2*1��С�������ص��ظ���һ��2*n�Ĵ���Σ��ܹ��ж����ַ�����
*/

#include "iostream"
using namespace std;

class Solution {
public:
    int rectCover(int number) {
		if(number<=0)
		{
			return 0;
		}
		if(number == 1)
		{
			return 1;
		}
		if(number == 2)
		{
			return 2;
		}
		int total = 0;
		int num_tmp = number;
		int first = 1 ,second = 1;
		while(num_tmp>1)         //�ǵݹ�ʵ�֣�����while()ѭ��ʵ��
		{
			total = first +second;
			first = second;
			second = total;
			num_tmp--;
		}
		return total;

    }
	int  rectCover_1(int number);   //������������ ����ʵ�ַ�������
};
int Solution::rectCover_1(int number)
{
	if(number <= 0)
	{
		return 0;
	}
	if(number == 1)
	{
		return 1;
	}
	if(number == 2)
	{
		return 2;
	}
	int total = 0;
	int num_tmp = number;

	total = rectCover_1(num_tmp-1)+rectCover_1(num_tmp-2);   //�ݹ�ʵ��  ����Ҫѭ�� �ݹ���� ����������ջ ִ�����֮�� ���չ������ε���ջ

	return total;

}


void main_demo28()
{
	Solution s1;
	int res = s1.rectCover(3);
	int res_1 = s1.rectCover_1(3);
	printf("�ܹ���res:%d�ָ��Ƿ���\n",res);
	printf("�ܹ���res_1:%d�ָ��Ƿ���\n",res_1);
	system("pause");
}