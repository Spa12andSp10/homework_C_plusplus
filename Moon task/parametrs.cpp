#include "parametrs.h"
#include <iostream>
#include <cstring>
#include <algorithm>
#include <fstream>
#include <sstream>

double moonRice(string h1, string h2, string t1, string t2, string d2, string sd1)
{
    double H1, H2, t = -1;
    stringstream sh1(h1);
    sh1 >> H1;
    stringstream sh2(h2);
    sh2 >> H2;
    if (H1 <= 0 && H2 >= 0 && d2.substr(6, 2) == sd1)
    {
        double T1, T2;
        stringstream st1(t1);
        st1 >> T1;
        stringstream st2(t2);
        st2 >> T2;
        t = T1 + (T2 - T1) * (0 - H1) / (H2 - H1);
    }
    return t;
}

double moonSet(string h1, string h2, string t1, string t2, string d2, string sd1)
{
    double H1, H2, t = -1;
    stringstream sh1(h1);
    sh1 >> H1;
    stringstream sh2(h2);
    sh2 >> H2;
    if (H1 >= 0 && H2 <= 0 && d2.substr(6, 2) == sd1)
    {
        double T1, T2;
        stringstream st1(t1);
        st1 >> T1;
        stringstream st2(t2);
        st2 >> T2;
        t = T2 + (T1 - T2) * (0 - H2) / (H1 - H2);
    }
    return t;
}

double moonCulmination(string h1, string h2, string h3,string t1, string t2, string d2, string sd1)
{
    double H1, H2, H3, t = -1;
    stringstream sh1(h1);
    sh1 >> H1;
    stringstream sh2(h2);
    sh2 >> H2;
    stringstream sh3(h3);
    sh3 >> H3;
    if (H2 >= H1 && H2 >= H3 && d2.substr(6, 2) == sd1)
    {
        double T1, T2;
        stringstream st1(t1);
        st1 >> T1;
        stringstream st2(t2);
        st2 >> T2;
        t = T2 + ((H3 - H1)/(2 * (H1 - 2 * H2 + H3))) * (T2 - T1);
    }
    return t;
}
