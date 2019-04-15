#include <iostream>
#include <cmath>
#include "../reader.hpp"
#include <sstream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

std::vector<std::string> split(const std::string &str, const char &delim = ',')
{
    std::stringstream ss(str);
    std::string token;
    std::vector<std::string> toks;
    while (std::getline(ss, token, delim))
    {
        toks.push_back(token);
    }
    return toks;
}
bool isOriginInside(int ax, int ay, int bx, int by, int cx, int cy)
{
    int ex = bx - ax;
    int ey = by -ay;
    int fx = cx -ax;
    int fy = cy -ay;
    int64_t k = fy*ex - fx*ey;
    int64_t un = ay*fx - ax*fy;
    int64_t vn = ax*ey - ay*ex;
    int sig = (k<0)?-1:1;
    // std::cout << "u: " << double(un) /k <<" v: " << double(vn) / k<<std::endl;
    return (sig*un >= 0 && sig *vn >= 0 && (sig*(un+vn) <= sig*k));

}
int main(int argc, char const *argv[])
{
    //std::cout << isOriginInside(-340,495,-153,-910,835,-947);
    //std::cout << isOriginInside(1,1,-1,1,0,-2);
    int64_t solution = 0;
    
    std::ifstream ifs("input.txt", std::ifstream::in);
    std::vector<std::string> lines = read_input(ifs);
    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    for (auto &l: lines){
        auto c = split(l);
        std::vector<int> cc;
        for (auto &cs: c)
            cc.push_back(std::stoi(cs));
        //std::cout <<cc[0]<<","<<cc[1]<<","<<cc[2]<<","<<cc[3]<<","<<cc[4]<<","<<cc[5]<<std::endl;
        if (isOriginInside(cc[0],cc[1],cc[2],cc[3],cc[4],cc[5]))
            solution++;
    }
    high_resolution_clock::time_point t2 = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>( t2 - t1 ).count();

    cout << duration<<endl;
    std::cout <<solution;
    return 0;
}
