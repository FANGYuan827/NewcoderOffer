/*
2018��4��11��22:01:19
��εõ�һ���������е���λ����
������������ж�����������ֵ����ô��λ������������ֵ����֮��λ���м����ֵ��
������������ж���ż������ֵ����ô��λ������������ֵ����֮���м���������ƽ��ֵ��
*/
#include "iostream"
#include <queue>
#include <vector>
#include <string>
using namespace std;

//Ϊʲô�öѣ���ʵ���ǽ��������ֳ��������֣����м��з֣�����������������������������󶥶�������С��һ�� С�������Ǵ��һ��
//            ������λ��ʱ��ֻ��Ҫ�����м��һ�������������� ���ǹ��ĵ������ǶѶ�����
/*
����������˼·��
1��ֱ�Ӳ��뵽����У�֮�������ѳߴ�֮�����1��Ҳ����2������Ӵ���е���ջ��Ԫ�ز����뵽С����
   ������֮�����1 ��ֱ�Ӳ������м���

2�������������뵽����У�ż���������뵽С���У�
   ���� ���ܻ���ֵ�ǰ���������С�ѶѶ�Ԫ�ش󣬴�ʱ��Ҫ��Ԫ���Ȳ��뵽С�ѣ�Ȼ��С�ѶѶ�Ԫ�ص�������������
   
   ����ż��ʱ����С�ѵ������һ���ĵ���
   Ҫ��֤��ѵ�Ԫ��Ҫ��С����С��Ԫ�ض�ҪС��
*/
class Solution_demo67 {
public:
    void Insert(int num)
    {
		count+=1;
		if(count%2==0)   /*	����������Ϊż��ʱ���¼����Ԫ��Ӧ������С����
		��ע�⣺����ֱ�ӽ���С���ѣ����Ǿ����󶥶�ɸѡ��ȡ�󶥶��е����Ԫ�ؽ���С���ѣ�*/
		{
			big_heap.push(num);     //1���¼����Ԫ�����뵽�󶥶� �ɴ󶥶�ɸѡ����������Ԫ��
			small_heap.push(big_heap.top());   //2��ɸѡ��ġ��󶥶��е����Ԫ�ء�����С����
			big_heap.pop();
		}
		else           /* ����������Ϊ����ʱ���¼����Ԫ�أ�Ӧ���ǽ��뵽�󶥶�
					   ��ע�⣺����ֱ�ӽ���󶥶ѣ����Ǿ���С����ɸѡ��ȡС������С��Ԫ�ؽ���󶥶ѣ�*/
		{
			small_heap.push(num);     //1���¼����Ԫ�����뵽С���� ��С����ɸѡ�����е���СԪ��
			big_heap.push(small_heap.top());//2��ɸѡ��ġ�С�����е���СԪ�ء����뵽�󶥶�
			small_heap.pop();
		}
    }
    double GetMedian()
    { 
		if(count&0x1)           //�������
		{
			return big_heap.top();
		}
		else				  //ż�����
		{
			return double((small_heap.top()+big_heap.top())/2.0);
		}
    }
	Solution_demo67(int x):count(x){               //���캯��+��ʼ���б�
	}
private:
	priority_queue<int,vector<int>,less<int> > big_heap;        //���һ���󶥶�  -->>>��������
	priority_queue<int,vector<int>,greater<int> > small_heap;   //�ұ�һ��С����  -->>>��������
	int count ;
	//�󶥶�����Ԫ�ؾ�С��С���ѵ�����Ԫ�� 
};


/*
˼·1�Ĵ��룺 
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
	priority_queue<int>q;   //Ĭ����������ǽ���ķ��ڶ�����λ�� ������
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
	
	friend bool operator< (student s1,student s2)     //�����������غ���û�ж��� ������벻ͨ��
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
	priority_queue<student,vector<student>,Cmp>student_q;    //��ô���岻�� ������벻ͨ��
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

