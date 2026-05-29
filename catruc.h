#include<iostream>
#include<vector>
#include<string>
using namespace std;
struct catruc{
    int idCa; //1-buổi sáng 2-buổi chiều 3-buổi tối
    string tenCa; // Ca sáng(7-12) Ca chiều(12-17) Ca tối(17-22)
    string thu;// thu2,3,4,5,6,7,cn
    vector<string>dsnhanviendangky;
    vector<string>dsnhanvientrucchinhthuc;
};