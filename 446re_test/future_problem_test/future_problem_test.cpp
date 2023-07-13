/*
 * future_problem_test.cpp
 *
 *  Created on: 2023/07/13
 *      Author: k-abe
 */
#include "CppUTest/TestHarness.h"
#include <time.h>
#include <string.h>
#include "2038.h"

TEST_GROUP(FutureProblemTestGroup)
{

};

TEST(FutureProblemTestGroup, pre2038problem)
{
	char date_str[256];

	memset(date_str, 0x00, sizeof(date_str));
	time_t tmr = 2147483647; /* UTC:2038/01/19 03:14:07 日本(UTC+9): 2038/01/19 12:14:07 */

	get_date_string(tmr, date_str, sizeof(date_str));
	STRCMP_EQUAL("2038/01/19 03:14:07", date_str);
}

TEST(FutureProblemTestGroup, 2038problem)
{
	char date_str[256];

	memset(date_str, 0x00, sizeof(date_str));
	time_t tmr = 2147483647; /* UTC:2038/01/19 03:14:07 日本(UTC+9): 2038/01/19 12:14:07 */
	tmr += 1; /* UTC:1901/12/13 20:45:52 日本(UTC+9): 1901/12/14 05:45:52 */

	get_date_string(tmr, date_str, sizeof(date_str));
//	STRCMP_EQUAL("1901/12/13 20:45:52", date_str);	// このテストは失敗することを確認した
	STRCMP_EQUAL("2038/01/19 03:14:08", date_str);	// テスト成功: 2038年問題対応済みであることがわかった
}
