class Solution {
    public int lengthOfLastWord(String s) {
        String[] words = s.trim().split("\\s+");
        int n = words.length;
        String word = words[n-1];
        return word.length();
    }
}