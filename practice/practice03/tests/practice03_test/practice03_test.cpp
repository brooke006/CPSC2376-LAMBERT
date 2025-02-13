#include "pch.h"
#include <iostream>
#include <vector>
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

// Copy the MathUtils class here
class MathUtils
{
public:
    static int sumRange(int start, int end)
    {
        int sum{ 0 };
        for (int i{ start }; i <= end; ++i)
        {
            sum += i;
        }
        return sum;
    }

    static bool containsNegative(const std::vector<int>& numbers)
    {
        for (int i{ 0 }; i < static_cast<int>(numbers.size()); ++i)
        {
            if (numbers[i] < 0)
            {
                return true;
            }
        }
        return false;
    }

    static int findMax(const std::vector<int>& numbers)
    {
        if (numbers.empty())
        {
            return -1;
        }

        int maxVal{ numbers[0] };
        for (int i{ 1 }; i < static_cast<int>(numbers.size()); ++i)
        {
            if (numbers[i] > maxVal)
            {
                maxVal = numbers[i];
            }
        }
        return maxVal;
    }
};

namespace Practice03Tests
{
    TEST_CLASS(MathUtilsTests)
    {
    public:
        TEST_METHOD(TestSumRange)
        {
            Assert::AreEqual(15, MathUtils::sumRange(1, 5));
            Assert::AreEqual(3, MathUtils::sumRange(3, 3));
            Assert::AreEqual(0, MathUtils::sumRange(-2, 2));
        }

        TEST_METHOD(TestContainsNegative)
        {
            std::vector<int> test1{ 1, -2, 3, 4 };
            Assert::IsTrue(MathUtils::containsNegative(test1));

            std::vector<int> test2{ 1, 2, 3, 4 };
            Assert::IsFalse(MathUtils::containsNegative(test2));

            std::vector<int> test3;
            Assert::IsFalse(MathUtils::containsNegative(test3));
        }

        TEST_METHOD(TestFindMax)
        {
            std::vector<int> test1{ 1, 5, 3, 4 };
            Assert::AreEqual(5, MathUtils::findMax(test1));

            std::vector<int> test2{ 2, 2, 2, 2 };
            Assert::AreEqual(2, MathUtils::findMax(test2));

            std::vector<int> test3;
            Assert::AreEqual(-1, MathUtils::findMax(test3));
        }
    };
}
