#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int number, sum;
    vector<int> digits;

    cout << "Enter a whole number: ";
    cin >> number;

    while(number)
    {
        digits.push_back(number%10);
        number /= 10;
    }

    //C++11 range-based for loop
    for(auto i : digits)
        cout << i << " ";

    cout << "\nSum of the digits: ";
    cout << sum << endl;

}
