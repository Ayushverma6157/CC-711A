class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int tsum=0;
        for(int num:nums)
        {
            tsum+=num;
        }
        int target=tsum-x;
        if(target<0) return -1;
        int left=0;
        int csum=0;
        int maxl=-1;
        for(int right=0;right<nums.size();right++)
        {
            csum+=nums[right];
            while(csum>target)
            {
                csum-=nums[left];
                left++;
            }
            if(csum==target)
            {
                int length=right-left+1;
                maxl=max(maxl,length);
            }
        }
        if(maxl==-1) return -1;
        return nums.size()-maxl;
    }
};