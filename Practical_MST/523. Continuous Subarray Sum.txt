class Solution {
    public boolean checkSubarraySum(int[] nums, int k) {
    HashMap<Integer,Integer> map=new HashMap<>();
    map.put(0,-1);
    int psum=0;
    for(int i=0;i<nums.length;i++)
    {
        psum+=nums[i];
        if(map.containsKey(psum%k))
        {
            int j=map.get(psum%k);
            if(i-j>1) return true;
        }
        else
        {
            map.put(psum%k,i);
        }
    }
    return false;

    }
}