#pragma once
#include <iostream>

using namespace std;

template <class T>
struct TLink
{
	T val;
	TLink* pNext;
};

template <class T>
class TList
{
protected:
	TLink<T>* pFirst, * pLast, * pCurr, * pPrev, * pStop;
	int size, pos;
public:
	TList() { pStop = NULL; pFirst = pLast = pCurr = pPrev = pStop; size = 0; }
	~TList()
	{
		while (pFirst != NULL)
		{
			TLink<T>* tmp = pFirst;
			pFirst = pFirst->pNext;
			delete tmp;
		}
	}

	int GetSize()
	{
		TLink<T>* pCurr = pFirst;
		int k = 0;
		while (pCurr != pStop)
		{
			pCurr = pCurr->pNext;
			k++;
		}
		return k;
	}

	void InsFirst(T elem)
	{
		TLink<T>* tmp = new TLink<T>;
		tmp->val = elem;
		tmp->pNext = pFirst;
		pFirst = tmp;
	}

	void InsLast(T elem)
	{
		TLink<T>* pCurr = pFirst;
		while (pCurr->pNext != pStop)
		{
			pCurr = pCurr->pNext;
		}
		TLink<T>* tmp = new TLink<T>;
		tmp->val = elem;
		tmp->pNext = NULL;
		pCurr->pNext = tmp;
	}

	void InsK(T elem, int k)
	{
		TLink<T>* pCurr = pFirst;
		TLink<T>* tmp = new TLink<T>;
		for (int i = 0; i < k; i++)
		{
			pCurr = pCurr->pNext;
		}
		TLink<T>* _tmp = pCurr->pNext;
		pCurr->pNext = tmp;
		tmp->pNext = _tmp;
	}

	void InsElem(T elem)
	{
		if (pFirst != NULL)
		{
			TLink<T>* pCurr = pFirst;
			while (pCurr->pNext != NULL)
				pCurr = pCurr->pNext;
			TLink<T> * tmp = new TLink<T>;
			tmp->val = elem;
			tmp->pNext = NULL;
			pCurr->pNext = tmp;
		}
		else
		{
			TLink<T>* tmp = new TLink<T>;
			tmp->val = elem;
			tmp->pNext = pFirst;
			pFirst = tmp;
		}
	}

	friend ostream& operator<<(ostream & out, const TList<T> & l)
	{
		TLink<T>* tmp = l.pFirst;
		tmp = tmp->pNext;
		while (tmp != NULL)
		{
			out << tmp->val << " ";
			tmp = tmp->pNext;
		}
		return out;
	}



	void DelFirst();
	void DelCurr()
	{
		if (pCurr == pStop)
			throw 0;
		if (pCurr == pFirst)
			DelFirst();
		else
		{
			TLink<T>* t = pCurr;
			pPrev->pNext;
			pCurr->pNext;
			delete t;
			pCurr = pPrev->pNext;
			size--;
		}
	}
};


