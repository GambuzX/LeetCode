class Solution {
    public String addBinary(String a, String b) {
        boolean carry = false;
        int max_len = Math.max(a.length(), b.length());
        char[] result = new char[max_len+1];
        for (int i = 0; i < max_len; i++) {
            int s = carry ? 1 : 0;
            carry = false;
            
            int a_index = i < a.length() ? a.length()-i-1 : -1;
            int b_index = i < b.length() ? b.length()-i-1 : -1;
            
            if (a_index != -1 && a.charAt(a_index) == '1')
                s += 1;
            if (b_index != -1 && b.charAt(b_index) == '1')
                s += 1;
            
            result[max_len-i] = s%2 != 0 ? '1' : '0';
            if (s >= 2) carry = true;            
        }
        result[0] = carry ? '1' : '0';
        
        String res = new String(result);
        return res.charAt(0) == '0' ? res.substring(1) : res;
    }
}