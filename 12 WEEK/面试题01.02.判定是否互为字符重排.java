class Solution {
    public boolean CheckPermutation(String s1, String s2) {
        if (s1.length() != s2.length()) {
            return false;
        }
        int[] table = new int[128];
        for (int i = 0; i < s1.length(); i++) {
            table[s1.charAt(i)]++;
        }
        for (int i = 0; i < s2.length(); i++) {
            table[s2.charAt(i)]--;
            if (table[s2.charAt(i)] < 0) {
                return false;
            }
        }
        return true;
    }
}