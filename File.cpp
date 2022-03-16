#include <iostream>
#include <fstream>
using namespace std;

void file();
int main(){
    file();
    return 0;
}
void file(){
    cout << "File\nInput new file path:\t";
    string path;
    double digit, sum = 0;
    cin >> path;
    ofstream f_write(path);
    cout << "\nInput numbers for the file:\n";
    for(int i = 0; i < 10; i++){
        cin >> digit;
        f_write << digit << " ";
    }
    f_write.close();
    ifstream f_read(path);
    if(f_read.is_open()) {
        for (int i = 0; i < 10; i++) {
            f_read >> digit;
            sum += digit;
        }
        cout << "sum: " << sum << "\n";
    } else
        cout << "Can't open file\n";
    f_read.close();
}