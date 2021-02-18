#include <../gtest/gtest.h>
#include "Converter.h"

TEST(test_converter, test_1){
	Converter parse;
	roman rome = { "I" };
	int value = parse.fromRomanToArabic(rome).value;
	EXPECT_EQ(1, value);
}

TEST(test_converter, test_4) {
	Converter parse;
	roman rome = { "IV" };
	int value = parse.fromRomanToArabic(rome).value;
	EXPECT_EQ(4, value);
}

TEST(test_converter, test_5){
	Converter parse;
	roman rome = { "V" };
	int value = parse.fromRomanToArabic(rome).value;
	EXPECT_EQ(5, value);
}

TEST(test_converter, test_6) {
	Converter parse;
	roman rome = { "VI" };
	int value = parse.fromRomanToArabic(rome).value;
	EXPECT_EQ(6, value);
}

TEST(test_converter, test_8) {
	Converter parse;
	roman rome = { "VIII" };
	int value = parse.fromRomanToArabic(rome).value;
	EXPECT_EQ(8, value);
}

TEST(test_converter, test_10) {
	Converter parse;
	roman rome = { "X" };
	int value = parse.fromRomanToArabic(rome).value;
	EXPECT_EQ(10, value);
}

TEST(test_converter, test_48) {
	Converter parse;
	roman rome = { "XLVIII" };
	int value = parse.fromRomanToArabic(rome).value;
	EXPECT_EQ(48, value);
}

TEST(test_converter, test_50){
	Converter parse;
	roman rome = { "L" };
	int value = parse.fromRomanToArabic(rome).value;
	EXPECT_EQ(50, value);
}

TEST(test_converter, test_89) {
	Converter parse;
	roman rome = { "LXXXIX" };
	int value = parse.fromRomanToArabic(rome).value;
	EXPECT_EQ(89, value);
}

TEST(test_converter, test_100) {
	Converter parse;
	roman rome = { "C" };
	int value = parse.fromRomanToArabic(rome).value;
	EXPECT_EQ(100, value);
}

TEST(test_converter, test_499) {
	Converter parse;
	roman rome = { "CDXCIX" };
	int value = parse.fromRomanToArabic(rome).value;
	EXPECT_EQ(499, value);
}

TEST(test_converter, test_500) {
	Converter parse;
	roman rome = { "D" };
	int value = parse.fromRomanToArabic(rome).value;
	EXPECT_EQ(500, value);
}

TEST(test_converter, test_1000) {
	Converter parse;
	roman rome = { "M" };
	int value = parse.fromRomanToArabic(rome).value;
	EXPECT_EQ(1000, value);
}

TEST(test_converter, test_I){
	arabic arab = { 1 };
	Converter parse;

	EXPECT_EQ("I", parse.fromArabicToRoman(arab).value);
}

TEST(test_converter, test_IV) {
	arabic arab = { 4 };
	Converter parse;

	EXPECT_EQ("IV", parse.fromArabicToRoman(arab).value);
}

TEST(test_converter, test_V) {
	arabic arab = { 5 };
	Converter parse;

	EXPECT_EQ("V", parse.fromArabicToRoman(arab).value);
}

TEST(test_converter, test_VI) {
	arabic arab = { 6 };
	Converter parse;

	EXPECT_EQ("VI", parse.fromArabicToRoman(arab).value);
}

TEST(test_converter, test_X) {
	arabic arab = { 10 };
	Converter parse;

	EXPECT_EQ("X", parse.fromArabicToRoman(arab).value);
}

TEST(test_converter, test_XLVIII) {
	arabic arab = { 48 };
	Converter parse;

	EXPECT_EQ("XLVIII", parse.fromArabicToRoman(arab).value);
}

TEST(test_converter, test_L) {
	arabic arab = { 50 };
	Converter parse;

	EXPECT_EQ("L", parse.fromArabicToRoman(arab).value);
}

TEST(test_converter, test_LXXXIX) {
	arabic arab = { 89 };
	Converter parse;

	EXPECT_EQ("LXXXIX", parse.fromArabicToRoman(arab).value);
}


TEST(test_converter, test_C) {
	arabic arab = { 100 };
	Converter parse;

	EXPECT_EQ("C", parse.fromArabicToRoman(arab).value);
}

TEST(test_converter, test_CDXCIX) {
	arabic arab = { 499 };
	Converter parse;

	EXPECT_EQ("CDXCIX", parse.fromArabicToRoman(arab).value);
}

TEST(test_converter, test_D) {
	arabic arab = { 500 };
	Converter parse;

	EXPECT_EQ("D", parse.fromArabicToRoman(arab).value);
}

TEST(test_converter, test_M) {
	arabic arab = { 1000 };
	Converter parse;

	EXPECT_EQ("M", parse.fromArabicToRoman(arab).value);
}

TEST(test_converter, checkRoman_false){
	roman rome = { "XXXXXXX" };
	Converter parse;

	EXPECT_EQ(false, parse.checkRoman(rome));
}

TEST(test_converter, checkRoman_true) {
	roman rome = { "CC" };
	Converter parse;

	EXPECT_EQ(true, parse.checkRoman(rome));
}