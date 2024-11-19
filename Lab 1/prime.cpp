#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    bool has_first = false;
    int number, iterator, repeat_count = 0, i = 3;
    cin >> number;
    cout << number << " = ";
    int bound = (int) sqrt(number);
    while (number % 2 == 0)
    {
        repeat_count++;
        number /= 2;
    }
    if (repeat_count > 1) {
        cout << "2^" << repeat_count;
        has_first = true;
    } 
    else if (repeat_count == 1) {
        cout << "2";
        has_first = true;
    }
    repeat_count = 0; // reset repeat_count

    while (i < bound + 2)
    {
        if (number % i != 0)
        {       
            if (repeat_count == 1) {
                cout <<  (has_first ? " x " : "") << i;
                has_first = true;
            }
            else if (repeat_count > 1) {
                cout << (has_first ? " x " : "") << i << "^" << repeat_count;
                has_first = true;
            }
            i += 2;
            repeat_count = 0;
            continue;
        }
        number /= i;
        repeat_count++;
    }

    if (number != 1) {
        cout << (has_first ? " x " : "") << number;
    }

    return 0;
}