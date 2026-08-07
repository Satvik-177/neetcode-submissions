class Solution {
public:
    int mySqrt(int x) {

        if(x==1 || x==0){
            return x;
        }

        int s = 1;
        int e = x;
        int ans = 0;

        while(s<=e){

            long long mid = s+((e-s)/2);

            if(mid*mid  == x){
                return mid;
            }

            else if(mid * mid < x){
                ans = mid;
                s = mid+1;
            }

            else{
                e = mid-1;
            }
        }

        return ans;
    }
};