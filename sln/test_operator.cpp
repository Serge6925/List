#include "list.h"

#include <gtest.h>


TEST(iterator,	can_create_iterator_of_node)
{
	List l(10);
	ASSERT_NO_THROW(iterator iter(l(5)));
}
TEST(iterator,	can_create_iterator_of_list)
{
	List l(10);
	ASSERT_NO_THROW(iterator iter(l(0)));
}
TEST(iterator, can_create_iterator_of_iterator)
{
	List l(10);
	iterator iter1(l(0));
	ASSERT_NO_THROW(iterator iter2(iter1));
}
TEST(iterator, can_be_post_incremented)
{
	List l(10);
	l.insert_after(2, l(3));
	l.insert_after(5, l(4));
	iterator iter(l(4));
	EXPECT_EQ(2, iter++.GetNode()->value);
	EXPECT_EQ(5, iter.GetNode()->value);
}
TEST(iterator, can_be_prefix_incremented)
{
	List l(10);
	l.insert_after(2, l(3));
	l.insert_after(5, l(4));
	iterator iter(l(4));
	EXPECT_EQ(2, iter.GetNode()->value);
	EXPECT_EQ(5, (++iter).GetNode()->value);
	EXPECT_EQ(5, iter.GetNode()->value);
}
TEST(iterator, can_compare_two_iterators)
{
	List l1(10);
	List l2(15);
	iterator iter1_1(l1(0));
	iterator iter1_2(l1(2));
	iterator iter1_3(l1(5));
	iterator iter1_4(l1(8));
	iterator iter2_1(l2(10));
	EXPECT_ANY_THROW(iter1_1 < iter2_1);
	EXPECT_ANY_THROW(iter1_1 > iter2_1);
	EXPECT_EQ(1, iter1_1 < iter1_2);
	EXPECT_EQ(0, iter1_1 > iter1_2);
	EXPECT_EQ(1, iter1_1 < iter1_4);
	EXPECT_EQ(1, iter1_3 < iter1_4);
}
TEST(iterator, can_create_cycle)
{
	List l1(10);
	for (iterator i(l1(0)); i < l1(5); i++)
		EXPECT_NO_THROW(i);
}