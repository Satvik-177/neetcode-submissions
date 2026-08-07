class Solution {
public:
    int findMin(vector<int> &nums) {

        int n = nums.size();

        int s = 0;
        int e = n-1;

        while(s<=e){

            if(nums[s]<=nums[e]){
                return nums[s];
            }

            int mid = s+((e-s)/2);

            int prev = (mid+n-1)%n;
            int next = (mid+1)%n;

            if(nums[mid] <= nums[prev] && nums[mid] <= nums[next]){
                return nums[mid];
            }

            else if(nums[s]<=nums[mid]){
                s=mid+1;
            }
            
            else if(nums[mid]<=nums[e]){
                e=mid-1;
            }
        }

        return -1;
    }
};
