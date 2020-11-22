#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

bool IsDuplicate(vector<int> nums, size_t k)
{
    size_t n = nums.size();

    for(size_t i(0); i < n - 1; i++)
    {
        for(size_t j = i+1; j <= (i + k); j++)
        {
            if(j >= n)
                break;

            if(nums[i] == nums[j])
            {
                cout << "Function 1: Duplicate elements:" << nums[i] << " " << i << " " << j << endl;
                return true;
            }
        }
    }

    return false;
}

bool IsDuplicate2(vector<int> nums, size_t k)
{
    size_t n = nums.size();

    unordered_map<int, int> h;

    for(size_t i(0); i < n; i++)
    {
        if(h.find(nums[i]) != h.end())
        {
            if( (i - h[nums[i]]) <= k)
            {
                cout << "Function 2: Duplicate elements:" << nums[i] << " " << i << " " << h[nums[i]] << endl;
                return true;
            }
            else
                h.insert(make_pair(nums[i], i));
        }
        else
        {
            h[nums[i]] = i;
        }
    }

    return false;
}

int main()
{
    vector<int>     nums;

//    for(int i(0); i < 10; i++)
//        nums.push_back(rand() % 100);

    nums.push_back(1);
    nums.push_back(3);
    nums.push_back(6);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(1);
    nums.push_back(5);
    nums.push_back(5);

    size_t k(3);

    cout << "Vector:";
    for(int i : nums)
        cout << i << "\t";

    cout << endl << "Min Difference to be checked:" << k << endl;

    if(IsDuplicate(nums, k))
    {
        cout << "Function1: Duplicate elements present less than " << k << " elements apart" << endl;
    }
    else
    {
        cout << "Function1: No Duplicate elements present less than " << k << " elements apart" << endl;
    }

    if(IsDuplicate2(nums, k))
    {
        cout << "Function2: Duplicate elements present less than " << k << " elements apart" << endl;
    }
    else
    {
        cout << "Function2: No Duplicate elements present less than " << k << " elements apart" << endl;
    }
}
