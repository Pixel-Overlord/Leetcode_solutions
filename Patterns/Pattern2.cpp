//1
//21
//321
//4321
//54321

#include <iostream>
using namespace std;

int main()
{
    for (int i=0; i<5; i++)
    {
        for (int j=i+1; j>=1 ; j--)
        {
            cout << j << "";
        }
        cout << endl;
    }
    return 0;
}