/*
2017年12月6日20:25:12：
输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。
*/

#include "iostream"
using namespace std;


struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
	val(x), next(NULL) {
	}
};
/*
遍历的思想 但是就是最后的尾巴处理不好 总是会漏 代码的鲁棒性太差了...... 
*/
class Solution_my {
public:
	ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
	{
		if(pHead1==NULL&&pHead2==NULL)        //异常处理
		{
			return NULL;
		}
		if(pHead1==NULL)
		{
			return pHead2;
		}
		if(pHead2==NULL)
		{
			return pHead1;
		}
		ListNode *tmp1 = pHead1;
		ListNode *tmp2 = pHead2;
		ListNode *result = NULL;
		ListNode *final_result = NULL;
		while(tmp1!=NULL&&tmp2!=NULL)
		{

			if(tmp2->val<=tmp1->val)
			{
				if(result!=NULL)
				{
					result->next = tmp2;          
					result = tmp2;
				}
				else
				{
					result = tmp2;
					final_result = result;
				}
				tmp2 = tmp2->next;
			}
			else
			//if(tmp2->val>=tmp1->val)
			{
				if(result!=NULL)
				{
					result->next = tmp1;         					
					result = tmp1;
				}
				else
				{
					result = tmp1;
					final_result = result;
				}
				tmp1 = tmp1->next;
			}
		}
		if(tmp1==NULL)   //表明链表1已经全部遍历完了
		{
			result->next = tmp2;
		}
		else                  //表明链表2已经全部遍历完了
		{
			result->next = tmp1;
		}
		return final_result;
	}
};

//递归的思想
class Solution{
public:
	ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
	{
		if(pHead1==NULL)
		{
			return pHead2;
		}
		if(pHead2==NULL)
		{
			return pHead1;
		}
		if(pHead1->val<=pHead2->val)
		{
			pHead1->next = Merge(pHead1->next,pHead2);
			return pHead1;
		}
		else
		{
			pHead2->next = Merge(pHead1,pHead2->next);
			return pHead2;
		}
	}

};

void main_demo17()
{
	Solution_my s1;
	struct ListNode *result = NULL;
	/*
	struct ListNode l1(1),l2(3),l3(5),l7(7);
	struct ListNode l4(2),l5(4),l6(6),l8(8);
	//struct ListNode l1(1),l2(2),l3(3),l7(3);
	//struct ListNode l4(4),l5(5),l6(666),l8(888);
	
	l1.next = &l2;
	l2.next = &l3;
	l3.next = &l7;

	l4.next = &l5;
	l5.next = &l6;
	l6.next = &l8;
	*/
	struct ListNode l1(1),l4(2);
 	result=s1.Merge(&l1,&l4);///
	while(result!=NULL)
	{
		printf("%d  ",result->val);
		result = result->next;

	}
	printf("\n");
	system("pause");
}