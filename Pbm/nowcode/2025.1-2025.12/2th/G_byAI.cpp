#include <bits/stdc++.h>
using namespace std;

struct Point { long long x, y; };
void solve_G() {
    int n; 
    long long px, py;
    if (!(cin >> n >> px >> py)) return;
    vector<Point> poly(n);
    bool on_vertex = false;
    for(int i=0; i<n; i++) {
        cin >> poly[i].x >> poly[i].y;
        if(poly[i].x == px && poly[i].y == py) on_vertex = true;
    }
    
    if (on_vertex) {
        // Find internal angle at P.
        // Find neighbors.
        int idx = -1;
        for(int i=0; i<n; i++) if(poly[i].x == px && poly[i].y == py) idx = i;
        Point p_prev = poly[(idx - 1 + n) % n];
        Point p_next = poly[(idx + 1) % n];
        
        // Vectors
        double ax = p_prev.x - px, ay = p_prev.y - py;
        double bx = p_next.x - px, by = p_next.y - py;
        
        // Angle using atan2
        double ang1 = atan2(ay, ax);
        double ang2 = atan2(by, bx);
        
        double diff = ang2 - ang1;
        if (diff < 0) diff += 2 * M_PI;
        
        // Polygon is CCW. Vector next is "after" prev.
        // Interior angle is diff?
        // Wait, CCW order. P_prev -> P -> P_next.
        // Angle from (P -> P_next) to (P -> P_prev)? No.
        // We want the angle OCCUPIED by the polygon.
        // Standard formula for interior angle at P_i:
        // angle = atan2(det, dot).
        // det = cross_product(u, v). dot = dot_product(u, v).
        // u = P_next - P, v = P_prev - P.
        // angle in [0, 2pi].
        // Actually, simple subtraction of absolute angles?
        // Be careful with range.
        
        // The angle covered is the one "to the left" of P->P_next and "to the right" of P->P_prev?
        // No, P is a vertex.
        // Angle is from (P->P_next) to (P->P_prev) in CCW direction?
        // Usually angle is (arg(prev) - arg(next)) normalized?
        // Let's check Example 3.
        // P=(0,0). Prev=(1,1). Next=(1,-1).
        // arg(prev) = pi/4. arg(next) = -pi/4.
        // diff = pi/4 - (-pi/4) = pi/2.
        // Angle occupied is 90 deg.
        // Result is 2pi - pi/2 = 3pi/2.
        // So we need angle between prev and next.
        
        double ang_prev = atan2(ay, ax);
        double ang_next = atan2(by, bx);
        
        // Interior angle is (ang_prev - ang_next). Normalize to [0, 2pi).
        double interior = ang_prev - ang_next;
        while(interior < 0) interior += 2 * M_PI;
        while(interior >= 2 * M_PI) interior -= 2 * M_PI;
        
        cout << fixed << setprecision(15) << (2 * M_PI - interior) << endl;
        return;
    }
    
    // Check if P is inside
    // Sum of signed angles
    double sum_ang = 0;
    for(int i=0; i<n; i++) {
        Point p1 = poly[i];
        Point p2 = poly[(i+1)%n];
        double a1 = atan2(p1.y - py, p1.x - px);
        double a2 = atan2(p2.y - py, p2.x - px);
        double d = a2 - a1;
        while(d <= -M_PI) d += 2*M_PI;
        while(d > M_PI) d -= 2*M_PI;
        sum_ang += d;
    }
    
    bool inside = (abs(abs(sum_ang) - 2*M_PI) < 1e-5);
    
    if (!inside) {
        cout << fixed << setprecision(15) << 2 * M_PI << endl;
    } else {
        // P inside. Find max angular gap between vertices.
        vector<double> angles;
        for(int i=0; i<n; i++) {
            angles.push_back(atan2(poly[i].y - py, poly[i].x - px));
        }
        sort(angles.begin(), angles.end());
        double max_gap = 0;
        for(int i=0; i<n; i++) {
            double diff = angles[(i+1)%n] - angles[i];
            if (diff < 0) diff += 2 * M_PI;
            if (diff > max_gap) max_gap = diff;
        }
        cout << fixed << setprecision(15) << max_gap << endl;
    }
}


int main() {
  int T; cin >> T;
  while(T--) solve_G();
}