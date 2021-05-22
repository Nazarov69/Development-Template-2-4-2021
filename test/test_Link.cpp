#include "../gtest/gtest.h"
#include "TText.h"

TEST(Link, can_create_link) {
	ASSERT_NO_THROW(Link);
}
TEST(Link, can_create_link_with_str) {
	ASSERT_NO_THROW(Link("newnew"));
}

TEST(Link, can_get_pNext) {
	Link* tmp = new Link();
	ASSERT_NO_THROW(tmp->GetNext());
}

TEST(Link, can_get_pDown) {
	Link* tmp = new Link();
	ASSERT_NO_THROW(tmp->GetDown());
}

TEST(Link, can_set_pNext) {
	Link* tmp1 = new Link();
	Link* tmp2 = new Link();
	ASSERT_NO_THROW(tmp1->SetNext(tmp2));
}

TEST(Link, can_set_pDown) {
	Link* tmp1 = new Link();
	Link* tmp2 = new Link();
	ASSERT_NO_THROW(tmp1->SetDown(tmp2));
}

