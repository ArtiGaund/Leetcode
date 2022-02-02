class Solution {
public:
    int getSum(int a, int b) {
      unsigned int ua = (unsigned int) a; 
          unsigned int ub = (unsigned int) b;

          while(ub){ // Repeat as long as there is no carry
            /*Make sure to make carry 64bit wide since left shifting uint32 gives error*/

              uint64_t carry = ua & ub; //bitwise AND gets the carry values
              ua = ua ^ ub; //XOR gives the ADDITION values without taking the carry values into account
              ub = carry << 1; // We left shift the carry value to be able to use it
          }

          return (int)ua; //Converting the unsigned back to signed does the trick
    }
};