/*
2018年2月28日10:21:19
定义栈的数据结构，请在该类型中实现一个能够得到栈最小元素的min函数。
*/
#include "iostream"
using namespace std;
/*
struct My_Stack
{
	int val;
	struct My_Stack *next;
	My_Stack(int x):val(0),next(NULL){

	}
};
*/
class Solution {
public:
    void push(int value) 
	{
		if(count>=length)
		{
			cout<<"栈内存已满"<<endl;
			return;
		}
		*(tmp+count) = value;
		++count;
	}
    void pop()    //出栈
	{
		int i = 0;
        //static int c_i = ++i;
		for(i = 9-1;i>0;i--)
		{
			tmp[i] = tmp[i-1];
		}
		--count;
    }
    int top()    //获取栈顶元素
	{
		if(count>0)
			return tmp[9-1];
		else
			return 0;
    }
    int min() 
	{
        int i =0;
		int tmp_num = tmp[0];
		for(i=0;i<count;i++)
		{
			if(tmp_num>tmp[i])
			{
				tmp_num = tmp[i];
			}
		}
		return tmp_num;
    }
	Solution()
	{
		count = 0;
		length = 10;
		tmp = (int *)malloc(sizeof(int)*length);
		if(tmp==NULL)
		{
			cout<<"内存申请失败"<<endl;
			return;
		}
	}

public:
    int count;
	//int num;
private:
	int *tmp;
	int length;
};


void main_demo35()
{
	Solution s1;
	s1.push(1);
	s1.push(13);
	s1.push(12);
	s1.push(100);
	s1.push(55);
	s1.push(-1);
	s1.push(-200);
	s1.push(7);
	s1.push(10);
	int res = s1.min();
	int top = s1.top();
	cout<<"栈中最小的元素值为:"<<res<<endl;
	cout<<"栈顶元素为："<<top<<endl;
	while(s1.count!=0)
	{
		int res_num = s1.top();
		cout<<res_num<<endl;
		s1.pop();
	}
	system("pause");
}