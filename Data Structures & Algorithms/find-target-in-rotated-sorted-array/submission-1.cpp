class Solution {
public:

    int rBinSearch(vector<int>& nums,int target,int pivot,int n){

        int s = pivot;
        int e = n-1;

        while(s<=e){

            int mid = s+((e-s)/2);

            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid] <= target){
                s = mid+1;
            }
            else{
                e = mid-1;
            }
        }

        return -1;
    }

    int lBinSearch(vector<int>& nums,int target,int pivot,int n){

        int s = 0;
        int e = pivot-1;

        while(s<=e){

            int mid = s+((e-s)/2);

            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid] <= target){
                s = mid+1;
            }
            else{
                e = mid-1;
            }
        }

        return -1;
    }

    int minEleIndex(vector<int>& nums, int target, int n){

        int s = 0;
        int e = n-1;

        while(s<=e){

            if(nums[s] <= nums[e]){
                return s;
            }

            int mid = s+((e-s)/2);
            int prev = (mid+n-1)%n;
            int next = (mid+1)%n;

            if(nums[mid] <= nums[prev] && nums[mid] <= nums[next]){
                return mid;
            }
            else if(nums[s] <= nums[mid]){
                s = mid+1;
            }
            else if(nums[mid] <= nums[e]){
                e =  mid-1;
            }
        }

        return 0;
    }

    int search(vector<int>& nums, int target) {

        int n = nums.size();
        int pivot = minEleIndex(nums,target,n);

        int res1 = lBinSearch(nums,target,pivot,n);

        if(res1>=0){
            return res1;
        }

        int res2 = rBinSearch(nums,target,pivot,n);

        return res2;
    }
};
