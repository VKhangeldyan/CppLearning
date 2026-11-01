long arrayManipulation(int n, vector<vector<int>> queries) {
    
    std::vector<long> arr(n + 2, 0);
    long maxVal = 0;
    long currentSum = 0;
    
    for (const auto& q : queries) {
        int a = q[0];
        int b = q[1];
        int k = q[2];
        
        arr[a] += k;
        arr[b + 1] -= k;
    }
    
    for (int i = 1; i <= n; i++) {
        currentSum += arr[i];
        maxVal = currentSum > maxVal ? currentSum : maxVal;
    }
    
    return maxVal;
    
}