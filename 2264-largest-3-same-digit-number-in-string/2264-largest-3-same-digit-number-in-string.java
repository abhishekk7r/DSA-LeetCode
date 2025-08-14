class Solution {
    public String largestGoodInteger(String num) {
        char prev = ' ';
        int count = 1;
        StringBuilder sb = new StringBuilder();
        List<String> lst = new ArrayList<>();
        for (int i = 0; i < num.length(); i++) {
            char ch = num.charAt(i);

            if (ch == prev) {
                count++;
                sb.append(ch);

                if (count == 3){
                    
                    lst.add(sb.append(ch).toString());
                }
            } else {
                count = 1;
                prev = ch;
                sb = new StringBuilder();
            }

        }

        Collections.sort(lst, Collections.reverseOrder());
        return lst.isEmpty() == true ? "" : lst.get(0);
    }
}