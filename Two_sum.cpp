//solution of leetcode problem 1: Two Sum

/*
By Brute force
Time Complexity: O(N^2)
Space Complexity: O(N)   
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size(); // size of the vector
        for (int i = 0; i < n; i++) // iterating through the array
        {
            int value = target - nums[i]; // {2, 5, 7, 11} -> if target = 7 then, value = 7 - 2 which gives 5  
            for (int j = i + 1; j < n; j++) // starting from i+1 to avoid using the same element
            {
                if (nums[j] == value) // here if value = 5 is in array then return {i,j} 
                {
                    return {i, j}; //loop will continue until it finds the pair
                }
            }
        }
        return {}; // this return statement is for the case when no pair is found
    }
};

/*
solution 2: using sorting + two pointer approach 
Time Complexity: O(N log N)
Space Complexity: O(N)
*/

class solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size(); //size of the vector
    vector<pair<int,int>> vtr; //vector of pairs to store the value and its index

    for(int i=0; i<n; i++) //iterating through the vector
    {
        vtr.push_back({nums[i], i}); //storing the value and its index as pair in vector
    }

    sort(vtr.begin(), vtr.end()); //sorting the vector based on the value
    int l = 0, r = vtr.size()-1; //two pointer approach
    
        while (l<r) //till both pointers meet
        {
        int sum = vtr[l].first + vtr[r].first; //sum of values at both pointers
        if(sum=target) //if sum is equal to target then return the indices of those values
            {
                return {vtr[l]second, vtr[r].second}; //returning the indices of the original array
            }
            else if(sum>target) //if sum is greater than target then move the right pointer to left
            {
                r--; //decrementing the right pointer
            }
            else
            {
                l++; //incrementing the left pointer
            }
        }
        return {}; //this return statement is for the case when no pair is found
    }
};

/*
solution 3: using hashing
Time Complexity: O(N)
Space Complexity: O(N)
*/

class solution {
    public:
    vector<int> twosum(vector<int>& nums, int target) {

        unordered_map<int, int> mp; //hash map to store the value and its index
        int n = nums.size(); //size of the vector
        for(int i=0; i<n; i++) //iterating through the vector
        {
            int value = target - nums[i]; //calculating the value needed to reach the target
            if(mp.find(value) != mp.end()) //if the value is found in the map then return the indices
            {
                return {mp[value], i}; //returning the indices of the original vector
            }
            mp[nums[i]] = i; //storing the value and its index in the map
        }
        return {}; //this return statement is for the case when no pair is found
    }
};

