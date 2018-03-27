/*
2017年12月6日19:28:45：
输入一个链表，反转链表后，输出链表的所有元素。
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
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
		if(pHead == NULL)
        {
            return pHead;
        }
        if(pHead->next == NULL)
        {
            return pHead;
        }
        ListNode *Current1=NULL;
        ListNode *Current2=NULL;
        ListNode *pTemp=NULL;
        Current1 = pHead;
        Current2 = pHead->next;
		while(Current2->next!=NULL)
        {
            if(Current1==pHead)
            {
                Current1->next = NULL;
            }
            pTemp = Current2->next;
            Current2->next = Current1;
			Current1 = Current2;
			Current2 = pTemp;
        }
		Current2->next = Current1;
        return Current2;
    }
};

void main_demo16()
{
	Solution s1;
	struct ListNode l1(1),l2(22),l3(333),l4(4444),l5(55555),l6(666),l7(777);
	l1.next = &l2;
	l2.next = &l3;
	l3.next = &l4;
	l4.next = &l5;
	l5.next = &l6;
	l6.next = &l7;
	struct ListNode *p = NULL;
	p = s1.ReverseList(&l1);
	while(p!=NULL)
	{
		printf("%d ",p->val);
		p = p->next;
	}
	printf("\n");
	system("pause");
}
/*
//其实这题可以用stack来做会更简单......
网上讲解链接：
https://www.nowcoder.com/profile/4162969/codeBookDetail?submissionId=15921939
*/