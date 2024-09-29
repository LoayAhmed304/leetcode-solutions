class Solution {
public:
    double radius;
    double x_center;
    double y_center;
    Solution(double radius, double x_center, double y_center):radius(radius), x_center(x_center), y_center(y_center) { }
    
    vector<double> randPoint() {
        double theta = ((double) rand() / RAND_MAX) * 2 * M_PI;
        double R = radius * sqrt((double) rand() / RAND_MAX);

        double new_x = x_center + R * cos(theta);
        double new_y = y_center + R * sin(theta);
        return {new_x, new_y};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */
