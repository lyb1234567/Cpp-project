#include "pch.h"
#include "CppUnitTest.h"
#include"../2048/game board.h"
#include"../2048/Number.h"
#include"../2048/list.h"
#include"../2048/board.cpp"
#include"../2048/Number.cpp"
#include"../2048/list.cpp" 
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace My2048test
{
	TEST_CLASS(My2048test)
	{
	public:
		
		TEST_METHOD(Link_Test)
		{
			Board board;
			board.initwall();
			board.setnumber(3, 3, "2");
			board.setnumber(3, 9, "4");
			board.setnumber(3, 15, "2");
			board.setnumber(3, 21, "4");
			board.setnumber(9, 3, "4");
			board.setnumber(9, 9, "8");
			board.setnumber(9, 15, "4");
			board.setnumber(9, 21, "8");
			board.setnumber(15, 3, "16");
			board.setnumber(15, 9, "64");
			board.setnumber(15, 15, "32");
			board.setnumber(15, 21, "16");
			board.setnumber(21, 3, "32");
			board.setnumber(21, 9, "16");
			board.setnumber(21, 15, "4");
			board.setnumber(21, 21, "8");
			Node* temp = &board.nodearray_horizontal[3][3];
			Node *cur= &board.nodearray_vertical[3][3];
			Node* t1 = temp->next;
			Node* t2 = t1->next;
			Node* t3 = t2->next;
			Node* c1 = cur->next;
			Node* c2 = c1->next;
			Node* c3 = c2->next;
			Assert::AreEqual(0, t1->data.compare("4"));
			Assert::AreEqual(0, t2->data.compare("2"));
			Assert::AreEqual(0, t3->data.compare("4"));
			Assert::AreEqual(0, c1->data.compare("4"));
			Assert::AreEqual(0, c2->data.compare("16"));
			Assert::AreEqual(0, c3->data.compare("32"));
		}
		TEST_METHOD(Board_Info)
		{
			Board board;
			board.initwall();
			board.setnumber(3, 3, "2");
			string a = board.getnumber(3, 3);
			Assert::AreEqual(0, a.compare("2"));
		}
	};
}
