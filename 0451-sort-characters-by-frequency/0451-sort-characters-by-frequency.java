class Solution {
    public String frequencySort(String s) {
        var mp = new HashMap<Character, Integer>();
        int n = s.length();

        for(var ch : s.toCharArray()){
            mp.put(ch, mp.getOrDefault(ch, 0) + 1);
        }

        var bucket = new ArrayList<List<Character>>();

        for(int i=0; i<=n; i++){
            bucket.add(new ArrayList<>());
        }

        for(var i : mp.keySet()){
            bucket.get(mp.get(i)).add(i);
        }

        var sb = new StringBuilder();

        for(int i = n; i>=1; i--){
            //repeat every char i times into the string
            for(var ch : bucket.get(i)){
                sb.append(String.valueOf(ch).repeat(i));
            }
        }

        return sb.toString();
    }
}