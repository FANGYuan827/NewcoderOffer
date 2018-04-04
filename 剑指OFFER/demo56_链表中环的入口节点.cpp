/*
2018年3月30日13:36:21
一个链表中包含环，请找出该链表的环的入口结点。
*/

#include "iostream"
#include <vector>
using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
	val(x), next(NULL) {
	}
};

class Solution_demo56 {
public:
	ListNode* EntryNodeOfLoop(ListNode* pHead)
	{
		if(pHead==NULL)
			return NULL;
		vector<ListNode *>v_tmp;
		ListNode *tmp_1 = pHead;
		while(tmp_1!=NULL)
		{
			if(IsMatch(v_tmp,tmp_1))
				return tmp_1;
			v_tmp.push_back(tmp_1);
			tmp_1 = tmp_1->next;
		}
		CountListNodeNum(pHead);
		return NULL;
	}

	/*method2: 移动指针法*/
	ListNode* EntryNodeOfLoop_1(ListNode* pHead)
	{
		if(pHead==NULL)
			return NULL;
		int NodeCount = 0;
		NodeCount = CountListNodeNum(pHead);    //确定环中结点数
		ListNode *tmp_1 = pHead,*tmp_2=pHead;
		if(NodeCount==0)
		{
			return NULL;
		}
		while(NodeCount>0)
		{
			tmp_2 = tmp_2->next;
			--NodeCount;
		}
		while(tmp_1!=tmp_2)
		{
			tmp_1 = tmp_1->next;
			tmp_2 = tmp_2->next;
			if(tmp_2==NULL||tmp_1==NULL)
				return NULL;
		}
		return tmp_1;
	}
private:
	bool IsMatch(vector<ListNode*>&v,ListNode *pointer)
	{
		for(int i=0;i<v.size();i++)
		{
			if(v[i]==pointer)
				return true;
		}
		return false;
	}
	int CountListNodeNum(ListNode *pHead)
	{
		int Node_total = 0;
		if(pHead == NULL)
		{
			return 0;
		}
		ListNode *tmp_1=pHead,*tmp_2=pHead;
		while(1)               //必须保证next域不能为NULL 否则编译不通过
		{
			tmp_1 = tmp_1->next;
			tmp_2 = tmp_2->next;
            if(tmp_2 == NULL||tmp_1 == NULL)
				return 0;
            tmp_2 = tmp_2->next;
            if(tmp_2 == NULL||tmp_1 == NULL)
				return 0;
			if(tmp_1 == tmp_2)
				break;
		}
		tmp_1 = tmp_1->next;
		++Node_total;
		while(tmp_1!=tmp_2)
		{
			tmp_1 = tmp_1->next;
			++Node_total;
		}
		return Node_total;
	}
};


void main_demo56()
{
	Solution_demo56 s1;
	ListNode l1(1),l2(2),l3(3),l4(4),l5(5),l6(6);
	ListNode *res = NULL;
	l1.next = &l2;
	l2.next = &l3;
	l3.next = &l4;
	l4.next = &l5;
	l5.next = &l6;
	l6.next = &l1;
	res = s1.EntryNodeOfLoop_1(&l1);
	if(res!=NULL)
		cout<<"环的入口地址为:"<<res->val<<endl;
	else
		cout<<"链表不存在环"<<endl;
	system("pause");
}