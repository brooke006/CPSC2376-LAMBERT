#include <iostream>
#include <vector>

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

int main()
{
    // Test sumRange
    std::cout << "Testing sumRange(1, 5): " << MathUtils::sumRange(1, 5) << '\n';

    // Test containsNegative
    std::vector<int> numbers{ 1, -2, 3, 4 };
    std::cout << "Testing containsNegative: " << MathUtils::containsNegative(numbers) << '\n';

    // Test findMax
    std::cout << "Testing findMax: " << MathUtils::findMax(numbers) << '\n';

    return 0;
}