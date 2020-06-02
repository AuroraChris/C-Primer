#include <iostream>
#include <string>
#include <cctype>

using namespace std;

void fuc()
{
    static int test = 0;
    ++test;
    cout<<test<<endl;
}

int main()
{
    fuc();
    fuc();
    fuc();
}