class Solution {

    //Shifting and frequency array.

public:
    int arrayPairSum(vector<int>& nums) {
        //Elements will lie in this range:

        long long int left = -10000;
        long long int right = 10000;

        //-10000 se le kar 10000 tak ke element chahiye to
        //size of the array will be 2*10000

        int size = right - left + 1;
        vector<int>freq(size, 0);

        for (int i = 0; i < nums.size(); i++) {
            freq[nums[i] - left]++;
        }

        //frequency array par iterate karo:
        int ans = 0;
        int Residue = 0;

        for (int i = left; i <= right; i++) {
            ans += (((freq[i - left]) + 1 - Residue) / 2) * i;
            Residue = (freq[i - left] + Residue) % 2;
        }
        return ans;
    }
};