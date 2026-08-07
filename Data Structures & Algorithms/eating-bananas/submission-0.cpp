class Solution {
public:

    bool canEatAllBanana(vector<int>& piles, int banana, int h){

        int actualAnswer = 0;

        for(int& x: piles){
            actualAnswer += x/banana;

            if(x%banana != 0){
                actualAnswer++;
            }
        }

        return actualAnswer <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {

        int n = piles.size();

        int s = 1;
        int e = *max_element(begin(piles),end(piles));

        while(s<e){

            int mid = s+((e-s)/2);

            if(canEatAllBanana(piles,mid,h)){
                e=mid;
            }
            else{
                s=mid+1;
            }
        }

        return s;
    }
};
