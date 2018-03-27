/*
2018年3月14日15:39:48
地上有一个m行和n列的方格。
一个机器人从坐标0,0的格子开始移动，
每一次只能向左，右，上，下四个方向移动一格，但是不能进入行坐标和列坐标的数位之和大于k的格子。
例如，当k为18时，机器人能够进入方格（35,37），因为3+5+3+7 = 18。
但是，它不能进入方格（35,38），因为3+5+3+8 = 19。请问该机器人能够达到多少个格子？
*/
#include "iostream"
#include <vector>
using namespace std;

/*
解题思路：回溯算法
从坐标(0，0)开始 然后定义一个bool数组 来标记当前格子是否属于可以进入的格子 
采用回溯算法，从当前格子出发，如果当前格子可以到达 再进一步判断这个格子的上下左右的四个格子是否能够到达  每判断一个格子可以到达 那么就将bool数组相应元素置位true.
还要对格子坐标的有效性进行判断 坐标不合适 直接返回 false 
bool new 出来之后已经被进行了初始化 为false;
然后统计bool数组中元素值为 true 的个数即为机器人能够进入的格子数
*/

class Solution_demo52 {
public:
	int movingCount(int threshold, int rows, int cols)
	{
		bool *flag= new bool[rows*cols]();  
		int total = 0;
		Canreach(threshold,rows,cols,0,0,flag);    //从（0,0）开始
		for(int i=0;i<rows*cols;++i)
		{
			if(flag[i]==true)
				++total;
		}
		if(flag!=NULL)
		{
			free(flag);
			flag = NULL;
		}
		return total;
	}
private:
	vector<int> GetBit(int num)
	{
		vector<int>v_res;
		if(num<10&&num>=0)       //个位数直接返回即可 
		{
			v_res.push_back(num);
			return v_res;
		}
		while(num>0)                //一开始就是这个地方写错了 写成了while(n/10>0) 导致在取num的每一位的时候 会漏掉最高位
		{
			v_res.push_back(num%10);
			num/=10;
		}
		return v_res;
	}
	///////
	bool isOk(vector<int>&input1,vector<int>&input2,int threshold)
	{
		if(input1.size()<1||input2.size()<1||threshold<0)
		{
			return false;
		}
		int total = 0;
		vector<int>::iterator it;
		for(it=input1.begin();it!=input1.end();++it)
		{
			total+=*it;
		}
		for(it=input2.begin();it!=input2.end();++it)
		{
			total+=*it;
		}
		if(total>threshold)
			return true;
		return false;
	}
	//////
	bool Canreach(int threshold, int rows, int cols,int curx,int cury,bool *flag)
	{
		if(curx>=rows||curx<0||cury>=cols||cury<0)
		{
			return false;
		}
		vector<int>v_curx,v_cury;
		v_curx = GetBit(curx);
		v_cury = GetBit(cury);
		if(isOk(v_curx,v_cury,threshold)||flag[curx*cols+cury])
			return false;
		v_curx.clear();
		v_cury.clear();
		flag[curx*cols+cury] = true;
		bool sign =  Canreach(threshold,rows,cols,curx-1,cury,flag)||\
			Canreach(threshold,rows,cols,curx+1,cury,flag)||\
			Canreach(threshold,rows,cols,curx,cury-1,flag)||\
			Canreach(threshold,rows,cols,curx,cury+1,flag);
		return sign;
	}
};


void main_demo52()
{
	Solution_demo52 s1;
	int res = 0;
	res = s1.movingCount(15,20,20);
	cout<<"该机器人能够到达的格子为："<<res<<endl;
	system("pause");
}