#include <iostream>
#include <string>

using namespace std;

void func()
{
    double a;
    cout<<"1"<<a<<endl;
}

struct Sales_data {
    int a;
    double b;
    int c = 10;
};

int main()
{
    Sales_data data;
    cout<<data.a<<endl;
    cout<<data.b<<endl;
    cout<<data.c<<endl;
}