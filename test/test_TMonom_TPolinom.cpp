#include <../gtest/gtest.h> 
#include<algorithm>
#include "TMonom_TPolinom.h"

TEST(Monom, can_create_monom){
	ASSERT_NO_THROW(Monom m);
}

TEST(Monom, monom_fields_are_initialized_by_default){
	Monom monom;
	int error = 0;
	if (monom.degX != 0 || monom.degY != 0 || monom.degZ != 0 || monom.coeff != 0)
		error++;
	EXPECT_EQ(0, error);
}

TEST(Monom, can_compare_the_monoms){
	Monom* first_monom = new Monom[1], * second_monom = new Monom[1];
	ASSERT_NO_THROW(first_monom == second_monom);
	ASSERT_NO_THROW(first_monom < second_monom);
	ASSERT_NO_THROW(first_monom > second_monom);
}

TEST(Monom, monoms_are_compared_correctly){
	Monom* first_monom = new Monom[1], * second_monom = new Monom[1];
	first_monom[0].coeff = 15;
	first_monom[0].degX = 7;
	first_monom[0].degY = -2;
	first_monom[0].degZ = 1;

	second_monom[0].coeff = 4;
	second_monom[0].degX = -8;
	second_monom[0].degY = 5;
	second_monom[0].degZ = 9;

	EXPECT_EQ(true, first_monom > second_monom);
	EXPECT_EQ(true, second_monom < first_monom);

	second_monom[0].coeff = 15;
	second_monom[0].degX = 7;
	second_monom[0].degY = -2;
	second_monom[0].degZ = 1;

	EXPECT_EQ(true, second_monom == second_monom);
}

TEST(Monom, monom_can_be_assigned_to){
	Monom* first_monom = new Monom[1], * second_monom = new Monom[1];
	ASSERT_NO_THROW(first_monom = second_monom);
}

TEST(Monom, monoms_are_assigned_correctly){
	Monom* first_monom = new Monom[1], * second_monom = new Monom[1];
	second_monom[0].coeff = 4;
	second_monom[0].degX = -8;
	second_monom[0].degY = 5;
	second_monom[0].degZ = 9;
	first_monom[0] = second_monom[0];
	int error = 0;
	if (first_monom[0].degX != -8 || first_monom[0].degY != 5 || first_monom[0].degZ != 9 || first_monom[0].coeff != 4.0)
		error++;
	EXPECT_EQ(0, error);
}

TEST(Monom, monoms_can_be_multiplied_by_each_other){
	Monom* first_monom = new Monom[1], * second_monom = new Monom[1];
	ASSERT_NO_THROW(first_monom[0] = first_monom[0] * second_monom[0]);
}

TEST(Monom, monoms_multiplying_by_each_other_is_done_correctly){
	Monom* first_monom = new Monom[1], * second_monom = new Monom[1];
	first_monom[0].coeff = 15;
	first_monom[0].degX = 7;
	first_monom[0].degY = -2;
	first_monom[0].degZ = 1;

	second_monom[0].coeff = 4;
	second_monom[0].degX = -8;
	second_monom[0].degY = 5;
	second_monom[0].degZ = 9;
	first_monom[0] = first_monom[0] * second_monom[0];
	int error = 0;
	if (first_monom[0].degX != -1 || first_monom[0].degY != 3 || first_monom[0].degZ != 10 || first_monom[0].coeff != 60)
		error++;
	EXPECT_EQ(0, error);
}

TEST(Monom, monoms_can_be_multiplied_by_a_number){
	Monom* first_monom = new Monom[1];
	ASSERT_NO_THROW(first_monom[0] = first_monom[0] * 7);
}

TEST(Monom, monoms_multiplying_by_a_number_is_done_correctly){
	Monom* first_monom = new Monom[1];
	first_monom[0].coeff = 15;
	first_monom[0].degX = 7;
	first_monom[0].degY = -2;
	first_monom[0].degZ = 1;
	first_monom[0] = first_monom[0] * 6;
	int error = 0;
	if (first_monom[0].degX != 7 || first_monom[0].degY != -2 || first_monom[0].degZ != 1 || first_monom[0].coeff != 90)
		error++;
	EXPECT_EQ(0, error);
}


TEST(Polinom, can_create_polinom){
	ASSERT_NO_THROW(Polinom polinom);
}


TEST(Polinom, can_copy_no_empty_polinom){
	Monom* first_monom = new Monom[1];
	first_monom[0].coeff = 15;
	first_monom[0].degX = 7;
	first_monom[0].degY = -2;
	first_monom[0].degZ = 1;
	Polinom polinom(first_monom, 1);
	ASSERT_NO_THROW(Polinom polinoms(polinom));
}

TEST(Polinom, the_ñopied_polinom_has_its_own_memory){
	Monom* first_monom = new Monom[1];
	first_monom[0].coeff = 15;
	first_monom[0].degX = 7;
	first_monom[0].degY = -2;
	first_monom[0].degZ = 1;
	Polinom polinom(first_monom, 1);
	Polinom polinoms(polinom);
	polinoms.DeleteFirst();
	EXPECT_EQ(1, polinom.GetSize());
}

TEST(Polinom, can_multiply_a_no_empty_polinom_by_a_number){
	Polinom second_polinom;
	Monom* first_monom = new Monom[1];
	first_monom[0].coeff = 15;
	first_monom[0].degX = 7;
	first_monom[0].degY = -2;
	first_monom[0].degZ = 1;
	Polinom first_polinom(first_monom, 1);
	ASSERT_NO_THROW(second_polinom = first_polinom * 7);
}

TEST(Polinom, multiplying_a_polynomial_by_a_nonzero_number_does_not_change_its_size){
	Polinom second_polinom;
	Monom* first_monom = new Monom[1];
	first_monom[0].coeff = 15;
	first_monom[0].degX = 7;
	first_monom[0].degY = -2;
	first_monom[0].degZ = 1;
	Polinom first_polinom(first_monom, 1);
	int size = first_polinom.GetSize();
	second_polinom = first_polinom * 5;
	EXPECT_EQ(size, second_polinom.GetSize());
}

TEST(Polinom, can_multiply_a_no_empty_polinom_by_a_monom){
	Monom* first_monom = new Monom[1], * second_monom = new Monom[1];
	first_monom[0].coeff = 15;
	first_monom[0].degX = 7;
	first_monom[0].degY = -2;
	first_monom[0].degZ = 1;

	second_monom[0].coeff = 4;
	second_monom[0].degX = -8;
	second_monom[0].degY = 5;
	second_monom[0].degZ = 9;
	Polinom first_polinom(second_monom, 1);
	Polinom second_polinom;
	ASSERT_NO_THROW(second_polinom = first_polinom * first_monom[0]);
}

TEST(Polinom, multiplying_a_polynomial_by_a_monomial_with_a_nonzero_coefficient_does_not_change_the_size_of_the_polynomial){
	Monom* first_monom = new Monom[1], * second_monom = new Monom[1];
	first_monom[0].coeff = 15;
	first_monom[0].degX = 7;
	first_monom[0].degY = -2;
	first_monom[0].degZ = 1;
	Polinom first_polinom(first_monom, 1);
	second_monom[0].coeff = 4;
	second_monom[0].degX = -8;
	second_monom[0].degY = 5;
	second_monom[0].degZ = 9;
	int size = first_polinom.GetSize();
	Polinom second_polinom;
	second_polinom = first_polinom * second_monom[0];
	EXPECT_EQ(size, second_polinom.GetSize());
}

TEST(Polinom, multiplying_a_polynomial_by_a_monomial_with_a_zero_coefficient_makes_the_polynomial_empty) {
	Polinom res;
	Monom* first_monom = new Monom[1], * second_monom = new Monom[1];
	first_monom[0].coeff = 15;
	first_monom[0].degX = 7;
	first_monom[0].degY = -2;
	first_monom[0].degZ = 1;
	Polinom first_polinom(first_monom, 1);
	Polinom second_polinom(first_monom, 1);
	second_monom[0].coeff = 4;
	second_monom[0].degX = -8;
	second_monom[0].degY = 5;
	second_monom[0].degZ = 9;
	second_polinom = first_polinom * second_monom[0];
	EXPECT_EQ(1, second_polinom.GetSize());
}



TEST(Polinom, can_multiply_a_no_empty_polinom_by_a_no_empty_polinom){
	Polinom third_polinom;
	Monom* first_monom = new Monom[1], * second_monom = new Monom[1];
	first_monom[0].coeff = 15;
	first_monom[0].degX = 7;
	first_monom[0].degY = -2;
	first_monom[0].degZ = 1;

	second_monom[0].coeff = 4;
	second_monom[0].degX = -8;
	second_monom[0].degY = 5;
	second_monom[0].degZ = 9;
	Polinom first_polinom(first_monom, 1);
	Polinom second_polinom(second_monom, 1);
	ASSERT_NO_THROW(third_polinom = first_polinom * second_polinom);
	ASSERT_NO_THROW(first_polinom *= second_polinom);
}

TEST(Polinom, can_add_up_a_no_empty_polinom_by_a_no_empty_polinom){
	Monom* first_monom = new Monom[1], * second_monom = new Monom[1];
	second_monom[0].coeff = 4;
	second_monom[0].degX = -8;
	second_monom[0].degY = 5;
	second_monom[0].degZ = 9;
	Polinom first_polinom(first_monom, 1);
	Polinom second_polinom(second_monom, 1);
	ASSERT_NO_THROW(Polinom third_polinom = first_polinom + second_polinom);
	ASSERT_NO_THROW(first_polinom += second_polinom);
}
