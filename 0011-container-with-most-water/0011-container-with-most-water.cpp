class Solution {
public:
    int maxArea(vector<int>& height) {
    long long l = 0;
    long long r = height.size()-1;
    long long w = 0;

    while(l<r){
        long long width = r - l;
        long long y = min(height[l], height[r]);
        w = max(w, width*y);

        if(height[r] < height[l]){
            r--;
        }
        else{
            l++;
        }
    }
    return (long long)w;
}
};