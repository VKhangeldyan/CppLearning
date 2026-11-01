vector<int> rotLeft(vector<int> a, int d) {

    vector<int> rotVec(a.size());
    
    for (int i = 0; i < a.size(); i++) {
        rotVec[i] = a[(i + d) % a.size()];
    }
    
    return rotVec;
}