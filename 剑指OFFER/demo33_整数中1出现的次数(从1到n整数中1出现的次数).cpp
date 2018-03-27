/*
2018��2��7��10:41:04
���1~13��������1���ֵĴ���,�����100~1300��������1���ֵĴ�����
Ϊ�����ر�����һ��1~13�а���1��������1��10��11��12��13��˹�����6��,���Ƕ��ں�����������û���ˡ�
ACMerϣ�����ǰ����,������������ձ黯,���Ժܿ���������Ǹ�����������1���ֵĴ�����
*/
#include "iostream"
#include "vector"
#include <sstream>
using namespace std;

/*
��������������Լ�������ģ�ɵ��ʽ���� 
����˼·��
ֱ��ѭ������
ͨ��������ת�����ַ�����Ȼ������ж��ַ������ַ��ǲ��ǵ���'1'
�ǳ���ʱ��......
*/
class Solution_demo33 {
public:
	int NumberOf1Between1AndN_Solution(int n)
	{
		if(n<1)
			return 0;
		if(n<10)
			return 1;
		int count = 0;
		for(int i=1;i<=n;i++)
		{
			count+=CountNumOf1(i);
		}
		return count;
	}
private:
	int GetHigh(int num)
	{
		while(num>10)
		{
			num/=10;
		}
		return num;
	}
	int CountNumOf1(int num)
	{
		vector<string> v_res;
		int count = 0;
		stringstream ss;
		ss<<num;
		v_res.push_back(ss.str());
		char *str = (char *)malloc(sizeof(int)*5);
		string str_tmp = v_res[0];
		for(int i=0;i<str_tmp.size();i++)
		{
			if(str_tmp.at(i)=='1')
				count++;
		}
		if(str!=NULL)
		{
			free(str);
		}
		return count;
	}
};

/*
���ϵ�˼·��
���ӣ�https://www.nowcoder.com/questionTerminal/bd7f978302044eee894445e244c7eee6
��Դ��ţ����
��N = abcde ,����abcde�ֱ�Ϊʮ�����и�λ�ϵ����֡�
���Ҫ�����λ��1���ֵĴ�������Ҫ�ܵ�3�����Ӱ�죺��λ�ϵ����֣���λ���£���λ�������֣���λ���ϣ���λ�������֡�

�� �����λ������Ϊ0����λ�Ͽ��ܳ���1�Ĵ����ɸ���λ������
���磺12013�������֪����λ����1����������ǣ�100~199��1100~1199,2100~2199����...��11100~11199��һ��1200����
���Կ������ɸ���λ���֣�12�����������ҵ��ڸ���λ���֣�12������ ��ǰλ����100����

�� �����λ������Ϊ1����λ�Ͽ��ܳ���1�Ĵ��������ܸ���λӰ�컹�ܵ�λӰ�졣
���磺12113�������֪����λ�ܸ�λӰ����ֵ�����ǣ�100~199��1100~1199,2100~2199����....��11100~11199��һ��1200����
���������һ�������ҵ��ڸ���λ���֣�12������ ��ǰλ����100����
��ͬʱ�����ܵ�λӰ�죬��λ����1������ǣ�12100~12113,һ��114�������ڵ�λ���֣�113��+1��

�� �����λ�����ִ���1��2~9�������λ�ϳ���1��������ɸ���λ������
����12213�����λ����1������ǣ�100~199,1100~1199��2100~2199��...��11100~11199,12100~12199,һ����1300����
���ҵ��ڸ���λ����+1��12+1�����Ե�ǰλ����100����
*/
class Solution_demo33_1 {
public:
	int NumberOf1Between1AndN_Solution(int n){
		if(n<1)
			return 0;
		if(n<10)
			return 1;
		int count = 0;
		int i = 1;
		int current = 0,after = 0,before = 0;
		while((n/i)!=0)
		{
			current = (n/i)%10;     //��ǰλ
			before = n/(i*10);     //�õ���λ
			after = n-(n/i)*i;    //�õ���λ
			if(current==0)
				count+=before*i;
			else
				if(current==1)
					count+=before*i+after+1;
				else
					count+=(before+1)*i;
			i*=10;
		}
		return count;
	}
};



void main_demo33()
{
	Solution_demo33_1 s1;
	int res = 0;
	int input = 0;
	printf("������һ����һ�Ǹ�����: ");
	scanf("%d",&input);
	res = s1.NumberOf1Between1AndN_Solution(input);
	printf("������Ϊres=%d\n",res);
	system("pause");
}