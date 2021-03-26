/*
	Anderson Vieira's solution
	Don't copy this, try for yourself
*/
#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define rep(i, a, b) for(int i = (int)a; i < (int)b; i++)
#define vi vector<int>
#define ii pair<int, int>
#define ll pair<long long, long long>
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define MAX 1000010
#define MOD 1000000007
#define oo 0x7fffffff
#define lld long long int
#define endl '\n'
using namespace std;

class Point{
public:
    double x, y;
    Point(double x, double y){
        this->x = x;
        this->y = y;
    }
};

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
    
	int n;
	while(cin >> n && n){
	    vector<Point> points;
	    rep(i, 0, n){
	    	double x, y;
	    	cin >> x >> y;
	    	points.pb(Point(x, y));
	    }
	    graham_convex_hull(points);

	    double total_length = dist(points[0].x, points[0].y, 
	        points[points.size()-1].x, points[points.size()-1].y);

	    rep(i, 0, points.size()-1)
	        total_length += dist(points[i].x, points[i].y, points[i+1].x, points[i+1].y);

	    cout << "Tera que comprar uma fita de tamanho ";
	    cout << fixed << setprecision(2) << total_length << ".\n";
	}

    
}
