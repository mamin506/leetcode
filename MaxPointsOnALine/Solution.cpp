#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <climits>

using namespace std;

/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */

struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

class Solution {
public:
    int maxPoints(vector<Point> &points) {
        auto comp = [](const Point &a, const Point &b)->bool { 
            return a.x < b.x;
        };

        int n = points.size();
        int max_count = 0;
        sort(points.begin(), points.end(), comp);
        for (int i = 0; i < n; ++i) {
            unordered_map<double, int> slope_map;
            Point& p1 = points[i];
            int same_point = 1;
            int local_max = 1;

            // only look for points after the current one since ,
            // we have taken care of line segments before i with j when
            // running iteration for previous values of i
            for (int j = i+1; j < n; ++j) {
                double m = 0.0;
                Point& p2 = points[j];
                if (p1.x == p2.x && p1.y == p2.y) {
                    same_point++;
                    local_max = max(local_max, same_point);
                    continue;
                } else if (p1.x == p2.x) {
                    m = INT_MAX;
                } else {
                    m = ((double)(p2.y-p1.y))/(p2.x-p1.x);
                }
                if (slope_map.find(m) == slope_map.end()) {
                    slope_map[m] = same_point;
                }
                slope_map[m]++;
                local_max = max(local_max, slope_map[m]);
            }
            max_count = max(local_max, max_count);
        }
        return max_count;
    }
    
};

int main(int argc, char *argv[]) {
    class Solution sol1;

    return 0;
}

