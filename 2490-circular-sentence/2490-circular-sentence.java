class Solution {
    public boolean isCircularSentence(String sentence) {
        int n = sentence.length();

        String []words = sentence.split(" ");
        // if(words.length == 1){
        // if (sentence.charAt(0) != sentence.charAt(n - 1)) {
        //         return false;
        //     }
        // }

        char last = words[0].charAt(words[0].length() - 1);

        for(int i = 1; i<words.length; i++){
            if(last != words[i].charAt(0)){
                return false;
            }

            last = words[i].charAt(words[i].length() - 1);
        }

        return last == sentence.charAt(0);
    }
}