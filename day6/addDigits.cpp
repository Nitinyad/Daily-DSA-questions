
// WITHOUT USING RECURSION
class Solution {
public:
    int sum(int n){
        int s = 0;
        while(n){
            s += n%10;
            n /=10;
        }
        return s;
    }
    int addDigits(int num) {
        while(num/10!=0){
            num = sum(num);
        }
        return num;
    }
};


// USING RECURSION
class Solution {
public:
    int addDigits(int num) {
        int rem = 0;
        int sum = 0;
        if(num >= 0 && num <= 9){
            return num;
        }
        while(num!=0){
            rem = num%10;
            sum += rem;
            num /= 10;
        }
        return addDigits(sum);
    }
};
