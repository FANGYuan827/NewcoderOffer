/*
2018年3月5日15:49:45
LL今天心情特别好,因为他去买了一副扑克牌,
发现里面居然有2个大王,2个小王(一副牌原本是54张^_^)...
他随机从中抽出了5张牌,想测测自己的手气,看看能不能抽到顺子,
如果抽到的话,他决定去买体育彩票,嘿嘿！！
“红心A,黑桃3,小王,大王,方片5”,“Oh My God!”
不是顺子.....LL不高兴了,他想了想,决定大\小 王可以看成任何数字,并且A看作1,J为11,Q为12,K为13。
上面的5张牌就可以变成“1,2,3,4,5”(大小王分别看作2和4),
“So Lucky!”。
LL决定去买体育彩票啦。
现在,要求你使用这幅牌模拟上面的过程,然后告诉我们LL的运气如何。
为了方便起见,你可以认为大小王是0。
*/
#include "iostream"
#include <vector>
using namespace std;

/*
傻瓜式的解法 将所有解法都穷举出来了 然后利用多分支结构
*/
class Solution_demo45 {
public:
	bool IsContinuous( vector<int> numbers ) {
		if(numbers.size()!=5)
			return false;
		int count = NumberOf0(numbers);
		int min = Min(numbers);
		int max = Max(numbers);
		int sum = Sum(numbers);
		switch(count)
		{
		case 0:
			{
				if(max-min==4)
				{
					if(sum==5*min+10)
						return true;
					else
						return false;
				}
				else
				{
					return false;
				}
				break;
			}
		case 1:
			{
				if(max-min==3||max-min==4)
				{
					if(sum>=4*min+6&&sum<=4*min+9)
						return true;
					else
						return false;
				}
				else
				{
					return false;
				}
				break;
			}
		case 2:
			{
				if(max-min>=2&&max-min<=4)
				{
					if(sum>=3*min+3&&sum<=3*min+7)
						return true;
					else
						return false;
				}
				else
				{
					return false;
				}
				break;
			}
		case 3:
			{
				if(max-min>=1&&max-min<=4)
				{
					if(sum>=2*min+1&&sum<=2*min+4)
						return true;
					else
						return false;
				}
				else
				{
					return false;
				}
				break;
			}
		case 4:
			{
				return true;
				break;
			}
		default:break;
		}
		return false;
	}
private:
	int Min(vector<int>input)
	{
		int min = 100;
		for(unsigned int i=0;i<input.size();i++)
		{
			if(min>input[i]&&input[i]!=0)
				min = input[i];
		}
		return min;
	}
	int Max(vector<int>input)
	{
		int max = input[0];
		for(unsigned int i=1;i<input.size();i++)
		{
			if(max<input[i])
				max = input[i];
		}
		return max;
	}
	int Sum(vector<int>input)
	{
		int sum = 0;
		for(unsigned int i=0;i<input.size();i++)
		{
			sum+=input[i];
		}
		return sum;
	}
	int NumberOf0(vector<int>input)
	{
		int count = 0;
		for(unsigned int i=0;i<input.size();i++)
		{
			if(input[i]==0)
				++count;
		}
		return count;
	}
};

/*
网上的解法思路：
是顺子所满足的条件：
1、除0以外 没有重复的数字
2、max-min<=5(这里的min和max是不包括0的)
*/
class Solution_demo45_1 {
public:
	bool IsContinuous( vector<int> numbers ) {
		if(numbers.size()!=5)
		{
			return false;
		}
		int *flag = new int[14];
		memset(flag,0,14);
		int min = 14;
		int max = -1;
		for(unsigned int i=0;i<numbers.size();i++)
		{
			flag[numbers[i]]++;
			if(numbers[i]==0)
				continue;
			if(min>numbers[i])
			{
				min = numbers[i];
			}
			if(max<numbers[i])
			{
				max = numbers[i];
			}
			if(flag[numbers[i]]>1&&numbers[i]!=0)
			{
				return false;
			}
		}
		if(max-min>=5)
		{
			return false;
		}
		return true;

	}

};
void main_demo45()
{
	Solution_demo45_1 s1;
	vector<int>vec_input;

	vec_input.push_back(0);
	vec_input.push_back(0);
	vec_input.push_back(0);
	vec_input.push_back(0);
	vec_input.push_back(4);
	bool res = s1.IsContinuous(vec_input);
	if(res == false)
		cout<<"不是顺子"<<endl;
	else
		cout<<"是顺子"<<endl;
	system("pause");
}



