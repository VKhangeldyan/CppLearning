void minimumBribes(vector<int> q) {
    
    int bribes = 0;
    
    for (int i = q.size() - 1; i >= 0; i--) {
        if (q[i] - (i + 1) > 2) {
            std::cout << "Too chaotic\n";
            return;
        }

        for (int j = std::max(0, q[i] - 2); j < i; j++) {
            if (q[j] > q[i]) {
                bribes++;
            }
        }
    }
    
    std::cout << bribes << std::endl;

}
