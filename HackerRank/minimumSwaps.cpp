int minimumSwaps(vector<int> arr) {
   int swaps = 0;
   int i = 0;
   
   while(i < arr.size()) {
    int currentIndex = arr[i] - 1;
    
    if(arr[i] != arr[currentIndex]) {
        int t = arr[i];
        arr[i] = arr[currentIndex];
        arr[currentIndex] = t;
        swaps++;
    } else {
        i++;
    }
   }
   return swaps;
}