class Solution {
public:
    
    bool isLargestSum(vector<int>& nums, int k, int mid, int n){

        int subArrayCount = 1;
        int currSum  = 0;

        for(int i=0; i<n; i++){

            if(currSum + nums[i] <= mid){
                currSum += nums[i];
            }
            else{
                subArrayCount++;
                if((subArrayCount) > k || (nums[i] > mid))
                return false;

                currSum = nums[i];
            }
        }

        return true;
    }

    int splitArray(vector<int>& nums, int k) {

        int s = 0;
        int sum = 0;
        int ans = -1;
        int n = nums.size();

        for(int& x: nums){
            sum += x;
        }

        int e = sum;

        while(s<=e){

            int mid = s+((e-s)/2);

            if(isLargestSum(nums,k,mid,n)){
                ans = mid;
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }

        return ans;
    }
};