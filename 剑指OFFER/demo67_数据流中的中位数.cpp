/*
2018年4月11日22:01:19
如何得到一个数据流中的中位数？
如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。
如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。
*/
#include "iostream"
#include <queue>
#include <vector>
#include <string>
using namespace std;

//为什么用堆？其实就是将数据流分成两个部分，从中间切分（特殊情况：数据流有序的情况），大顶堆里面是小的一半 小顶堆中是大的一半
//            当求中位数时，只需要关心中间的一个数或者两个数 这是关心的数就是堆顶的数
/*
插入有两种思路：
1、直接插入到大堆中，之后若两堆尺寸之差大于1（也就是2），则从大堆中弹出栈顶元素并插入到小堆中
   若两堆之差不大于1 则直接插入大堆中即可

2、奇数个数插入到大堆中，偶数个数插入到小堆中，
   但是 可能会出现当前插入的数比小堆堆顶元素大，此时需要将元素先插入到小堆，然后将小堆堆顶元素弹出并插入大堆中
   
   对于偶数时插入小堆的情况，一样的道理，
   要保证大堆的元素要比小堆最小的元素都要小。
*/
class Solution_demo67 {
public:
    void Insert(int num)
    {
		count+=1;
		if(count%2==0)   /*	当数据总数为偶数时，新加入的元素应当进入小顶堆
		（注意：不是直接进入小顶堆，而是经过大顶堆筛选后取大顶堆中的最大元素进入小顶堆）*/
		{
			big_heap.push(num);     //1、新加入的元素先入到大顶堆 由大顶堆筛选出堆中最大的元素
			small_heap.push(big_heap.top());   //2、筛选后的【大顶堆中的最大元素】进入小顶堆
			big_heap.pop();
		}
		else           /* 当数据总数为奇数时，新加入的元素，应当是进入到大顶堆
					   （注意：不是直接进入大顶堆，而是经过小顶堆筛选后取小顶堆最小的元素进入大顶堆）*/
		{
			small_heap.push(num);     //1、新加入的元素先入到小顶堆 由小顶堆筛选出堆中的最小元素
			big_heap.push(small_heap.top());//2、筛选后的【小顶堆中的最小元素】进入到大顶堆
			small_heap.pop();
		}
    }
    double GetMedian()
    { 
		if(count&0x1)           //奇数情况
		{
			return big_heap.top();
		}
		else				  //偶数情况
		{
			return double((small_heap.top()+big_heap.top())/2.0);
		}
    }
	Solution_demo67(int x):count(x){               //构造函数+初始化列表
	}
private:
	priority_queue<int,vector<int>,less<int> > big_heap;        //左边一个大顶堆  -->>>降序排列
	priority_queue<int,vector<int>,greater<int> > small_heap;   //右边一个小顶堆  -->>>升序排列
	int count ;
	//大顶堆所有元素均小于小顶堆的所有元素 
};


/*
思路1的代码： 
class Solution {
    priority_queue<int, vector<int>, less<int> > p;
    priority_queue<int, vector<int>, greater<int> > q;
     
public:
    void Insert(int num){
        if(p.empty() || num <= p.top()) p.push(num);
        else q.push(num);
        if(p.size() == q.size() + 2) q.push(p.top()), p.pop();
        if(p.size() + 1 == q.size()) p.push(q.top()), q.pop();
    }
    double GetMedian(){ 
      return p.size() == q.size() ? (p.top() + q.top()) / 2.0 : p.top();
    }
};
*/
void main_demo67()
{
	priority_queue<int>q;   //默认情况下总是将大的放在队列首位置 （降序）
	priority_queue<int,vector<int>,greater<int> >small_queue;
	for(int i=0;i<10;++i)
	{
		q.push(i);
	}
	while(!q.empty())
	{
		cout<<q.top()<<ends;
		q.pop();
	}
	cout<<endl;
	system("pause");
}


struct student{
	int grade;
	string name;
	
	friend bool operator< (student s1,student s2)     //如果运算符重载函数没有定义 程序编译不通过
	{
		return s1.grade < s2.grade ;
	}

};

struct Cmp{
	bool operator()(student s1,student s2)
	{
		return s1.name > s2.name;
	}
};


void test()
{
	priority_queue<student,vector<student>,Cmp>student_q;    //这么定义不行 程序编译不通过
	//priority_queue<student>student_q;

	student s1,s2,s3;
	s1.grade = 90;
	s1.name = "Bob";

	s2.grade = 98;
	s2.name = "Mary";

	s3.grade = 80;
	s3.name = "CoCo";

	student_q.push(s1);
	student_q.push(s2);
	student_q.push(s3);

	while(!student_q.empty())
	{
		cout<<student_q.top().name<<":"<<student_q.top().grade<<endl;
		student_q.pop();
	}
}

void main_demo01()
{
	test();
	system("pause");
}

