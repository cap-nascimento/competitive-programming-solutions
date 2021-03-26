/*
    Code to implement various algorithms to use on geometry problems.
*/
#include <bits/stdc++.h>
using namespace std;

/*
****************************************
*   Common classes to the algorithms   *
****************************************
*/

class Point{
public:
    double x, y;
    Point(double x, double y){
        this->x = x;
        this->y = y;
    }
};

/*
****************************************
*             Algorithms               *
****************************************
*/

/*
*   Graham's Scan Convex Hull
*   Source: https://cp-algorithms.com/geometry/grahams-scan-convex-hull.html
*
*   a -> vector with points
*
*   return points used on convex hull
*/
bool cmp(Point a, Point b){
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}

bool cw(Point a, Point b, Point c){
    return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) < 0;
}

bool ccw(Point a, Point b, Point c){
    return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) > 0;
}

void graham_convex_hull(vector<Point>& a){
    if(a.size() == 1)
        return;

    sort(a.begin(), a.end(), &cmp);
    Point p1 = a[0], p2 = a.back();
    vector<Point> up, down;
    up.push_back(p1);
    down.push_back(p1);
    for(int i = 1; i < (int)a.size(); i++){
        if(i == (int)a.size()-1 || cw(p1, a[i], p2)){
            while(up.size() >= 2 && !cw(up[up.size()-2], up[up.size()-1], a[i]))
                up.pop_back();
            up.push_back(a[i]);
        }
        if(i == (int)a.size()-1 || ccw(p1, a[i], p2)){
            while(down.size() >= 2 && !ccw(down[down.size()-2], down[down.size()-1], a[i]))
                down.pop_back();
            down.push_back(a[i]);
        }
    }

    a.clear();
    for(int i=0;i<(int)up.size();i++)
        a.push_back(up[i]);

    for(int i=down.size()-2;i>0;i--)
        a.push_back(down[i]);
}

double dist(double x1, double y1, double x2, double y2){
    return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

int main()
{
    // Test Graham Scan Convex Hull O(n log n)
    vector<Point> points = {
        Point(0, 8), Point(1, 6),
        Point(8, 7), Point(6, 6),
        Point(8, 0), Point(3, 1)
    };

    graham_convex_hull(points);

    double total_length = dist(points[0].x, points[0].y, 
        points[points.size()-1].x, points[points.size()-1].y);

    for(int i=0;i<(int)points.size()-1;i++)
        total_length += dist(points[i].x, points[i].y, points[i+1].x, points[i+1].y);

    cout << fixed << setprecision(2) << total_length << endl;
    
}
