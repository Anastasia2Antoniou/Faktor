# include <iostream>
# include <vector>
# include <sstream>
using namespace std;

int get_nbr_digits(int);

int main()
{
    stringstream ss;
    string str;

    int number = 789;
    int dgtNbr = get_nbr_digits(number);

    ss << number;
    ss >> str;

    vector<int>myVector(dgtNbr);
    for(int i=0;i<dgtNbr;i++)myVector[i] = str[i]-'0';

    for(int i=0;i<dgtNbr;i++)
        cout << myVector[i] << endl;
}

int get_nbr_digits(int nbr)
{
    // This function calculates the number of the digits in a number giving
    // which is in this case the parameter nbr
    // PS : If you know the number of the digits you can abandon this function ,
    //      if you get an input this is the right function for the job

    int increase = 0;

    for(int i=0,j=1;i<10;i++,j*=10)// I choose 10 because INT_MAX contain 10 digits
    {
        if((nbr/j)!=0)increase++;
        else break;
    }return increase;
}

