class Solution {
public:

    bool BinSearch(vector<int>& nums, int s, int e, int target){

        while(s<=e){

            int mid = s+((e-s)/2);

            if(nums[mid] == target) return true;

            else if(nums[mid]<target) s=mid+1;

            else{
                e=mid-1;
            }
        }

        return false;
    }

    int findPivot(vector<int>& nums,int s,int e){

        while(s<e){
        while(s<e && (nums[s] == nums[s+1]))
        s++;

        while(s<e && (nums[e] == nums[e-1]))
        e--;

        int mid = s+((e-s)/2);

        if(nums[mid]>nums[e]){
            s=mid+1;
        }

        else{
            e=mid;
        }
    }

    return e;
}

    bool search(vector<int>& nums, int target) {

        int n = nums.size();

        int pivot = findPivot(nums,0,n-1);

        int res = BinSearch(nums,0,pivot-1,target);
        if(res){
            return res;
        }

        return BinSearch(nums,pivot,n-1,target);
    }
};