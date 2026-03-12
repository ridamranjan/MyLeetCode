#include <iostream>
#include <vector>
using namespace std;

class Solution
{
    public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        for (int i = 0; i < nums.size() - 1; i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                if ((nums[i] + nums[j]) == target)
                {
                    return {i, j};
                }
            }
        }
        return {};
    }
};

int main()
{
    Solution s;
    vector<int> nums = {2, 13, 11, 7};
    int target = 9;
    vector<int> result = s.twoSum(nums, target);
    cout << "Indices: " << result[0] << ", " << result[1] << endl;
    return 0;
}