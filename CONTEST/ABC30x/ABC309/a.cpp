#include <iostream> 
using namespace std;

int main()
{
    int a,b;
    cin >> a >> b;

    if(a % 3 == 0)
    {
        cout << "No" << endl; 
        return 0;    
    }
    else if(((b - a) != 1))
    {
        cout << "No" << endl;
        return 0;
    }

    cout << "Yes" << endl;

    return 0;
}