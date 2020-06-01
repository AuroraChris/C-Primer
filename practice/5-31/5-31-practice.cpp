#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int ia[3][4] = {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12}
    };
    for (auto p = ia; p != ia+3; ++p)
        for (auto q = *p; q != *p+4; ++q)
}