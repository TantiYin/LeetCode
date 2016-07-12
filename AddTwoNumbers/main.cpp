#include <iostream>
#include <list>

using namespace std;

struct ListNode
{
	int mVal;
	ListNode* mNext;
	ListNode(int x): mVal(x), mNext(nullptr) {}
};


ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
	if (l1 == nullptr)
	{
		return l2;
	}
	if (l2 == nullptr)
	{
		return l1;
	}

	ListNode *pNode = nullptr, *pHeader = nullptr, *pTmp = nullptr;//切勿忘记初始化
	int iSum = 0, iCarry = 0;
	ListNode *pi = l1, *pj = l2;
	for(; pi != nullptr && pj != nullptr; pi = pi->mNext, pj = pj->mNext)
	{
		iSum = pi->mVal + pj->mVal + iCarry;
		iCarry = iSum / 10;
		pTmp = new ListNode(iSum % 10);
		if (pHeader == nullptr)
		{
			pHeader = pTmp;
			pNode = pTmp;
		}
		else
		{
			pNode->mNext = pTmp;
			pNode = pTmp;
		}
	}

	ListNode* q = pi == nullptr? pj: pi; //统一，用同一个循环
	for (; q != nullptr; q = q->mNext)
	{
		iSum = q->mVal + iCarry;
		iCarry = iSum / 10;
		pTmp = new ListNode(iSum % 10);
		pNode->mNext = pTmp;
		pNode = pTmp;
	}
	if (iCarry != 0)
	{
		pTmp = new ListNode(iCarry);
		pNode->mNext = pTmp;
		pNode = pTmp;
	}
	return pHeader;
}

list<int> addTwoNumbers(const list<int>& lhs, const list<int>& rhs)
{
	list<int> listResult;
	int iSum = 0, iCarry = 0;
	auto pi = lhs.begin(), pj = rhs.begin();
	for (; pi != lhs.end() && pj != rhs.end(); ++pi, ++pj)
	{
		iSum = *pi + *pj + iCarry;
		iCarry = iSum / 10;
		listResult.push_back(iSum % 10);
	}
	for(; pi != lhs.end(); ++pi)
	{
		iSum = *pi + iCarry;
		iCarry = iSum / 10;
		listResult.push_back(iSum % 10);
	}
	for(; pj != rhs.end(); ++pj)
	{
		iSum = *pj + iCarry;
		iCarry = iSum / 10;
		listResult.push_back(iSum % 10);
	}
	if (iCarry != 0)
	{
		listResult.push_back(iCarry);
	}
	return listResult;

}

int main()
{
	/*list<int> l1, l2, l3;
	l1.push_back(2);
	l1.push_back(4);
	l1.push_back(5);
	l1.push_back(9);
	for (const auto &i : l1)
	{
		cout << i << " ";
	}
	cout << endl;
	l2.push_back(5);
	l2.push_back(6);
	l2.push_back(4);
	for (const auto &i : l2)
	{
		cout << i << " ";
	}
	cout << endl;

	l3 = addTwoNumbers(l1, l2);
	for (const auto &i : l3)
	{
		cout << i << " ";
	}
	cout << endl;*/

	ListNode node1(2), node2(4), node3(5), node4(9), node5(5), node6(6), node7(4);
	node1.mNext = &node2;
	node2.mNext = &node3;
	node3.mNext = &node4;

	node5.mNext = &node6;
	node6.mNext = &node7;

	ListNode* listRes = addTwoNumbers(&node1, &node5);
	for (ListNode* pNode = listRes; pNode != nullptr; pNode = pNode->mNext)
	{
		cout << pNode->mVal << " ";
	}
	cout << endl;
	return 0;
}