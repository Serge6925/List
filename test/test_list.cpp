#include "list.h"

#include <gtest.h>


TEST(List, can_create_list_with_positive_length)
{
	ASSERT_NO_THROW(List list(5));
}
TEST(List, can_create_list_with_negative_length)
{
	ASSERT_ANY_THROW(List list(-3));
}
TEST(List, can_get_length)
{
	List l(7);
	EXPECT_EQ(7, l.size());
}
TEST(List, can_insert_front_element)
{
	List l(7);
	l.insert_front(100);
	EXPECT_EQ(100, l[0].value);
}
TEST(List, can_erase_front_element)
{
	List l(7);
	l.insert_front(9);
	l.insert_front(8);
	l.erase_front();
	EXPECT_EQ(9, l[0].value);
}
TEST(List, can_insert_after_element)
{
	List l(7);
	l.insert_after(10, l(4));
	EXPECT_EQ(10, l[5].value);
}
TEST(List, can_erase_after_element)
{
	List l(7);
	l.insert_after(9, l(4));
	l.insert_after(10, l(4));
	l.erase_after(l(4));
	EXPECT_EQ(9, l[5].value);
}
TEST(List, can_get_not_existing_element)
{
	List l(5);
	ASSERT_ANY_THROW(l[10]);
}
TEST(List, can_copy_list)
{
	List l1(5);
	ASSERT_NO_THROW(List l2(l1));
}
//TEST(List, can_copy_list_2)
//{
//	ASSERT_NO_THROW(List l2(List l1));
//}
TEST(List, can_find_middle_elem)
{
	List l1(8);
	List l2(8);
	l1.insert_after(10, l1(3));
	l2.insert_after(8, l2(3));
	l2.insert_after(7, l2(4));
	EXPECT_EQ(10, l1.find_mid()[0]);
	EXPECT_EQ(8, l2.find_mid()[0]);
	EXPECT_EQ(7, l2.find_mid()[1]);
}