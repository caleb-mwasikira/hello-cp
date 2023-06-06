#include <iostream>
#include <string>

using namespace std;

int main() {
    string str = "13";
    try
    {
        float number = stof(str);
        cout << number << endl;
    }
    catch(const exception& e)
    {
        cerr << e.what() << '\n';
        cout << "String provided is not an integer" << endl;
    }
    
    return 0;
}