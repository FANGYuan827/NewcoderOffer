/*
2017��11��28��21:58:16��
����һ����������������е�����k����㡣
*/
#include "iostream"
using namespace std;
#include "stack"
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
	val(x), next(NULL) {
	}
};
class Solution {
public:
	ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
		int i = 0;
		ListNode *ptmp1 = NULL;
		stack<struct ListNode *>s1;
		if(pListHead==NULL||k<=0)
		{
			return NULL;
		}
		ptmp1 = pListHead;
		while(ptmp1!=NULL)
		{
			s1.push(ptmp1);
			ptmp1 = ptmp1->next;
		}
		int length = s1.size();
		if(k>length)
		{
			return NULL;
		}
		for(i=0;i<k-1;i++)
		{
			s1.pop();
		}
		return s1.top();
	}
};
/*
���ϴ���Ĵ��룺
public ListNode FindKthToTail(ListNode head,int k) { //5,{1,2,3,4,5}
        ListNode p, q;
        p = q = head;
        int i = 0;
        for (; p != null; i++) {
            if (i >= k)
                q = q.next;
            p = p.next;
        }
        return i < k ? null : q;
    }
*/