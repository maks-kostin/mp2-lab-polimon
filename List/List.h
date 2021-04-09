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

	void operator*=(const TMonom& m)
	{
		coeff *= m.coeff;
		x += m.x;
		y += m.y;
		z += m.z;
	}

	TMonom operator*(const TMonom& m)
	{
		TMonom res;
		res.coeff = coeff * m.coeff;
		res.x = x + m.x;
		res.y = y + m.y;
		res.z = z + m.z;
		return res;
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
	TLink* pNext, *pPr;
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
		if (size == 0)
		{
			tmp->pNext = pStop;
			pFirst = pLast = tmp;
		}
		else
		{
			tmp->pNext = pFirst;
			pFirst = tmp;
		}
		size++;
	}

	void InsLast(T elem)
	{
		if (size) 
		{
			TLink<T>* tmp = new TLink<T>;
			tmp->val = elem;
			tmp->pNext = pStop;
			pLast->pNext = tmp;
			pLast = tmp;
			size++;
		}
		else 
		{
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

	void ToEnd()
	{
		pCurr = pLast;
	}

	void GoNext()
	{
		pPrev = pCurr;
		pCurr = pCurr->pNext;
	}

	void GoBack() 
	{
		pCurr = pPrev;
		pPrev = pCurr->pPr;
	}
		

	bool IsEnd()
	{
		if (pCurr == pStop)
			return true;
		return false;
	}

	bool IsFirst()
	{
		return pCurr == pFirst;
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

	void InsMonom(const TMonom& m)
	{
		Reset();
		while (true)
		{
			if (pCurr->val < m)
			{
				InsCurr(m);
				break;
			}
			if (pCurr->val == m)
			{
				if (pCurr->val.coeff + m.coeff != 0)
					pCurr->val.coeff += m.coeff;
				else
					DelCurr();
				break;
			}
			GoNext();
		}
	}

	TPolinom& TPolinom::operator+=(const TPolinom& p)
	{
		Reset();
		TLink<TMonom>* curr = p.pFirst;
		while (curr != p.pStop)
		{
			if (pCurr->val < curr->val)
			{
				InsCurr(curr->val);
				curr = curr->pNext;
			}
			else
			{
				if (pCurr->val == curr->val)
				{
					double tmp = pCurr->val.coeff + curr->val.coeff;
					pCurr->val.coeff = tmp;
					if (tmp)
						GoNext();
					else
						DelCurr();
					curr = curr->pNext;
				}
				else
					GoNext();
			}
		}
		return *this;
	}

	TPolinom& operator*(TPolinom& q)
	{
		TPolinom res;
		for (Reset(); !IsEnd(); GoNext())
			{
			TLink<TMonom>* pC = q.pFirst;
			TMonom tmp;
			TPolinom p;
			while (pC != q.pStop)
			{
				tmp = pCurr->val * pC->val;
				p.InsMonom(tmp);
				pC = pC->pNext;
			}
			res += p;
		}
		/*
		ToEnd();
		while (!IsFirst())
		{
			TLink<TMonom>* pC = q.pLast;
			TPolinom tmp;
			while (pC != pStop)
			{
				tmp.InsCurr(pCurr->val * pC->val);
				pC = pC->pPr;
			}
			GoBack();
		}
		cout << res << endl;*/
		return res;
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

	friend std::ostream& operator << (std::ostream& out, TPolinom& p)
	{
		for (p.Reset(); !p.IsEnd(); p.GoNext())
		{
			out << p.pCurr->val << ' ';
		}
		return out;
	}
};
