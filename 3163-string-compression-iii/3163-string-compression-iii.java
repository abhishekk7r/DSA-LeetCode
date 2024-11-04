class Solution {
    public String compressedString(String word) {
        String word2 = word + "$";

        int i = 0;
        int n = word2.length();
        StringBuilder str = new StringBuilder();
        int count = 1;
        Character c = ' ';
        while(i<n){
            if(i == 0) {
                c = word2.charAt(i);
                i++;
                continue;
            }
            Character d = word2.charAt(i);
            if(d == c && count < 9){
                count++;
            } else {
                str.append(count);
                str.append(c);
                c = d;
                count = 1;
            }

            i++;
        }

        return str.toString();
    }
}