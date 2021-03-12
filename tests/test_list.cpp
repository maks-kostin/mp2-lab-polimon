#include "../List/List.h"

#include "gtest.h"

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

TEST(TList, can_ins_k)
{
	TList<int> li;
	li.InsFirst(1);
	li.InsLast(2);
	li.InsLast(4);
	ASSERT_NO_THROW(li.InsK(3, 3));
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
	ASSERT_ANY_THROW();
}







