/*
 * cpp_lerning_test.cpp
 *
 *  Created on: 2023/07/11
 *      Author: k-abe
 */
#include "CppUTest/TestHarness.h"
#include "default_argument.h"

TEST_GROUP(CppLerningTestGroup)
{

};

// デフォルト引数を使わない
TEST(CppLerningTestGroup, defaultArgumentNone)
{
	LONGS_EQUAL(7, defargtest_add(3, 4));
}

// 第1引数のみデフォルト引数 -> コンパイルエラー
//TEST(CppLerningTestGroup, defaultArgument_arg1)
//{
//	LONGS_EQUAL(4, defargtest_add(, 3));
//}

// 第2引数のみデフォルト引数
TEST(CppLerningTestGroup, defaultArgument_arg2)
{
	LONGS_EQUAL(2, defargtest_add(0));
}

// 第1, 2引数ともにデフォルト引数
TEST(CppLerningTestGroup, defaultArgument_arg1_2)
{
	LONGS_EQUAL(3, defargtest_add());
}
