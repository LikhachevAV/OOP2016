#include "stdafx.h"
#include "..\MyArray\MyArray.h"

using namespace std;

struct ArrayItem
{
	ArrayItem(int value = 0) : value(value)
	{}
	int value;
};

struct EmptyStringArray
{
	CMyArray<ArrayItem> arr;
};

BOOST_FIXTURE_TEST_SUITE(MyArray, EmptyStringArray)
	BOOST_AUTO_TEST_SUITE(by_default)
		BOOST_AUTO_TEST_CASE(is_empty)
		{
			BOOST_CHECK_EQUAL(arr.GetSize(), 0u);
		}
		BOOST_AUTO_TEST_CASE(has_0_capacity)
		{
			BOOST_CHECK_EQUAL(arr.GetCapacity(), 0u);
		}
	BOOST_AUTO_TEST_SUITE_END()
	BOOST_AUTO_TEST_SUITE(after_appending_an_item)
		BOOST_AUTO_TEST_CASE(increases_its_size_and_capacity)
		{
			arr.Append(ArrayItem());
			BOOST_CHECK_EQUAL(arr.GetSize(), 1u);
			BOOST_CHECK_EQUAL(arr.GetCapacity(), 1u);
			arr.Append(ArrayItem());
			BOOST_CHECK_EQUAL(arr.GetSize(), 2u);
			BOOST_CHECK_EQUAL(arr.GetCapacity(), 2u);
			arr.Append(ArrayItem());
			BOOST_CHECK_EQUAL(arr.GetSize(), 3u);
			BOOST_CHECK_EQUAL(arr.GetCapacity(), 4u);
			arr.Append(ArrayItem());
			BOOST_CHECK_EQUAL(arr.GetSize(), 4u);
			BOOST_CHECK_EQUAL(arr.GetCapacity(), 4u);
		}
		BOOST_AUTO_TEST_CASE(it_becomes_available_at_the_back)
		{
			arr.Append(1);
			BOOST_CHECK_EQUAL(arr.GetBack().value, 1);
			arr.Append(2);
			BOOST_CHECK_EQUAL(arr.GetBack().value, 2);
			arr.Append(3);
			BOOST_CHECK_EQUAL(arr.GetBack().value, 3);
			arr.Append(4);
			BOOST_CHECK_EQUAL(arr.GetBack().value, 4);
		}
	BOOST_AUTO_TEST_SUITE_END()
	BOOST_AUTO_TEST_SUITE(after_copy_construction)
		BOOST_AUTO_TEST_CASE(has_size_capacity_equal_to_size_of_original_array)
		{
			for (auto i = 0; i < 6; ++i)
			{
				arr.Append(i);
			}
			BOOST_CHECK_NE(arr.GetSize(), arr.GetCapacity());

			auto copy(arr);
			BOOST_CHECK_EQUAL(copy.GetSize(), arr.GetSize());
			BOOST_CHECK_EQUAL(copy.GetCapacity(), arr.GetSize());
		}
	BOOST_AUTO_TEST_SUITE_END()

	BOOST_AUTO_TEST_SUITE(operator_get_array_item_by_index)
		BOOST_AUTO_TEST_CASE(throw_exception_when_index_more_than_array_size)
		{
			BOOST_CHECK_EQUAL(arr.GetSize(), 0);
			BOOST_CHECK_THROW(arr[1].value, std::out_of_range);
		}
		BOOST_AUTO_TEST_CASE(return_item)
		{
			for (auto i = 0; i < 3; ++i)
			{
				arr.Append(i);
				BOOST_CHECK_EQUAL(arr[i].value, i);
			}
		}		
	BOOST_AUTO_TEST_SUITE_END()

	BOOST_AUTO_TEST_SUITE(Clear_function)
		BOOST_AUTO_TEST_CASE(delete_all_array_items)
		{
			for (auto i = 0; i < 3; ++i)
			{
				arr.Append(i);
			}
			BOOST_CHECK_EQUAL(arr.GetSize(), 3);
			arr.Clear();
			BOOST_CHECK_EQUAL(arr.GetSize(), 0);
			BOOST_CHECK_EQUAL(arr.GetCapacity(), 0);
		}
	BOOST_AUTO_TEST_SUITE_END()


	BOOST_AUTO_TEST_SUITE(access_to_iterators_methods)
		BOOST_AUTO_TEST_CASE(return_begin_iterator)
		{
			for (auto i = 1; i < 3; ++i)
			{
				arr.Append(i);
			}
			BOOST_CHECK_EQUAL(arr.begin()->value, 1);
		}
		BOOST_AUTO_TEST_CASE(return_end_iterator)
		{
			for (auto i = 1; i < 3; ++i)
			{
				arr.Append(i);
			}
			auto itEnd = arr.end();
			itEnd--;
			auto lastIndex = arr.GetSize() - 1;
			BOOST_CHECK_EQUAL(itEnd->value, arr[lastIndex].value);
		}
	BOOST_AUTO_TEST_SUITE_END()

	BOOST_AUTO_TEST_SUITE(can_use_iterators_to_loop_array)
		BOOST_AUTO_TEST_CASE(_forward_and_backward)
		{
			for (auto i = 0; i < 3; ++i)
			{
				arr.Append(i);
			}
			auto t = 0;
			for (auto it = arr.begin(); it != arr.end(); it++)
			{
				BOOST_CHECK_EQUAL(it->value, t);
				t++;
			}
			t = arr.GetSize() - 1;
			for (auto it = arr.end() - 1; it >= arr.begin(); it--)
			{
				BOOST_CHECK_EQUAL(it->value, t);
				t--;
			}
		}
		BOOST_AUTO_TEST_CASE(_forward_and_backward_using_rbegin_and_rend)
		{
			for (auto i = 0; i < 3; ++i)
			{
				arr.Append(i);
			}
			auto t = 2;
			for (auto it = arr.rbegin(); it != arr.rend(); it++)
			{
				std::cout << it->value << endl;
				BOOST_CHECK_EQUAL(it->value, t);
				t++;
			}
		}
	BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()
