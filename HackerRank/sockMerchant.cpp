int sockMerchant(int n, vector<int> ar) {
    unordered_map<int, int> socks;
    int pairs = 0;
    
    for(int sock : ar) {
        socks[sock]++;
    }
    
    for(const auto& i : socks) {
        pairs += i.second / 2;
    }
    
    return pairs;
}