#include <iostream>
using namespace std;

float Addition(float x, float y) {
    return x + y;
}

float Subtraction(float x, float y) {
    return x - y;
}

float Multiplication(float x, float y) {
    return x * y;
}

float Division(float x, float y) {
    if (y == 0) {
        cerr << "No se puede dividir entre 0" << endl;
        return 0; 
    }
    return x / y;
}
int main() {
    typedef float (*lpfnOperation)(float, float);
    lpfnOperation vpf[4] = { &::Addition, &::Subtraction,&::Multiplication, &::Division };
    float a, b, c; int opt;

    cin >> a >> b;

    cin >> opt;

    c = (*vpf[opt])(a, b);
    cout << c;
}