class Solution {
public:
    bool isArmstrong(int n) {
        int digitCount = 0;
        int temp = n;
        while(temp!=0){
            temp = temp/10;
            digitCount++;
        }

        temp = n;
        int newnum = 0;
        while(temp!=0){
            int digit = temp%10;
            newnum += pow(digit,digitCount);
            temp = temp/10;
        }
        return (newnum == n);
    }
};