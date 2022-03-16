#include <iostream>
#include <cmath>
using namespace std;

void menu();
void sub_menu();
double rectangle();
double triangle();
double circle();
int main(){
    cout << "Geometrical figures\n";
    menu();
    return 0;
}
void menu(){
    int input;
    cout << "Input 1 to calculate the area of the rectangle;\n";
    cout << "Input 2 to calculate the area of the triangle;\n";
    cout << "Input 3 to calculate the area of the circle;\n";
    cout << "Input 4 to exit.\n";
    cin >> input;
    switch (input){
        case 1: {
            cout << "You choose rectangle\n";
            double ar = rectangle();
            cout << "Area of the rectangle: " << ar << "\n";
            break;
        }
        case 2: {
            cout << "You choose triangle\n";
            double at = triangle();
            cout << "Area of the triangle: " << at << "\n";
            break;
        }
        case 3: {
            cout << "You choose circle\n";
            double ac = circle();
            cout << "Area of the circle: " << ac << "\n";
            break;
        }
        case 4: {
            cout << "\nExit";
            return;
        }
        default:{
            cout << "Invalid input";
            break;
        }
    }
    sub_menu();
    return;
}
void sub_menu(){
    cout << "Do you want to continue? (y/n)\n";
    char input;
    cin >> input;
    switch (input){
        case 'y': {
            cout << "Continue\n";
            menu();
            break;
        }
        case 'n': {
            cout << "Exit\n";
            return;
        }
        default: {
            cout << "Invalid input";
            break;
        }
    }
    return;
}
double rectangle(){
    double width, height;
    cout << "Input width and height of rectangle:\n";
    cin >> width >> height;
    return width * height;
}
double triangle(){
    double side1, side2, side3, p;
    cout << "Input sides of triangle:\n";
    cin >> side1 >> side2 >> side3;
    p = (side1 + side2 + side3)/2;
    return sqrt(p * (p - side1) * (p - side2) * (p - side3));
}
double circle(){
    double r;
    cout << "Input radius of circle:\n";
    cin >> r;
    return acos(-1.0) * pow(r, 2.0);
}