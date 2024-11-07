class Solution {
    
    public int largestCombination(int[] candidates) {
        List<Integer> lst = new ArrayList<>(Collections.nCopies(24, 0));

        for(var k:candidates){
            String bits = Integer.toBinaryString(k);
            String reversedStr = new StringBuilder(bits).reverse().toString();

            for(int i=0; i<reversedStr.length(); i++){
                if(reversedStr.charAt(i) == '1'){
                    lst.set(i, lst.get(i) + 1);
                }
            }
        }

        int maxi = Integer.MIN_VALUE;

        for(var i:lst){
            maxi = Math.max(maxi, i);
        }

        return maxi;
    }
}