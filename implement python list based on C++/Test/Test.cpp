#include "pch.h"
#include "CppUnitTest.h"
#include"../Python_lst/Link_list.h"
#include"../Python_lst/list.h"
#include"../Python_lst/implement_link_list.cpp"
#include"../Python_lst/implement_list.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Test
{
	TEST_CLASS(Test)
	{
	public:
		TEST_METHOD(return_Index)
		{
			list a;
			a.append(3);
			Assert::AreEqual(0, a.index(3));
		}
		TEST_METHOD(Length)
		{
			list a;
			a.append(3);
			a.append(4);

			Assert::AreEqual(2, a.len());
		}
		TEST_METHOD(index_number)
		{
			list a;
			a.append(3);
			a.append(4);
			Assert::AreEqual(4, 4);
		}
		TEST_METHOD(add)
		{
			list a;
			a.append(3);
			a.append(4);
			a + 3;
			Assert::AreEqual(6,6);
		}
		TEST_METHOD(minus)
		{
			list a;
			a.append(3);
			a.append(4);
			a-3;
			Assert::AreEqual(0,a[0]);
		}
		TEST_METHOD(str_list)
		{
			list a("sda");
			Assert::AreEqual(3, a.len());
		}
		TEST_METHOD(index_str)
		{
			list a("sda");
			Assert::AreEqual(0, a.index("s"));
		}
		TEST_METHOD(sorting)
		{
			list a;
			a.append(3);
			a.append(4);
			a.append(1);
			a.append(2);
			a.sort();
			Assert::AreEqual(1.0, a.min());
			Assert::AreEqual(4.0, a.max());
		}
		TEST_METHOD(max_min)
		{
			list a;
			a.append(3);
			a.append(4);
			a.append(1);
			a.append(2);
			Assert::AreEqual(1.0, a.min());
			Assert::AreEqual(4.0, a.max());
		}
		TEST_METHOD(pop)
		{
			list a;
			a.append(3);
			a.append(4);
			a.append(1);
			a.append(2);
			Assert::AreEqual(2.0, a.pop());
		}
		TEST_METHOD(count)
		{
			list a;
			a.append(3);
			a.append(4);
			a.append(4);
			a.append("s");
			a.append("s");
			a.append(1);
			a.append(2);
			Assert::AreEqual(2, a.count("s"));
			Assert::AreEqual(2, a.count(4));
		}
		TEST_METHOD(clear)
		{
			list a;
			a.append(3);
			a.append(4);
			a.append(4);
			a.append("s");
			a.append("s");
			a.append(1);
			a.append(2);
			a.clear();
			Assert::AreEqual(0, a.len());
		}
		TEST_METHOD(equal_test)
		{
			list a;
			list b;
			a.append(5);
			a.append(6);
			b.append(4);
			string i = (a == b);
			int h;
			if (i == "True")
			{
				h = 1;
			}
			else if (i == "False")
			{
				h = 0;
			}
			Assert::AreEqual(0, h);
		}
		TEST_METHOD(copy_test)
		{
			list a;
			list b;
			a.append(5);
			a.append(6);
			b.append(4);
			string i = (a == b);
			int h;
			if (i == "True")
			{
				h = 1;
			}
			else if (i == "False")
			{
				h = 0;
			}
			Assert::AreEqual(0, h);
		}
		TEST_METHOD(not_equal)
		{
			list a;
			list b;
			a.append(5);
			a.append(6);
			b.append(4);
			string i = (a != b);
			int h;
			if (i == "True")
			{
				h = 1;
			}
			else if (i == "False")
			{
				h = 0;
			}
			Assert::AreEqual(1, h);
		}
		TEST_METHOD(insert_int)
		{
			list a;
			a.append(0);
			a.append(1);
			a.insert(1, 2);
			Assert::AreEqual(2, a[1]);
		}
	};
}
