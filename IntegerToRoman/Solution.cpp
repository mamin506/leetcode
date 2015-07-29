#include <iostream>
#include <string>
#include <vector>
#include <cstdint>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        string s;  

        while (num > 0) {   
            if (num >= 1000) {s += "M"; num-=1000; continue;}
            if (num >= 900)  {s += "CM"; num-=900; continue;}
            if (num >= 500)  {s += "D"; num-=500; continue;}
            if (num >= 400)  {s += "CD"; num-=400; continue;}
            if (num >= 100)  {s += "C"; num-=100; continue;}
            if (num >= 90)   {s += "XC"; num-=90; continue;}
            if (num >= 50)   {s += "L"; num-=50; continue;}
            if (num >= 40)   {s += "XL"; num-=40; continue;}
            if (num >= 10)   {s += "X"; num-=10; continue;}
            if (num >= 9)    {s += "IX"; num-=9; continue;}
            if (num >= 5)    {s += "V"; num-=5; continue;}
            if (num >= 4)    {s += "IV"; num-=4; continue;}
            if (num == 3)    {s += "III"; num-=3; continue;}
            if (num == 2)    {s += "II"; num-=2; continue;}
            if (num == 1)    {s += "I"; num-=1; continue;}
        }   

        return s;
    }
};

int main(int argc, char *argv[]) {
    class Solution sol1;

    cout << sol1.intToRoman(39) << endl;

    return 0;
}

