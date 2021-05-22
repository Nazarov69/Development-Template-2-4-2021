#include <../gtest/gtest.h>
#include "TList.h"

TEST(TList, can_create_a_list) {
	ASSERT_NO_THROW(List<int> list);
}

TEST(THeadList, can_create_a_head_list) {
	ASSERT_NO_THROW(HeadList<int> list);
}

TEST(List, can_create_list) {
	ASSERT_NO_THROW(List<int> list);
}

TEST(List, can_copy_empty_list) {
	List<int> list;
	ASSERT_NO_THROW(List<int> copy(list));
}

TEST(List, can_add_an_elem_to_the_top_of_the_empty_list) {
	List<int> list;
	ASSERT_NO_THROW(list.InsertFirst(5));
}

TEST(List, can_add_an_elem_to_the_top_of_the_no_empty_list) {
	List<int> list;
	list.InsertFirst(5);
	ASSERT_NO_THROW(list.InsertFirst(5));
}

TEST(List, adding_an_elem_to_the_top_of_the_list_size_by_one) {
	List<int> list;
	list.InsertFirst(5);
	int size = list.GetSize();
	list.InsertFirst(5);
	EXPECT_EQ(size + 1, list.GetSize());
}

TEST(List, can_del_an_elem_to_the_top_of_the_no_empty_list) {
	List<int> list;
	list.InsertFirst(5);
	ASSERT_NO_THROW(list.DeleteFirst());
}

TEST(List, removing_an_elem_from_the_top_of_the_list_reduces_its_size_by_one) {
	List<int> list;
	list.InsertLast(5);
	int size = list.GetSize();
	list.DeleteFirst();
	EXPECT_EQ(size - 1, list.GetSize());
}

