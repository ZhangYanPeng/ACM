#include <stdio.h>
#include <math.h>

double GetMinTime(int d, int m, int a, int j){
    double t1, t2, t3;
    t1 = pow(d*0.5/j, 1.0/3.0);
    if(j * t1 <= a && j * t1 * t1 <= m){
        return t1 * 4;
    }
    t1 = sqrt(m*1.0/j);
    if(j*t1 <= a && m*t1*2 <= d){
        t2 = d*1.0/m - t1*2;
        return t1 * 4 + t2;
    }
    t1 = a*1.0/j;
    double aa = a;
    double bb = a*a*3.0/j;
    double cc = a*a*a*2.0/(j*j) - d;
    t3 = (sqrt(bb*bb - 4*aa*cc) - bb)/(aa*2);
    double vmax = a*a*1.0/j + a*t3;
    if(t3 >= 0 && vmax <= m){
        return t1 * 4 + t3 * 2;
    }
    t3 = m*1.0/a - a*1.0/j;
    t2 = d*1.0/m - (t1*2 + t3);
    return t1 * 4 + t3 * 2 + t2;
}

int main(int argc, char* argv[]){
    double time;
    int d, m, a, j;
    while(scanf("%d %d %d %d", &d, &m, &a, &j) != EOF){
        time = GetMinTime(d, m, a, j);
        time = ((int)(time*10 + 0.5)) * 0.1;
        printf("%.01f\n", time);
    }
    return 0;
}
