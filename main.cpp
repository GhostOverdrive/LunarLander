#include <iostream>

using namespace std;

int steps;

void lunar_lander()
{
    float speed = 1000;
    int height = 30000, fuel = 9000, fuel_burn = 0;
    while (height > 0)
    {
        cout << "\n\nHeight: " << height << 'm' << " Speed: " << speed << "m/s" << " Fuel: " << fuel << "kg" << '\n';
        if (height <= 0)
        {
            break;
        }
        cout << "Enter the amount of fuel you want to use:\n";
        cin >> fuel_burn;
        while (fuel_burn > fuel)
        {
            cout << "Please, enter correct number: \n";
            cin >> fuel_burn;
        }
        steps++;
        fuel -= fuel_burn;
        speed -= fuel_burn * 0.407;
        int t = 10;
        while (t >= 0)
        {
            height -= speed;
            speed += 1.62;
            if (height <= 0)
            {
                break;
            }
            t--;
        }
    }
    if (speed > 10)
    {
        cout << "CRASHED\n";
    }
    else
    {
        cout << "\\\***LANDED***///\n";
    }
}

char retry()
{
    cout << "Want to try again?(y/Y-yes,n/N-no)\n";
    char again;
    cin >> again;
    while (again != 'Y' && again != 'y' && again != 'N' && again != 'n')
    {
        cout << "Want to try again?(y/Y-yes,n/N-no)\n";
        cin >> again;
    }
    return again;
}

int main()
{
    cout << "Hello!\n\nYou're playing Lunar Landing simulation game!\n\nHave fun and good luck!";
    lunar_lander();
    cout << "\nNumber of attempts:\n" << steps << "\n\n";
    char again = retry();
    while (again == 'Y' || again == 'y')
    {
        lunar_lander();
        again = retry();
    }
    cout << "Goodbye!!!";
    return 0;
}
