/*
 * @lc app=leetcode id=67 lang=cpp
 * @lcpr version=21912
 *
 * [67] Add Binary
 */

// @lc code=start
#include <string>
using namespace std;

class Solution {
   public:
    string addBinary(string a, string b) {
        /* normal brute force
        int carry = 0;
        int i = 0;
        string result;
        while (!a.empty() || !b.empty()) {
            int digit = carry;
            if (!a.empty()) {
                digit += a.back() - '0';
                a.pop_back();
            }
            if (!b.empty()) {
                digit += b.back() - '0';
                b.pop_back();
            }
            result += to_string(digit & 1);
            carry = digit >> 1;
        }

        if (carry) {
            result += '1';
        }
        reverse(result.begin(), result.end());
        return result;
        */

        // Bit manipulation. Add two numbers without using +. it's easier with python implementation.
        int a_int = stoi(a, nullptr, 2);
        int b_int = stoi(b, nullptr, 2);
        int answer_without_carry = a_int ^ b_int;
        int carry = a_int & b_int;
        while (carry) {
            answer_without_carry = answer_without_carry ^ carry;
            carry = answer_without_carry & carry;
        }
        std::string r;
        // or just int answer_without_carry = a_int + b_int;
        while (answer_without_carry != 0) {
            r = (answer_without_carry & 1 == 0 ? "0" : "1") + r;
            answer_without_carry >>= 1;
        }
        return r;
    }
};

/*

def addBinary(self, a: str, b: str) -> str:
    x = int(a,2)
    y = int(b,2)
    while y:
        x, y = x ^ y, (x & y) << 1
    # bin() returns the binary equivalent of input integer with prefix '0b'
    return bin(x)[2:]
*/
// @lc code=end

/*
// @lcpr case=start
// "11"\n"1"\n
// @lcpr case=end

// @lcpr case=start
// "1010"\n"1011"\n
// @lcpr case=end

 */
