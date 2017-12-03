//
// Created by asem on 03.12.17.
//
#include <algorithm>
#include <cstdio>
#include <list>
#include <cmath>
using namespace std;
typedef int CoordinateT;
class Point {
public:
    static Point* central; // used only for comparing points.
    CoordinateT x;
    CoordinateT y;
    Point(CoordinateT x,CoordinateT y){
        Point::x = x;
        Point::y = y;
    }
    bool operator < (const Point& other) const {
        CoordinateT vmulZ = *this*other;
        if(vmulZ < 0) return true;
        else if(vmulZ == 0 && (*this).vectorLenghtInPow2() < other.vectorLenghtInPow2()) return true;
        return false;
    }
    CoordinateT operator * (const Point & other) const {
        // this func calculate Z coordinate of the result vector multiplication vectors
        // consists:
        // 1) central and this points
        // 2) central and other points
        CoordinateT thisX = x - central->x;
        CoordinateT thisY = y - central->y;
        CoordinateT otherX = other.x - central->x;
        CoordinateT otherY = other.y - central->y;
        return thisX*otherY - otherX*thisY;
    }
    CoordinateT vectorLenghtInPow2() const {
        // this function calculate length of vector consists central and this points
        return (x - central->x)*(x - central->x) + (y - central->y)*(y - central->y);
    }
};
typedef Point* PointPtr;
Point* Point::central;

bool cmpPointPtr(const PointPtr &a,const PointPtr &b){
    return *a < *b;
}

int main(int argc, char* argv[]){
    int countPoints;
    scanf("%d",&countPoints);
    list<PointPtr> points;
    for (int i = 0; i < countPoints; ++i) {
        int x,y;
        scanf("%d %d",&x, &y);
        points.push_back(new Point(x,y));
    }
    typedef list<PointPtr>::iterator PointIt;
    PointIt firstPoint = max_element(points.begin(),points.end(),[](const PointPtr &a, const PointPtr &b) -> bool {
        if(a->x < b->x) return true;
        else if(a->x == b->x && a->y > b->y) return true;
        return false;
    });
    list<PointPtr> hull;
    hull.push_back(*firstPoint);
    Point::central = *firstPoint;
    double perimeter = 0;
    do {
        PointIt next = max_element(points.begin(),points.end(),cmpPointPtr);
        perimeter += sqrt((*next)->vectorLenghtInPow2());
        Point::central = *next;
        hull.push_back(Point::central);
        points.erase(next);
    }while(Point::central != *firstPoint);
    printf("%lf\n",perimeter);
    for(auto e:points) delete e;
    for(auto e:hull) delete e;
}
