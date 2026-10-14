class Solution {
public:
    int mySqrt(int x) {
        for (int i=1;i<=(x/2 +1);i++){
            double j=i+1;
            double h =int (x);
            if(h==i*i){
                return i;
            }else{
                 if(h>(i*i) && h<(j*j)){
                return i;
            }
            }
        }
        return 0;
    }
};