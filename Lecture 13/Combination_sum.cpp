class Solution {
public:
    void FindSum(vector<int>candidates, int target, vector<vector<int>>&ans, vector<int>result, int sum, int index) {
        //Base Case:
        if (sum >= target) {
            if (sum == target) {
                ans.push_back(result);
            }
            return;
        }

        /*  a[] = 2 3 4 13; target = 8;
          i = 0;
          result[] = {2,}
                     sum = 2;

          i = 0;
          result[] = {2, 2};
          sum = 4;

          i = 0;
          result[] = {2, 2, 2};
          sum = 6;

          i = 0;
          result[] = {2, 2, 2, 2};
          sum = 8;

        base case hit hoga:
          8 == 8

          ans two vector:  2 2 2 2

          i = 0;
          result[] = {2, 2, 2};
          sum = 6;

          i=1;
          result[]={2,2,2,3}
          sum=9;
          result= 2,2,2
          sum=6;

        */


        for (int i = index; i < candidates.size(); i++) {

            result.push_back(candidates[i]);
            sum += candidates[i];
            FindSum(candidates, target, ans, result, sum, i);
            /*
                Two case will be there:

                i am not able to make sum==target
                so in this scenario what i will do is i will elimate the last element and move on.

                the sum was equal to target;

                2 + 2 + 2+ 2 =8
                sum=8 and target =8;

                ek ans = 2 + 2+2 next elementk check karo
            */
            result.pop_back();
            sum -= candidates[i];
        }
    }


    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>result;
        FindSum(candidates, target, ans, result, 0, 0);
        return ans;
    }
};