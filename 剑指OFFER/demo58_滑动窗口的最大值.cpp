/*
2018年4月3日19:15:34
给定一个数组和滑动窗口的大小，
找出所有滑动窗口里数值的最大值。
例如，如果输入数组{2,3,4,2,6,2,5,1}及滑动窗口的大小3，
那么一共存在6个滑动窗口，他们的最大值分别为{4,4,6,6,6,5}； 
针对数组{2,3,4,2,6,2,5,1}的滑动窗口有以下6个：
{[2,3,4],2,6,2,5,1}， {2,[3,4,2],6,2,5,1}， {2,3,[4,2,6],2,5,1}， {2,3,4,[2,6,2],5,1}， {2,3,4,2,[6,2,5],1}， {2,3,4,2,6,[2,5,1]}。
*/


#include "iostream"
#include <vector>
#include <deque>
#include <queue>
using namespace std;

class Solution_demo58 {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
		vector<int> res_v;
		if(num.size()<=1||size==1)
			return num;
		int count = GetWindowsNum(num,size);
		for(int i=0;i<count;i++)
		{
			int max = getMax(num,i,i+size-1);
			res_v.push_back(max);
		}
		return res_v;
    }
private:
	int GetWindowsNum( const vector<int>&num,unsigned int size)
	{
		if(size>num.size())
			return 0;
		int count = 0;
		int length = num.size();
		int pre = 0,current = size-1;
		for(;current<length;current++)
		{
			++count;
		}
		return count;
	}
	int getMax(const vector<int>&num, int start,int end)
	{
		if(start>=end)
			return 0;
		int max_tmp = num[start];
		while(start<=end)
		{
			if(max_tmp<num[start])
				max_tmp = num[start];
			++start;
		}
		return max_tmp;
	}
};
/*
链接：https://www.nowcoder.com/questionTerminal/1624bc35a45c42c0bc17d17fa0cba788
来源：牛客网

//时间复杂度o（n），空间复杂度为o（n）
      思路就是采用双端队列，队列中的头节点保存的数据比后面的要大。
      比如当前假如的数据比队尾的数字大，说明当前这个数字最起码在从现在起到后面的过程中可能是最大值
      ，而之前队尾的数字不可能最大了，所以要删除队尾元素。
      此外，还要判断队头的元素是否超过size长度，由于存储的是下标，所以可以计算得到；
      特别说明，我们在双端队列中保存的数字是传入的向量的下标；
*/
class Solution_demo58_2{
public:
	 vector<int> maxInWindows(const vector<int>& num, unsigned int size)
	 {
		 vector<int>res_v;
		 if(num.size()<=0||num.size()<size||size<=0)
			 return res_v;
		 deque<int> dq;
		 for(unsigned int i=0;i<size;i++)    //这个for循环处理前size个元素
		 {
			 while(!dq.empty()&&num[i]>=num[dq.back()])
			 {
				 dq.pop_back();          //弹出队尾元素
			 }
			 dq.push_back(i);       //将数组元素的下标入队列
		 }
		 for(unsigned int i=size;i<num.size();i++) //处理size之后的元素
		 {
			 res_v.push_back(num[dq.front()]);
			 while(!dq.empty()&&num[i]>=num[dq.back()])
			 {
				 dq.pop_back();
			 }
			 if(!dq.empty()&&dq.front()<=(int)(i-size))
			 {
				 dq.pop_front();				//超出窗口值
			 }
			 dq.push_back(i);
		 }
		 res_v.push_back(num[dq.front()]);
		 return res_v;
	 }

};
void main_demo58()
{
	//Solution_demo58 s1;
	Solution_demo58_2 s1;
	vector<int> input;
	input.push_back(2);
	input.push_back(3);
	input.push_back(4);
	input.push_back(2);
	input.push_back(6);
	input.push_back(2);
	input.push_back(5);
	input.push_back(1);
	vector<int>res_v;
	res_v = s1.maxInWindows(input,3);
	vector<int>::iterator it;
	for(it = res_v.begin();it!=res_v.end();it++)
	{
		cout<<*it<<ends;
	}
	cout<<endl;
	system("pause");
}

