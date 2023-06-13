#include <iostream>

using namespace std;

constexpr int furlongs_to_yards{220};

int main(void)
{

    int furlongs, yards;

    cout << "Distance in furlongs: " <<endl;
    cin >> furlongs;
    yards = furlongs * furlongs_to_yards;

    cout << furlongs << " are" << yards << " yards" << endl;



    return 0;
}