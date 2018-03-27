/*
2017��12��4��16:37:02��
��һ�������ʼ�����ɸ�Ԫ�ذᵽ�����ĩβ�����ǳ�֮Ϊ�������ת��
����һ���ǵݼ�����������һ����ת�������ת�������СԪ�ء� 
��������{3,4,5,1,2}Ϊ{1,2,3,4,5}��һ����ת�����������СֵΪ1�� 
NOTE������������Ԫ�ض�����0���������СΪ0���뷵��0��
*/
#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;
class Solution_1 
{
public:
	int minNumberInRotateArray(vector<int> rotateArray) 
	{
		if(rotateArray.empty())
		{
			return 0;
		}
		sort(rotateArray.begin(),rotateArray.end());    //���ַ�����ʱ�临�Ӷ�̫���� ��Ŀ���㲻�����...���ٲ���...
		return rotateArray[0];
	}
};

class Solution_2
{
public:
	int minNumberInRotateArray(vector<int> rotateArray) 
	{
		int flag = 0;
		if(rotateArray.empty())
		{
			return 0;
		}
		int length = rotateArray.size();
		for(int i =0;i<length-1;i++)
		{
			if(rotateArray[i]>rotateArray[i+1])
			{
				flag = i+1;
				break;
			}
		}
		return rotateArray[flag];
	}
};
/*
����˼·:
���ö��ַ����������⣬
mid = low + (high - low)/2
��Ҫ�������������
(1)Array[mid] > Array[high]:
�������������Array����[3,4,5,6,0,1,2]����ʱ��С����һ����mid���ұߡ�
low = mid + 1
(2)Array[mid] == Array[high]:
�������������Array���� [1,0,1,1,1] ����[1,1,1,0,1]����ʱ��С���ֲ����ж���mid���
�����ұ�,��ʱֻ��һ��һ���� ��
high = high - 1
(3)Array[mid] < Array[high]:
�������������Array����[2,2,3,4,5,6,6],��ʱ��С����һ������Array[mid]������mid����
�ߡ���Ϊ�ұ߱�Ȼ���ǵ����ġ�
high = mid
ע�������и��ӣ��������ѯ�ķ�Χ���ֻʣ����������ômid һ����ָ���±꿿ǰ������
���� Array = [4,6]
Array[low] = 4 ;Array[mid] = 4 ; Array[high] = 6 ;
���high = mid - 1���ͻ�������� ���high = mid
������(1)��low = mid + 1�Ͳ������
*/
class Solution_3      //���ַ�����.....  �������������ķ����ð�....
{
public:
	int minNumberInRotateArray(vector<int> rotateArray) 
	{
		if(rotateArray.empty())
		{
			return 0;
		}
		int left =0;
		int right = 0;
		int middle = 0;
		int length = rotateArray.size();
		right = length -1;
		while(left<right)
		{
			middle = left+(right-left)/2;
			if(rotateArray[middle]>rotateArray[right])
			{
				left = middle+1;
			}
			else
			{
				if(rotateArray[middle]==rotateArray[right])
				{
					right = right-1;
				}
				else
				{
					right = middle;
				}
			}
		}

		return rotateArray[left];
	}
};

void main_demo13()     //��Ҫ�����Ƕ��ַ�
{
	Solution_3 s1;
	vector<int>v1(6);
	v1[0] = 4;
	v1[1] = 4;
	v1[2] = 4;
	v1[3] = 4;
	v1[4] = 1;
	v1[5] = 2;
	cout<<"���Ϊ:"<<s1.minNumberInRotateArray(v1)<<endl;

	system("pause");
}