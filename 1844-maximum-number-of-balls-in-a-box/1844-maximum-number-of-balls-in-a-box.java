class Solution {
    private Integer getSumOfDigits(Integer n){
        Integer sum = 0;
        while(n>0){
            sum += n%10;
            n /= 10;
        }

        return sum;
    }
    public int countBalls(int lowLimit, int highLimit) {
        int maxCount = 0;
        HashMap<Integer, Integer> mp = new HashMap<>();
        for(int i=lowLimit; i<=highLimit; i++)
        {
            Integer sum = getSumOfDigits(i);
            mp.put(sum, mp.getOrDefault(sum, 0) + 1);
            maxCount = Math.max(maxCount, mp.get(sum));
        }

        return maxCount;
    }
}