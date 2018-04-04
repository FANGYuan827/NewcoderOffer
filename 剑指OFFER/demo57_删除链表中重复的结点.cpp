/*
2018��3��30��15:56:07 
��һ������������У������ظ��Ľ�㣬
��ɾ�����������ظ��Ľ�㣬�ظ��Ľ�㲻��������������ͷָ�롣
���磬����1->2->3->3->4->4->5 �����Ϊ 1->2->5
*/
#include "iostream"
#include <stack>
#include <vector>
using namespace std;


struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};


/*
����˼·��
��Ҫ����ָ�룬һ��ָ��ǰһ���ڵ�preNode����һ��ָ��ǰ�ڵ�node��
���������ȵĽڵ㣬node����ƶ���preNode����������node.val�������ıȽϣ�
ֱ������node��node.next����ȣ�preNode�Ϳ���ָ��node.next

ע�⣺����ͷ���ܾͿ�ʼ���ظ��Ľڵ㣬����Ĭ��preNode=null��
�ں���ĸ�preNode��ֵ��ʱ����preNodeΪnull���ǾͰ�pHead����Ϊnode.next

*/
class Solution_demo57 {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
		if(pHead==NULL)
			return NULL;
		ListNode *res = pHead;
		ListNode *preNode = NULL;
		ListNode *Node = pHead;
		while(Node!=NULL)
		{
			if(Node->next!=NULL&&Node->val==Node->next->val)
			{
				int value_tmp = Node->val;
				while(Node->next!=NULL&&Node->next->val==value_tmp)
				{
					Node = Node->next;
				}
				if(preNode==NULL)
				{
					pHead = Node->next;
				}
				else
				{
					preNode->next = Node->next;
				}
			}
			else
			{
				preNode = Node;
			}
			Node = Node->next;
		}
		return pHead;
    }
};


void main_demo57()
{
	Solution_demo57 s1;
	ListNode l1(1),l2(1),l3(3),l4(3),l5(4),l6(4),l7(5);
	ListNode *res = NULL;
	l1.next = &l2;
	l2.next = &l3;
	l3.next = &l4;
	l4.next = &l5;
	l5.next = &l6;
	l6.next = &l7;

	res = s1.deleteDuplication(&l1);
	while(res!=NULL)
	{
		cout<<res->val<<"->";
		res = res->next;
	}
	cout<<endl;
	system("pause");
}

