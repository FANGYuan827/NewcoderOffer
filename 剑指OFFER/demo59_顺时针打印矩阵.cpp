/*
2018��4��4��15:14:14
����һ�����󣬰��մ���������˳ʱ���˳�����δ�ӡ��ÿһ�����֣�
���磬����������¾��� 
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 
�����δ�ӡ������1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.
*/

#include "iostream"
#include <vector>
using namespace std;

class Solution_demo59 {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
		vector<int>res_v;
		if(matrix.size()<1)
			return res_v;
		int col = matrix.size();      //�õ�����
		int len = matrix[0].size();   //�õ�����
		if(col==1)
		{
			for(int j=0;j<len;j++)
				res_v.push_back(matrix[0][j]);
			return res_v;
		}
		if(len==1)
		{
			for(int i=0;i<col;i++)
				res_v.push_back(matrix[i][0]);
			return res_v;
		}
		int i = 0,j = 0;
		int start_row=0,start_col=0,end_row=col-1,end_col=len-1;    //start_row ��ʼ�� start_col��ʼ��  end_row������  end_col������
 		for(;start_row<=end_row&&start_col<=end_col;)
		{
			for(j=start_col;j<=end_col;j++)
			{
				res_v.push_back(matrix[start_row][j]);
			}
			start_row++;
			if(start_row>end_row)
			{
				break;
			}
			for(i=start_row;i<=end_row;i++)
			{
				res_v.push_back(matrix[i][end_col]);
			}
			end_col--;

			for(j=end_col;j>=start_col;j--)
			{
				res_v.push_back(matrix[end_row][j]);
			}
			end_row--;
			for(i=end_row;i>=start_row;i--)
			{
				res_v.push_back(matrix[i][start_col]);
			}
			start_col++;
		}
		return res_v;
    }
};

void main_demo59()
{
	Solution_demo59 s1;
	vector<vector<int> >input;
	vector<int>v_tmp;
	vector<int>res;
	for(int i=0;i<15;i++)
	{
		v_tmp.push_back(i+1);
		if((i+1)%5==0)
		{
			input.push_back(v_tmp);
			v_tmp.clear();
		}
	}
	res = s1.printMatrix(input);
	vector<int>::iterator it;
	for(it=res.begin();it!=res.end();it++)
	{
		cout<<*it<<ends;
	}
	cout<<endl;
	system("pause");
}