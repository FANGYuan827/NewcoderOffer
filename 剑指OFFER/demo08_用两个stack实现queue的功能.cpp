/*
2017��11��30��20:51:44��
������ջ��ʵ��һ�����У���ɶ��е�Push��Pop������ �����е�Ԫ��Ϊint���͡�
*/
#include "iostream"
#include "stack"
using namespace std;

/*
 ����˼�룺ʼ�ս�stack1��Ϊ�洢�ڴ����򣬽�stack2��Ϊ��������
 ÿһ��Ԫ����ջ��ֱ��ѹ��stack1�����Ҫִ�г�ջ��������stack1�е�Ԫ��-1����ջ ��ѹ��Stack2��
 ����stack1�����һ��Ԫ�� �ٽ�Stack2 �е�Ԫ������ѹ��stack1�С�
*/


//����1
class Solution1
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        int count = stack1.size();
        while(stack1.size()!=1)
        {
            int tmp1 = stack1.top();
            stack2.push(tmp1);
            stack1.pop();
        }
        int result = stack1.top();
        stack1.pop();
        while(stack2.size()!=0)
        {
            int tmp2 = stack2.top();
            stack1.push(tmp2);
            stack2.pop();
        }
        return result;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};

//����2
/*
����˼·��
��ջʱ ֱ�ӽ�Ԫ�ض�ѹ��stack1 
��ջʱ ���ж�stack2�Ƿ�Ϊ�գ�
��Ϊ�� ��ʾԪ�ض���stack1�У��Ǿͽ�stack1�е�Ԫ�ض�����stack2�� Ȼ��stack2��ջ��Ԫ�س�ջ
�ڲ�Ϊ��  ��ֱ�ӵ���stack2�е�ջ��Ԫ��
*/
class Solution2
{
public:
    void push(int node) {
		stack1.push(node);
 
    }

    int pop() {
		if(stack2.empty())
		{
			while(!stack1.empty())
			{
				int tmp = stack1.top();
				stack2.push(tmp);
				stack1.pop();
			}
			int result1 = stack2.top();
			stack2.pop();
			return result1;
		}
		else
		{
			int result2 = stack2.top();
			stack2.pop();
			return result2;
		}
        
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};


void main_demo08()
{
	/*
	Solution1 s1;
	s1.push(999);
	s1.push(2);
	s1.push(3);
	s1.push(4);
	s1.push(5);
	cout<<s1.pop()<<endl;
	cout<<s1.pop()<<endl;
	cout<<s1.pop()<<endl;
	cout<<s1.pop()<<endl;
	cout<<s1.pop()<<endl;
	*/

	Solution2 s2;
	s2.push(999);
	s2.push(2);
	cout<<s2.pop()<<endl;
	s2.push(3);
	s2.push(4);
	s2.push(5);
	
	cout<<s2.pop()<<endl;
	cout<<s2.pop()<<endl;
	cout<<s2.pop()<<endl;
	cout<<s2.pop()<<endl;
	cout<<9/2<<endl;

	system("pause");
}