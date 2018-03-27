#include "iostream"
#include "vector"
using namespace std;
/*
class Solution_1204 {
public:
void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
if(data.empty()||num1==NULL||num2==NULL)
{
return ;
}
int length = data.size();
int result = 0;
for(int i = 0;i<length;i++)
{
result ^= data[i];
}
*num1 = result;
}
};
*/
/*
class Solution_1204_2{
public: void FindNumsAppearOnce(vector<int>Array,int *num1, int *num2) 
{
if(Array.empty()||Array.size()<2)
return ;
int temp = 0;
for(int i=0;i<Array.size();i++)
temp ^= Array[i];

int indexOf1 = findFirstBitIs(temp);
for(int i=0;i<Array.size();i++)
{
if(isBit(Array[i], indexOf1))
*num1^=Array[i];
else
*num2^=Array[i];
}
}
public: int findFirstBitIs(int Num)
{
int indexBit = 0;
while(((Num & 1)==0) && (indexBit)<8*4){
Num = Num >> 1;
++indexBit;
}
return indexBit;
}
public: bool isBit(int Num,int indexBit)
{
Num = Num >> indexBit;
return (Num & 1) == 1;
}

};
*/

/*
�㷨˼�룺
������λ����ʵ�֣������������������� �����Ľ���϶���������ֻ����һ�ε��������Ľ��
���Ը������Ľ��1���ڵ����λ �����ֳַ����� ÿһ���ﶼ����ֻ����һ�ε����ݺͳɶԳ��ֵ�����
����������ÿһ�����������Էֱ��������ֻ����һ�ε�����
*/
class Solution_1204_3 {
public:
	void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) 
	{
		if(data.size()<2)
			return ;
		int size=data.size();
		int temp=data[0];
		for(int i=1;i<size;i++)
			temp=temp^data[i];
		if(temp==0)
			return ;
		int index=0;
		while((temp&1)==0)
		{
			temp=temp>>1;
			++index;
		}
		*num1=*num2=0;
		for(int i=0;i<size;i++)    //����indexλ�ϵ������ǲ���1 ������ֳ����������� �ٷֱ������� ���õ�����ֻ����һ�ε�������......
		{
			if(IsBit(data[i],index))
				*num1^=data[i];
			else
				*num2^=data[i];
		}
	}
	bool IsBit(int num,int index)
	{
		num=num>>index;
		return (num&1);
	}
};
void main_demo12_2()
{
	/*
	Solution_1204 s1;
	vector<int>Num(8);
	int result1,result2;
	//Num = [2,4,3,6,3,2,5,5];
	Num[0] = 2;
	Num[1] = 2;
	Num[2] = 2;
	Num[3] = 2;
	Num[4] = 2;
	Num[5] = 2;
	Num[6] = 2;
	Num[7] = 3;
	//Num[8] = 3;

	s1.FindNumsAppearOnce(Num,&result1,&result2);
	cout<<"�����:"<<result1<<endl;
	*/
	Solution_1204_3 s1;
	vector<int>Num(8);
	int result1,result2;
	//Num = [2,4,3,6,3,2,5,5];
	Num[0] = 1;
	Num[1] = 2;
	Num[2] = 2;
	Num[3] = 2;
	Num[4] = 2;
	Num[5] = 2;
	Num[6] = 2;
	Num[7] = 3;
	s1.FindNumsAppearOnce(Num,&result1,&result2);
	cout<<"�����:"<<result1<<"  "<<result2<<endl;


	system("pause");
}