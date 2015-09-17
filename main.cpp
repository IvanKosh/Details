/* 
 * File:   main.cpp
 * Author: bat
 *
 * Created on 17 Сентябрь 2015 г., 19:04
 */

#include <iostream>
#include <fstream>

using namespace std;

short s, e;

int count_dot(string str) {
    s = str.size();
    e = 0;
    
    while(str[s] != 'X'){
        s--;
    }
    
    while(str[e] != 'Y') {
        e++;
    }
    
    return e-s-1;
}

int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string line;
    short i, j, min, temp;
    while (getline(stream, line)) {
        min = 10;
        j = line.size();
        for (i = line.size(); i--; ) {
            if (line[i] == ',') {
                temp = count_dot(line.substr(i+1, j-i));
                j=i-1;
                if(temp < min) min = temp;
            }
        }
        temp = count_dot(line.substr(i+1, j-i));
        if(temp < min) min = temp;
        cout << min<< '\n';
    }

    return 0;
}