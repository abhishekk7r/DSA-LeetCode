class Solution {
    public boolean isValidSudoku(char[][] board) {
        // Prepare 9 sets for rows, cols and boxes
        List<Set<Character>> rows = new ArrayList<>(9);
        List<Set<Character>> cols = new ArrayList<>(9);
        List<Set<Character>> boxes = new ArrayList<>(9);
        for (int i = 0; i < 9; i++) {
            rows.add(new HashSet<>());
            cols.add(new HashSet<>());
            boxes.add(new HashSet<>());
        }

        // Single pass over the board
        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                char ch = board[r][c];
                if (ch == '.') continue;

                int boxId = (r / 3) * 3 + (c / 3);

                // If any of row/col/box already contains this digit -> invalid
                if (rows.get(r).contains(ch) ||
                    cols.get(c).contains(ch) ||
                    boxes.get(boxId).contains(ch)) {
                    return false; // duplicate found
                }

                // Otherwise add to the trackers
                rows.get(r).add(ch);
                cols.get(c).add(ch);
                boxes.get(boxId).add(ch);
            }
        }

        // No duplicates found
        return true;
    }
}
