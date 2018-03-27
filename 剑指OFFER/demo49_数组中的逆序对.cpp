/*
2018��3��6��21:07:27
�������е��������֣����ǰ��һ�����ִ��ں�������֣����������������һ������ԡ�
����һ������,�����������е�����Ե�����P��
����P��1000000007ȡģ�Ľ������� 
�����P%1000000007
����������
��Ŀ��֤�����������û�е���ͬ������

���ݷ�Χ��

����%50������,size<=10^4

����%75������,size<=10^5

����%100������,size<=2*10^5

ʾ��1��
����
1��2��3��4��5��6��7��0

�����

7

*/
#include "iostream"
#include <vector>
using namespace std;



/*
�Լ���˼· ��������ѭ����Ƕ�� �㷨���Ӷ�O(n^2) ����������ͨ��
���ϴ���˼·��
�鲢����
*/

/*
class Solution_demo49{
public:
	int InversePairs(vector<int> data) {
		if(data.size()<1)
			return 0;
		int count = 0;
		int count_1 = 0;
		int min_position = -1;
		int max_position = 0;
		int min = 40000;
		int max = data[0];
		int i = 0;
		while(count_1<data.size()-1)
		{
			for(i=0;i<data.size();i++)
			{
				if(min>=data[i]&&(data[i]!=-1)&&i!=min_position)
				{
					min = data[i];
					min_position = i;
					count+=min_position;
					data[i] = -1;              //�Ѿ��ҵ��ĵ���Сֵ��Ϊ-1;
				}
				if(data[i]==-1)
				{
					count_1++;
				}
			}
		}
		return count%1000000007;
	}
};
*/
class Solution_demo49_1{
public:
	int InversePairs(vector<int> data) {
		if(data.size()<1)
			return 0;
		int length = data.size();
		vector<int> copy;
		for(int i=0;i<length;i++)
		{
			copy.push_back(data[i]);
		}
		long long count = InversePairsCore(data,copy,0,length-1);
		return count%1000000007;
	}
private:
	long long InversePairsCore(vector<int> &data,vector<int> &copy,int start,int end)
	{
		if(start==end)
		{
			copy[start] = data[start];
			return 0;
		}
		int length = (end-start)/2;
		long long left = InversePairsCore(data,copy,start,start+length)%1000000007;     //ͳ����벿�ֵ����������   �ݹ����
		long long right = InversePairsCore(data,copy,start+length+1,end)%1000000007;    //ͳ���Ұ벿�ֵ����������

		int i = start+length;		 //ָ������������һ��Ԫ��
		int j = end;				//ָ������������һ��Ԫ��
		int indexcopy = end;
		long long count = 0;
		while(i>=start&&j>=start+length+1)
		{
			if(data[i]>data[j])                     //���if...else...�����Ϊ��ͳ������������֮������������
			{
				copy[indexcopy--] = data[i--];
				count += j-start-length;             //data[j]�Լ���ǰ������Ԫ�ص�����
				if(count>=1000000007)
					count%=1000000007;
			}
			else
			{
				copy[indexcopy--] = data[j--];
			}
		}
		for(;i>=start;i--)
			copy[indexcopy--] = data[i];
		for(;j>=start+length+1;j--)		//
			copy[indexcopy--] = data[j];
		for(int i=start;i<=end;i++)
		{
			data[i] = copy[i];
		}
		return (left+right+count)%1000000007;
	}
};

void main_demo49()
{
	Solution_demo49_1 s1;
	int res = 0;
	vector<int>v_input;
	v_input.push_back(1);
	v_input.push_back(2);
	v_input.push_back(3);
	v_input.push_back(7);
	v_input.push_back(5);
	v_input.push_back(6);
	v_input.push_back(4);
	v_input.push_back(0);
    res = s1.InversePairs(v_input);
	cout<<"����������Ե�����Ϊ��"<<res<<endl;
	system("pause");
}