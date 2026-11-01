int countingValleys(int steps, string path) {
    int height = 0;
    int valleys = 0;
    
    for(int i = 0; i < steps; i++) {
        if(path[i] == 'U') {
            height++;
            
            if(height == 0) {
                valleys++;
            }
         } else if(path[i] == 'D') {
            height--;
        }
    }
    return valleys;
}