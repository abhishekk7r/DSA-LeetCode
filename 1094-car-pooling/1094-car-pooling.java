class Solution {
    public boolean carPooling(int[][] trips, int capacity) {
        int [] cost = new int[1007];

        for(int i=0; i<trips.length; i++){
            cost[trips[i][1]] += trips[i][0];
            cost[trips[i][2]] += (-1) * trips[i][0];
        }
        
        int maxCap = 0;
        for(int i=0; i<1000; i++){
            maxCap += cost[i];
            if(maxCap > capacity) return false;
        }


        return true;

    }
}