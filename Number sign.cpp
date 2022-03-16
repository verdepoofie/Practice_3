#include <iostream>
#include <cmath>
using namespace std;

int sign(double x);
int main(){
    cout << "Number sign\nInput number:\n";
    double num;
    int s;
    cin >> num;
    s = sign(num);
    if(s == 1)
        cout << "\n> 0\n";
    if(s == -1)
        cout << "\n< 0\n";
    if(s == 0)
        cout << "\n= 0\n";
    return 0;
}
int sign(double x){
    if(x > 0)
        return 1;
    else if (x == 0)
        return 0;
    else
        return -1;
}