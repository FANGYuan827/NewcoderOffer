/*
2017年11月30日20:51:44：
用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。
*/
#include "iostream"
#include "stack"
using namespace std;

/*
 解题思想：始终将stack1作为存储内存区域，将stack2作为缓存区域，
 每一次元素入栈都直接压入stack1，如果要执行出栈操作，将stack1中的元素-1都出栈 在压入Stack2中
 弹出stack1中最后一个元素 再将Stack2 中的元素重新压入stack1中。
*/


//方法1
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

//方法2
/*
解题思路：
入栈时 直接将元素都压入stack1 
出栈时 先判断stack2是否为空：
①为空 表示元素都在stack1中，那就将stack1中的元素都倒入stack2中 然后将stack2的栈顶元素出栈
②不为空  就直接弹出stack2中的栈顶元素
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