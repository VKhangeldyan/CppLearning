long repeatedString(string s, long n) {
    long count = 0;
    long repeatCount = n / s.length();
      for(int i = 0; i < s.length(); i++) {
        if(s[i] == 'a') {
            count++;
        }
      }
      count = count * repeatCount;
      for(int i = 0; i < n % s.length(); i++) {
        if(s[i] == 'a') {
            count++;
        }
      }
      return count;
}