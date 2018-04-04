/*
2018年3月30日15:56:07 
在一个排序的链表中，存在重复的结点，
请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。
例如，链表1->2->3->3->4->4->5 处理后为 1->2->5
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
解题思路：
需要两个指针，一个指向前一个节点preNode，另一个指向当前节点node，
如果遇到相等的节点，node向后移动，preNode不动，存下node.val方便后面的比较，
直到遇到node和node.next不相等，preNode就可以指向node.next

注意：链表开头可能就开始有重复的节点，所以默认preNode=null，
在后面的给preNode赋值的时候，若preNode为null，那就把pHead设置为node.next

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

