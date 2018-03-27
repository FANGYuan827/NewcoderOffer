/*
2018年2月28日09:43:02
输入两个链表，找出它们的第一个公共结点。
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
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
         if(pHead1==NULL||pHead2==NULL)
         {
             return NULL;
         }
        ListNode *tmp1 = NULL;
        ListNode *tmp2 = NULL;
        tmp1 = pHead1;
        tmp2 = pHead2;
        while(tmp1!=NULL)
        {
            for(tmp2=pHead2;tmp2!=NULL;tmp2=tmp2->next)
            {
                if(tmp1==tmp2)
                {
                    if(tmp2!=NULL)
                        return tmp1;
                    else
                        break;
                }
            }
            tmp1 = tmp1->next;
        }
        return NULL;
    }
};



void main_demo34()
{

	struct ListNode l1(1),l2(2),l3(3),l4(4),l5(5),l6(6);
	l1.next = &l2;
	l2.next = &l3;
	l3.next = &l5;
	l4.next = &l5;
	l5.next = &l6;
	Solution s1;
	ListNode *res = s1.FindFirstCommonNode(&l1,&l4);
	if(res!=NULL)
	{
		cout<<"第一个公共结点为："<<res->val<<endl;
	}
	system("pause");
}