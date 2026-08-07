class Solution {
public:
    bool isPerfectSquare(int num) {

        if(num == 1)
        return true;

        int s = 1;
        int e = num;

        while(s<=e){

            long long mid = s+((e-s)/2);

            if(mid*mid == num){
                return true;
            }

            else if(mid*mid < num){
                s = mid+1;
            }
            else{
                e = mid-1;
            }
        }

        return false;
    }
};