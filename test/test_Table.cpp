#include <../gtest/gtest.h>
#include "TTable.h"
#include "TArrayTable.h"
#include "THashTable.h"
#include "TTreeTable.h"

TEST(Record, can_create_a_record) {
	Record<int, int> record;
	ASSERT_NO_THROW(record);
}

TEST(Record, the_default_constructor_initializes_the_values){
	Record<int, int> record;
	EXPECT_EQ(record.GetKey() + record.GetValue(), 0);
}

TEST(Record, the_initialization_constructor_initializes_the_values){
	Record<int, int> record(2, 7);
	EXPECT_EQ(record.GetKey() + record.GetValue(), 9);
}

TEST(Record, can_get_a_key){
	Record<int, int> record(2, 7);
	ASSERT_NO_THROW(record.GetKey());
	EXPECT_EQ(record.GetKey(), 2);
}

TEST(Record, can_get_a_val){
	Record<int, int> record(2, 7);
	ASSERT_NO_THROW(record.GetValue());
	EXPECT_EQ(record.GetValue(), 7);
}

TEST(Record, can_compare_a_record){
	Record<int, int> record, second_record;
	ASSERT_NO_THROW(record == second_record);
}

TEST(Record, comparing_identical_records_is_true){
	Record<int, int> record, second_record;
	EXPECT_EQ(record == second_record, true);
}

TEST(Record, comparing_no_identical_records_is_true){
	Record<int, int> record(2, 7), second_record;
	EXPECT_EQ(record == second_record, false);
}

TEST(Record, can_assign_records){
	Record<int, int> first_record, second_record, third_record;
	ASSERT_NO_THROW(first_record = second_record = third_record);
}

TEST(Record, the_records_after_the_assignment_are_the_same){
	Record<int, int> record(2, 7), second_record;
	second_record = record;
	EXPECT_EQ(record == second_record, true);
}

TEST(ScanTable, can_create_ScanTable){
	ScanTable<int, int> scan;
	ASSERT_NO_THROW(scan);
}

TEST(ScanTable, can_insert_record_in_no_full_ScanTable){
	ScanTable<int, int> scan;
	Record<int, int> record;
	ASSERT_NO_THROW(scan.Insert(record));
}

TEST(ScanTable, can_find_record_in_ScanTable){
	ScanTable<int, int> scan;
	Record<int, int> record;
	ASSERT_NO_THROW(scan.Find(record.GetKey()));
}

TEST(ScanTable, can_delete_record_in_no_empty_ScanTable){
	ScanTable<int, int> scan;
	Record<int, int> record;
	scan.Insert(record);
	ASSERT_NO_THROW(scan.Delete(record.GetKey()));
}

TEST(ScanTable, find_for_an_existing_record_will_return_the_true){
	ScanTable<int, int> scan;
	Record<int, int> record;
	scan.Insert(record);
	EXPECT_EQ(scan.Find(record.GetKey()), true);
}

TEST(ScanTable, find_for_a_nonexistent_record_will_return_the_false){
	ScanTable<int, int> scan;
	Record<int, int> record;
	EXPECT_EQ(scan.Find(record.GetKey()), false);
}

TEST(ScanTable, insert_a_nonexistent_record_will_return_the_true) {
	ScanTable<int, int> scan;
	Record<int, int> record;
	ASSERT_NO_THROW(scan.Insert(record));
}

TEST(ScanTable, delete_an_existing_record_will_return_the_true) {
	ScanTable<int, int> scan;
	Record<int, int> record;
	scan.Insert(record);
	ASSERT_NO_THROW(scan.Delete(record.GetKey()));
}

