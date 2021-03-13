#include <../gtest/gtest.h>
#include "TwoPointers.h"

TEST(CLL, test_racers_length_0_without_cycle_false) {
	int length = 0;
	int* array = new int[length];
	for (int i = 0; i < length; i++) {
		srand(time(NULL));
		array[i] = rand() % 12;
	}
	CLL _cll(array, length, false);

	EXPECT_EQ(false, _cll.CLL_racers(_cll));
}

TEST(CLL, test_racers_length_0_with_cycle_false) {
	int length = 0;
	int* array = new int[length];
	for (int i = 0; i < length; i++) {
		srand(time(NULL));
		array[i] = rand() % 12;
	}
	CLL _cll(array, length, true);

	EXPECT_EQ(false, _cll.CLL_racers(_cll));
}

TEST(CLL, test_racers_length_1_without_cycle_false) {
	int length = 1;
	int* array = new int[length];
	for (int i = 0; i < length; i++) {
		srand(time(NULL));
		array[i] = rand() % 12;
	}
	CLL _cll(array, length, false);
	
	EXPECT_EQ(false, _cll.CLL_racers(_cll));
}

TEST(CLL, test_racers_length_1_with_cycle_false) {
	int length = 1;
	int* array = new int[length];
	for (int i = 0; i < length; i++) {
		srand(time(NULL));
		array[i] = rand() % 12;
	}
	CLL _cll(array, length, true);

	EXPECT_EQ(false, _cll.CLL_racers(_cll));
}

TEST(CLL, test_racers_length_2_without_cycle_false) {
	int length = 2;
	int* array = new int[length];
	for (int i = 0; i < length; i++) {
		srand(time(NULL));
		array[i] = rand() % 12;
	}
	CLL _cll(array, length, false);

	EXPECT_EQ(false, _cll.CLL_racers(_cll));
}

TEST(CLL, test_racers_length_2_with_cycle_false) {
	int length = 2;
	int* array = new int[length];
	for (int i = 0; i < length; i++) {
		srand(time(NULL));
		array[i] = rand() % 12;
	}
	CLL _cll(array, length, true);

	EXPECT_EQ(false, _cll.CLL_racers(_cll));
}

TEST(CLL, test_racers_length_3_without_cycle_false) {
	int length = 3;
	int* array = new int[length];
	for (int i = 0; i < length; i++) {
		srand(time(NULL));
		array[i] = rand() % 12;
	}
	CLL _cll(array, length, false);

	EXPECT_EQ(false, _cll.CLL_racers(_cll));
}

TEST(CLL, test_racers_length_3_with_cycle_true) {
	int length = 3;
	int* array = new int[length];
	for (int i = 0; i < length; i++) {
		srand(time(NULL));
		array[i] = rand() % 12;
	}
	CLL _cll(array, length, true);

	EXPECT_EQ(true, _cll.CLL_racers(_cll));
}

TEST(CLL, test_racers_length_4_without_cycle_false) {
	int length = 4;
	int* array = new int[length];
	for (int i = 0; i < length; i++) {
		srand(time(NULL));
		array[i] = rand() % 12;
	}
	CLL _cll(array, length, false);

	EXPECT_EQ(false, _cll.CLL_racers(_cll));
}

TEST(CLL, test_racers_length_4_with_cycle_true) {
	int length = 4;
	int* array = new int[length];
	for (int i = 0; i < length; i++) {
		srand(time(NULL));
		array[i] = rand() % 12;
	}
	CLL _cll(array, length, true);

	EXPECT_EQ(true, _cll.CLL_racers(_cll));
}

TEST(CLL, test_racers_length_5_with_cycle_true) {
	int length = 5;
	int* array = new int[length];
	for (int i = 0; i < length; i++) {
		srand(time(NULL));
		array[i] = rand() % 12;
	}
	CLL _cll(array, length, true);

	EXPECT_EQ(true, _cll.CLL_racers(_cll));
}

TEST(CLL, test_racers_length_5_without_cycle_false) {
	int length = 5;
	int* array = new int[length];
	for (int i = 0; i < length; i++) {
		srand(time(NULL));
		array[i] = rand() % 12;
	}
	CLL _cll(array, length, false);

	EXPECT_EQ(false, _cll.CLL_racers(_cll));
}

TEST(CLL, test_revers_length_0_without_cycle_false) {
	int length = 0;
	int* array = new int[length];
	for (int i = 0; i < length; i++) {
		srand(time(NULL));
		array[i] = rand() % 12;
	}
	CLL _cll(array, length, false);

	EXPECT_EQ(false, _cll.CLL_revers(_cll));
}

TEST(CLL, test_revers_length_0_with_cycle_false) {
	int length = 0;
	int* array = new int[length];
	for (int i = 0; i < length; i++) {
		srand(time(NULL));
		array[i] = rand() % 12;
	}
	CLL _cll(array, length, true);

	EXPECT_EQ(false, _cll.CLL_revers(_cll));
}

TEST(CLL, test_revers_length_1_without_cycle_false) {
	int length = 1;
	int* array = new int[length];
	for (int i = 0; i < length; i++) {
		srand(time(NULL));
		array[i] = rand() % 12;
	}
	CLL _cll(array, length, false);

	EXPECT_EQ(false, _cll.CLL_revers(_cll));
}

TEST(CLL, test_revers_length_1_with_cycle_false) {
	int length = 1;
	int* array = new int[length];
	for (int i = 0; i < length; i++) {
		srand(time(NULL));
		array[i] = rand() % 12;
	}
	CLL _cll(array, length, true);

	EXPECT_EQ(false, _cll.CLL_revers(_cll));
}

TEST(CLL, test_revers_length_2_without_cycle_false) {
	int length = 2;
	int* array = new int[length];
	for (int i = 0; i < length; i++) {
		srand(time(NULL));
		array[i] = rand() % 12;
	}
	CLL _cll(array, length, false);

	EXPECT_EQ(false, _cll.CLL_revers(_cll));
}

TEST(CLL, test_revers_length_2_with_cycle_false) {
	int length = 2;
	int* array = new int[length];
	for (int i = 0; i < length; i++) {
		srand(time(NULL));
		array[i] = rand() % 12;
	}
	CLL _cll(array, length, true);

	EXPECT_EQ(false, _cll.CLL_revers(_cll));
}

TEST(CLL, test_revers_length_3_without_cycle_false) {
	int length = 3;
	int* array = new int[length];
	for (int i = 0; i < length; i++) {
		srand(time(NULL));
		array[i] = rand() % 12;
	}
	CLL _cll(array, length, false);

	EXPECT_EQ(false, _cll.CLL_revers(_cll));
}

TEST(CLL, test_revers_length_3_with_cycle_true) {
	int length = 3;
	int* array = new int[length];
	for (int i = 0; i < length; i++) {
		srand(time(NULL));
		array[i] = rand() % 12;
	}
	CLL _cll(array, length, true);

	EXPECT_EQ(true, _cll.CLL_revers(_cll));
}

TEST(CLL, test_revers_length_4_without_cycle_false) {
	int length = 4;
	int* array = new int[length];
	for (int i = 0; i < length; i++) {
		srand(time(NULL));
		array[i] = rand() % 12;
	}
	CLL _cll(array, length, false);

	EXPECT_EQ(false, _cll.CLL_revers(_cll));
}

TEST(CLL, test_revers_length_4_with_cycle_true) {
	int length = 4;
	int* array = new int[length];
	for (int i = 0; i < length; i++) {
		srand(time(NULL));
		array[i] = rand() % 12;
	}
	CLL _cll(array, length, true);

	EXPECT_EQ(true, _cll.CLL_revers(_cll));
}

TEST(CLL, test_revers_length_5_with_cycle_true) {
	int length = 5;
	int* array = new int[length];
	for (int i = 0; i < length; i++) {
		srand(time(NULL));
		array[i] = rand() % 12;
	}
	CLL _cll(array, length, true);

	EXPECT_EQ(true, _cll.CLL_revers(_cll));
}

TEST(CLL, test_revers_length_5_without_cycle_false) {
	int length = 5;
	int* array = new int[length];
	for (int i = 0; i < length; i++) {
		srand(time(NULL));
		array[i] = rand() % 12;
	}
	CLL _cll(array, length, false);

	EXPECT_EQ(false, _cll.CLL_revers(_cll));
}