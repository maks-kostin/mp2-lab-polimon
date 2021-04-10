#include "../List/List.h"

#include "gtest.h"

TEST(TMonom, can_create_monom)
{
	ASSERT_NO_THROW(TMonom m);
}

TEST(TMonom, can_compare_the_monoms_more)
{
	TMonom m1, m2;
	ASSERT_NO_THROW(m1 > m2);
}

TEST(TMonom, can_compare_the_monoms_less)
{
	TMonom m1, m2;
	ASSERT_NO_THROW(m1 < m2);
}

TEST(Monom, can_compare_the_monoms_equal)
{
	TMonom m1, m2;
	ASSERT_NO_THROW(m1 == m2);
}

TEST(TList, can_create_list)
{
	ASSERT_NO_THROW(TList<int> l);
}

TEST(TList, can_ins_first)
{
	TList<int> li;
	ASSERT_NO_THROW(li.InsFirst(1));
}

TEST(TList, can_ins_last)
{
	TList<int> li;
	li.InsFirst(1);
	ASSERT_NO_THROW(li.InsLast(2));
}


TEST(TList, can_del_first)
{
	TList<int> li;
	li.InsFirst(1);
	li.InsFirst(2);
	ASSERT_NO_THROW(li.DelFirst());
}

TEST(TList, can_del_curr)
{
	TList<int> li;
	li.InsFirst(1);
	li.InsFirst(2);
	//li.InsFirst(3);
	li.Reset();
	//li.GoNext();
	ASSERT_NO_THROW(li.DelCurr());
}

TEST(TList, can_get_curr)
{
	TList<int> li;
	li.InsFirst(1);
	li.InsFirst(2);
	li.Reset();
	EXPECT_EQ(2, li.GetCurr());
}

TEST(TList, can_set_curr)
{
	TList<int> li;
	li.InsFirst(1);
	li.InsFirst(2);
	li.Reset();
	ASSERT_NO_THROW(li.SetCurr(3));
}

TEST(THeadList, can_create_HeadList)
{
	ASSERT_NO_THROW(THeadList<int> hl);
}

TEST(THeadTList, can_ins_first)
{
	TList<int> li;
	ASSERT_NO_THROW(li.InsFirst(1));
}

TEST(THeadTList, can_del_first)
{
	TList<int> li;
	li.InsFirst(1);
	ASSERT_NO_THROW(li.DelFirst());
}

TEST(TPolinom, can_create_polinom)
{
	ASSERT_NO_THROW(TPolinom p);
}

TEST(TPolinom, can_ins_monom)
{
	TPolinom p;
	TMonom m;
	m.x = 1;
	ASSERT_NO_THROW(p.InsMonom(m));
}

TEST(TPolinom, can_add_polinom)
{
	TMonom a(1, 1, 1, 1);
	TPolinom p;
	p.InsMonom(a);
	ASSERT_NO_THROW(p += p;);
}

TEST(TPolinom, null_coeff_deletes)
{
	TMonom a;
	TPolinom p1, p2;
	a.coeff = a.x = a.y = a.z = 1;
	p1.InsMonom(a);
	a.coeff = a.x = a.y = a.z = 3;
	p1.InsMonom(a);
	a.coeff = a.x = a.y = a.z = 4;
	p1.InsMonom(a);
	a.coeff = a.x = a.y = a.z = 2;
	p2.InsMonom(a);
	a.coeff = 3;
	a.x = a.y = a.z = 3;
	p2.InsMonom(a);
	a.coeff = -4;
	a.x = a.y = a.z = 4;
	p2.InsMonom(a);
	p1 += p2;
	EXPECT_EQ(3, p1.GetSize());
}

TEST(TPolinom, polinom_can_become_bigger)
{
	TMonom a;
	TPolinom p1, p2;
	a.coeff = a.x = a.y = a.z = 1;
	p1.InsMonom(a);
	a.coeff = a.x = a.y = a.z = 3;
	p1.InsMonom(a);
	a.coeff = a.x = a.y = a.z = 4;
	p1.InsMonom(a);
	a.coeff = a.x = a.y = a.z = 2;
	p2.InsMonom(a);
	a.coeff = 3;
	a.x = a.y = a.z = 3;
	p2.InsMonom(a);
	a.coeff = 4;
	a.x = a.y = a.z = 4;
	p2.InsMonom(a);
	p1 += p2;
	EXPECT_EQ(4, p1.GetSize());
}

TEST(TPolinom, polinom_can_become_lesser)
{
	TMonom a;
	TPolinom p1, p2;
	a.coeff = a.x = a.y = a.z = 1;
	p1.InsMonom(a);
	a.coeff = a.x = a.y = a.z = 3;
	p1.InsMonom(a);
	a.coeff = a.x = a.y = a.z = 4;
	p1.InsMonom(a);
	a.coeff = a.x = a.y = a.z = 2;
	p2.InsMonom(a);
	a.coeff = -3;
	a.x = a.y = a.z = 3;
	p2.InsMonom(a);
	a.coeff = -4;
	a.x = a.y = a.z = 4;
	p2.InsMonom(a);
	p1 += p2;
	EXPECT_EQ(2, p1.GetSize());
}







