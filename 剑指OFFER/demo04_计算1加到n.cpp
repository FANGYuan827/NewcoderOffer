/*
2017��11��22��19:26:50��
��1+2+3+...+n��Ҫ����ʹ�ó˳�����for��while��if��else��switch��case�ȹؼ��ּ������ж���䣨A?B:C��;
*/

#include "iostream"
using namespace std;


class Solution {
public:
    int Sum_Solution(int n) {
		/*
		int sum1 = 0;
		int value = 1+n;
		int count = 0;
		sum1 += value<<6;
		sum1 += value<<5;
		sum1 += value<<2;
		//sum1 += value<<1;
		*/
		int value = n;
		n && (value+=Sum_Solution(n-1));     //�����������Ҫ�Ľ���������
		return value;                      //���ͨ��return ��佫���Ĵ�˦������
		
        
    }
};



void main_demo04()
{
	Solution s1;
	int sum = 0;
	sum = s1.Sum_Solution(100);
	printf("�����Ϊ��sum = %d\n",sum);
	system("pause");
}