class Solution {
    public int reverseBits(int n) {
        int ans = 0;
        for (int i = 0; i < 32; i++) {
            ans <<= 1; // Shift result left : Makes space for the new bit
            ans |= (n & 1); // Extract last bit: And add last bits
            n >>= 1; // Shift n results
        }
        return ans;
    }
}
