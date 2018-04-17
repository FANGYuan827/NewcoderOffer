/*
2018��4��7��16:01:47
����һ���������飬�жϸ������ǲ���ĳ�����������ĺ�������Ľ����
����������Yes,�������No���������������������������ֶ�������ͬ��
*/
#include "iostream"
#include <vector>
using namespace std;

/*
˼·��
1����������������������С�ڸ���� �ҽ����ڸ����
2�����������������ĩ����Ǹ����
3����ĩ���ֿ��������������������֣����ж��������Ƿ�ȫ�����ڸ���� �� ��ݹ��ж����������������������Ƿ���϶���������
*/

class Solution_demo63 {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
		if(sequence.size()<1)
			return false;
		return VerifySquenceOfBST_SubTree(sequence,0,sequence.size()-1);
    }

private:
	bool VerifySquenceOfBST_SubTree(vector<int> &sequence,int start,int end)
	{
		if(start>=end)					//ֻʣһ������� ����Ҫ��  ���ݹ������������
			return true;

		int RootPos = 0;
		for(int i=RootPos;sequence[i]<sequence[end]&&RootPos<end-1;i++)
		{
			RootPos++;    //�ҵ����������ķֽ�λ��
		}
		for(int i=RootPos;i<end-1;i++)
		{
			if(sequence[i]<sequence[end])  
				return false;
		}
		return VerifySquenceOfBST_SubTree(sequence,start,RootPos-1)&&VerifySquenceOfBST_SubTree(sequence,RootPos,end-1);     //�ݹ���������ǹ̶������
	}
};


void main_demo63()
{
	Solution_demo63 s1;
	vector<int> input;
	input.push_back(4);
	input.push_back(8);
	input.push_back(6);
	input.push_back(12);
	input.push_back(16);
	input.push_back(14);
	input.push_back(10);

	bool res = false;
 	res = s1.VerifySquenceOfBST(input);
	if(res)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
	system("pause");
}