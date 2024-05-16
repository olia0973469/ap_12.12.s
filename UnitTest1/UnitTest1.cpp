#include "pch.h"
#include "CppUnitTest.h"
#include "../ap_12.12.s/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			StudentGroup group;
			group.addStudent({ "Biba", 85, 90, 92 });

			std::ostringstream out;
			std::streambuf* coutbuf = std::cout.rdbuf();
			std::cout.rdbuf(out.rdbuf());
			group.print();
			std::cout.rdbuf(coutbuf);

			Assert::IsTrue(out.str().find("Biba") != std::string::npos);
		}
	};
}
