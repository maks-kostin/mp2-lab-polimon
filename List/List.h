#pragma once
#include <iostream>

using namespace std;

struct TMonom 
{
	int x, y, z;
	double coeff;

	TMonom() { x = 0; y = 0; z = 0; coeff = 1; }
	TMonom(int tcoeff, int tx, int ty, int tz) { coeff = tcoeff; x = tx; y = ty; z = tz; }
	bool operator>(const TMonom& m)
	{
		if (x > m.x)
			return true;
		else
			if ((x == m.x) && (y > m.y))
				return true;
			else
				if ((x == m.x) && (y == m.y) && (z > m.z))
					return true;
		return false;
	}

	bool operator<(const TMonom& m)
	{
		if (x < m.x)
			return true;
		else
			if ((x == m.x) && (y < m.y))
				return true;
			else
				if ((x == m.x) && (y == m.y) && (z < m.z))
					return true;
		return false;
	}

	bool operator==(const TMonom& m)
	{
		if ((x == m.x) && (y == m.y) && (z == m.z))
			return true;
		return false;
	}

	bool operator!=(const TMonom& m)
	{
		return !(operator==(m));
	}

	void operator*=(TMonom& q)
	{
		coeff *= q.coeff;
		x += q.x;
		y += q.y;
		z += q.z;
	}

	friend ostream& operator<<(ostream& out, const TMonom& m)
	{
		out << m.coeff << "*x^" << m.x << "*y^" << m.y << "*z^" << m.z << " ";
		return out;
	}

	friend istream& operator>>(istream& in, TMonom& m)
	{
		in >> m.coeff;
		in >> m.x;
		in >> m.y;
		in >> m.z;
		return in;
	}
};

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
	TList(){
		pStop = NULL;
		pFirst = pLast = pCurr = pPrev = pStop;
		size = pos = 0;
	}

	~TList()
	{
		while (pFirst != pStop)
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
		size++;
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

	void InsLast(T elem)
	{
		if (size) {
			TLink<T>* tmp = new TLink<T>;
			tmp->val = elem;
			tmp->pNext = pStop;
			pLast->pNext = tmp;
			pLast = tmp;
			size++;
		}
		else {
			InsFirst(elem);
		}
	}

	void InsCurr(T elem)
	{
		if (pCurr == pStop)
			InsLast(elem);
		else
			if (pCurr == pFirst)
				InsFirst(elem);
			else
			{
				TLink<T>* t = new TLink<T>;
				t->val = elem;
				t->pNext = pCurr;
				pPrev->pNext = t;
				pPrev = t;
				size++;
			}
		
	}

	friend ostream& operator<<(ostream & out, const TList<T> & l)
	{
		TLink<T>* tmp = l.pFirst;
		tmp = tmp->pNext;
		while (tmp != l.pStop)
		{
			out << tmp->val << " ";
			tmp = tmp->pNext;
		}
		return out;
	}

	void DelFirst()
	{
		if (size == 0)
			throw 0;
		else
		{
			TLink<T>* t = pFirst;
			pFirst = pFirst->pNext;
			delete t;
			size--;
		}
	}

	void DelCurr()
	{
		if (pCurr == pStop || size == 0)
			throw 0;
		if (pCurr == pFirst) 
		{
			DelFirst();
			pCurr = pFirst;
		}
		else
		{
			TLink<T>* t = pCurr;
			pPrev->pNext = pCurr->pNext;
			delete t;
			pCurr = pPrev->pNext;
			size--;
		}
	}

	T GetCurr()
	{
		return pCurr->val;
	}

	void SetCurr(T elem)
	{
		pCurr->val = elem;
	}

	void Reset()
	{
		pCurr = pFirst;
	}

	void GoNext()
	{
		pPrev = pCurr;
		pCurr = pCurr->pNext;
	}

	bool IsEnd()
	{
		if (pCurr == pStop)
			return true;
		return false;
	}

};

template <class T>
class THeadList : public TList<T>
{
protected:
	//using TList<T>::pFirst;
	TLink<T>* pHead;
public:
	THeadList() : TList()
	{
		/*
		TLink<T>* t = new TLink<T>;
		pHead = t;
		pStop = pHead;
		pHead->pNext = pHead;
		*/
		pHead = new TLink<T>;
		pStop = pHead;
		pFirst = pLast = pCurr = pPrev = pStop;
		pHead->pNext = pHead;
	}

	~THeadList()
	{
		while (pFirst != pStop)
		{
			TLink<T>* tmp = pFirst;
			pFirst = pFirst->pNext;
			delete tmp;
		}
		delete pHead;
	}
	
	void InsFirst(T elem)
	{
		TList::InsFirst(elem);
		pHead->pNext = pFirst;
	}

	void DelCurr()
	{
		TList<T>::DelCurr();
		pHead->pNext = this->pFirst;
	}

	void DelFirst()
	{
		TList<T>::DelFirst();
		pHead->pNext = this->pFirst;
	}
};

class TPolinom : public THeadList<TMonom>
{
public:
	TPolinom()
	{
		TMonom tmp;
		tmp.z = -1;
		pHead->val = tmp;
		pFirst = pLast = pCurr = pPrev = pStop;
	}

	void InsMonom(TMonom m)
	{

		Reset();
		while (true)
		{
			if (pCurr == pStop)
			{
				InsLast(m);
				break;
			}
			if (m > pCurr->val)
			{
				InsCurr(m);
				break;
			}
			else
			{
				if (m == pCurr->val)
				{
					if (m.coeff + pCurr->val.coeff == 0)
					{
						DelCurr();
						break;
					}
					else
					{
						pCurr->val.coeff += m.coeff;
						break;
					}
				}
				GoNext();
			}
		}
		/*for (Reset(); !IsEnd(); GoNext())
		{
			if (m > pCurr->val)
			{
				InsCurr(m);
				break;
			}
			else
				if (m == pCurr->val)
				{
					double sum = m.coeff + pCurr->val.coeff;
						if (sum == 0)
						{
							DelCurr();
						}
						else
						{
							pCurr->val.coeff = sum;
						}
						break;
				}
		}
		if (pCurr == pStop)
			InsLast(m);*/

	}

	TPolinom& operator+=(TPolinom& q)
	{
		Reset();
		q.Reset();
		while (!q.IsEnd())
		{
			if ((pCurr->val) < q.pCurr->val)
			{
				InsCurr(q.pCurr->val);
				q.GoNext();
			}
			else
			{
				if (pCurr->val > q.pCurr->val)
					GoNext();
				else
				{
					double tmp = pCurr->val.coeff + q.pCurr->val.coeff;
					if (tmp)
					{
						pCurr->val.coeff = tmp;
						GoNext();
						q.GoNext();
					}
					else
					{
						DelCurr();
						q.GoNext();
					}
				}
			}
		}
		return *this;
	}

	void operator*=(TPolinom& q)
	{
		q.Reset();
		while (!q.IsEnd())
		{
			for (Reset(); !IsEnd(); GoNext())
			{
				pCurr->val *= q.pCurr->val;
			}
			q.GoNext();
		}
	}

	TPolinom& operator=(TPolinom& q)
	{
		if (this == &q)
			return *this;
		while (pFirst != pStop)
			DelFirst();
		for (q.Reset(); !q.IsEnd(); q.GoNext())
			InsLast(q.GetCurr());
		return *this;
	}

	/*friend ostream& operator<<(ostream& out, const TPolinom& q)
	{
		for (q.Reset(); !q.IsEnd(); q.GoNext())
			out << q.pCurr->val;
		return out;

	}*/
	friend std::ostream& operator << (std::ostream& out, TPolinom& p)
	{
		for (p.Reset(); !p.IsEnd(); p.GoNext())
		{
			out << p.pCurr->val << ' ';
		}
		return out;
	}
};
