#include "../gtest/gtest.h"
#include "TText.h"

TEST(Text, can_create_text) {
	ASSERT_NO_THROW(Text);
}
TEST(Text, can_add_next_line) {
	Text tmp;
	ASSERT_NO_THROW(tmp.InsertNextLine("NEWNEW"));
}
TEST(Text, can_add_next_section) {
	Text tmp;
	ASSERT_NO_THROW(tmp.InsertNextSection("newnew"));
}
TEST(Text, can_go_next) {
	Text tmp;
	ASSERT_NO_THROW(tmp.GoNextLink());
}
TEST(Text, can_go_back) {
	Text tmp;
	ASSERT_NO_THROW(tmp.GoPrevLink());
}
TEST(Text, can_go_down) {
	Text tmp;
	ASSERT_NO_THROW(tmp.GoDownLink());
}

