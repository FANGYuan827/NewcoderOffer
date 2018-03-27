/*
2017��12��8��20:09:27��
��һ����ά�����У�ÿһ�ж����մ����ҵ�����˳������ÿһ�ж����մ��ϵ��µ�����˳������
�����һ������������������һ����ά�����һ���������ж��������Ƿ��и�������
*/

#include "iostream"
#include "vector"
using namespace std;
#define False 0
#define True 1


/*������˼�� ʱ�临�Ӷ�O(n*n)*/
class Solution_my {
public:
    bool Find(int target, vector<vector<int> > myArray) {
		if(myArray.size()==0)
		{
			return False;
		}
		int length1 = myArray.size();
		int length2 = myArray[0].size();
		for(int i = 0;i<length1;i++)
			for(int j =0;j<length2;j++)
			{
				if(myArray[i][j]==target)
				{
					return True;
				}
			}
       return False;
	}

};
/* ˼·
* ����������ģ������½��������������ֵݼ����������ֵ�����
* ��˴����½ǿ�ʼ���ң���Ҫ�������ֱ����½����ִ�ʱ������
* Ҫ�������ֱ����½�����Сʱ������
*/

class Solution {
public:
    bool Find(int target, vector<vector<int> > myArray) {
		if(myArray.size()==0)
		{
			return False;
		}
		int length1 = myArray.size();      //������������
		int length2 = myArray[0].size();  //������������
		int i = length1-1;
		int j = 0;
		while(j<length2&&i>=0)
		{
			if(myArray[i][j]<target)
			{
				j++;
			}
			else
			{
				if(myArray[i][j]>target)
				{
					i--;
				}
				else
				{
					return true;
				}
			}
			/*
			if(j==length2||i<0)
			{
				break;
			}
			*/
		}
		return false;
	}

};
void main_demo18()
{
	//Solution_my s1;
	Solution s1;
	int result = 0;
	int Target = 0;
	printf("������Ҫ���ҵ���\n");
	scanf("%d",&Target);
	vector<vector<int>> myArray(4,5);
	int i = 0,j = 0;
	for(i=0;i<4;i++)
	{
		for(j=0;j<5;j++)
		{
			myArray[i][j] =i+j; 
		}
	}
	result = s1.Find(Target,myArray);    //
	if(result!=0)
	{
		printf("������:%d\n",Target);
	}
	else
	{
		printf("��������:%d\n",Target);
	}
	printf("����:%d ����:%d\n",myArray.size(),myArray[0].size());
	for(i=0;i<4;i++)
	{
		for(j=0;j<5;j++)
		{
			printf("%d ",myArray[i][j]);
		}
		printf("\n");
	}
	//printf("\n");

	system("pause");
}