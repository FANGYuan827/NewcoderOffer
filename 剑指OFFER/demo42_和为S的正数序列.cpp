/*
2018��3��5��08:45:57
С����ϲ����ѧ,��һ����������ѧ��ҵʱ,Ҫ������9~16�ĺ�,�����Ͼ�д������ȷ����100��
���������������ڴ�,�����뾿���ж������������������еĺ�Ϊ100(���ٰ���������)��
û���,���͵õ���һ������������Ϊ100������:18,19,20,21,22��
���ڰ����⽻����,���ܲ���Ҳ�ܿ���ҳ����к�ΪS��������������?
Good Luck!


�������:
������к�ΪS�������������С������ڰ��մ�С�����˳�����м䰴�տ�ʼ���ִ�С�����˳��
*/


#include "iostream"
#include <vector>
using namespace std;


/*
����˼·��
����������start��end�ֱ��ʾ���е����ֵ����Сֵ
���Ƚ�start��ʼ��1 end��ʼ��2
�����begin��end�ĺʹ���S �ʹ�������ȥ����С��ֵ��start++��������������
�����begin��end�ĺ�С��S ���������е����ֵ��end++��������������
*/
class Solution_demo42 {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int> >v_res;     //��ά����
		vector<int>v_tmp;
		if(sum<3)
		{
			return v_res;
		}
		int start = 1;
		int end = 2;
		while(start<=(1+sum)/2&&end<sum)
		{
			int sum_tmp = (start+end)*(end-start+1)/2;
			if(sum_tmp==sum)
			{
				int start_tmp = start;
				while(start_tmp<=end)
				{
					v_tmp.push_back(start_tmp++);
				}
				v_res.push_back(v_tmp);
				v_tmp.clear();
				start++;
			}
			else
			{
				if(sum_tmp>sum)
				{
					start++;
				}
				if(sum_tmp<sum)
				{
					end++;
				}
			}
		}
		return v_res;
    }
};



void main_demo42()
{

	Solution_demo42 s1;
	vector<vector<int> > v_res;
	v_res = s1.FindContinuousSequence(100);
	vector<vector<int>>::iterator it;
	for(it = v_res.begin();it!=v_res.end();it++)
	{
		for(int i=0;i<it->size();i++)
		{
			cout<<(*it)[i]<<ends;  //
		}
		cout<<endl;
	}
	system("pause");
}