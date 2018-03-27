/*
2018年3月5日08:45:57
小明很喜欢数学,有一天他在做数学作业时,要求计算出9~16的和,他马上就写出了正确答案是100。
但是他并不满足于此,他在想究竟有多少种连续的正数序列的和为100(至少包括两个数)。
没多久,他就得到另一组连续正数和为100的序列:18,19,20,21,22。
现在把问题交给你,你能不能也很快的找出所有和为S的连续正数序列?
Good Luck!


输出描述:
输出所有和为S的连续正数序列。序列内按照从小至大的顺序，序列间按照开始数字从小到大的顺序
*/


#include "iostream"
#include <vector>
using namespace std;


/*
解题思路：
用两个数字start、end分别表示序列的最大值和最小值
首先将start初始化1 end初始化2
如果从begin到end的和大于S 就从序列中去掉较小的值（start++）（减少项数）
如果从begin到end的和小于S 就增加序列的最大值（end++）（增加项数）
*/
class Solution_demo42 {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int> >v_res;     //二维数组
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