class Solution {
    public int romanToInt(String s) {
        String t = " " + s;
        int len = t.length() - 1;
        int sum = 0;
        
        for (int i = len; i >= 0; --i) {
            if (t.charAt(i) == 'I') {
                sum += 1;
            } else if (t.charAt(i) == 'V') {
                if (t.charAt(i-1) == 'I') {
                    sum += 4;
                    --i;
                } else {
                    sum += 5;
                }
            } else if (t.charAt(i) == 'X') {
                if (t.charAt(i-1) == 'I') {
                    sum += 9;
                    --i;
                } else {
                    sum += 10;
                }                
            } else if (t.charAt(i) == 'L') {
                if (t.charAt(i-1) == 'X') {
                    sum += 40;
                    --i;
                } else {
                    sum += 50;
                }                
            } else if (t.charAt(i) == 'C') {
                if (t.charAt(i-1) == 'X') {
                    sum += 90;
                    --i;
                } else {
                    sum += 100;
                }                
            } else if (t.charAt(i) == 'D') {
                if (t.charAt(i-1) == 'C') {
                    sum += 400;
                    --i;
                } else {
                    sum += 500;
                }                
            } else if (t.charAt(i) == 'M') {
                if (t.charAt(i-1) == 'C') {
                    sum += 900;
                    --i;
                } else {
                    sum += 1000;
                }                
            }
        }
        
        return sum;
    }
}