#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

int main()

{
    string year {};
    int firstTwo{};
    int lastTwo{};
    int firstday {};
    int yearint {};
    cout << "Please enter a year: ";
    cin >> year;
    int daycounter {1};

    string months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "Dicember"};

    firstTwo = stoi(year.substr(0,2));
    lastTwo = stoi(year.substr(2,4));
    yearint = stoi(year);

    //calculate the first day of the year
    int tempfirstday = 1+ (13*11-1)/5 + lastTwo-1 + (lastTwo-1)/4 + firstTwo/4 -2*firstTwo;
    if (tempfirstday > 0){
        firstday = tempfirstday % 7;
    }
    else{
        firstday = 7 - (tempfirstday*-1 % 7);
    }
    
    cout << "First day of the year " << firstday << endl ;

    for (string month : months){
        cout << endl;
        cout << "--" << month << "  " << year <<" --" << endl;
        cout << setw(3) << "Mon" << "   " << "Tue" << "   "<< "Wed" << "   "<< "Thu" << "   "<< "Fri" << "   "<< "Sat" << "   "<< "Sun" << endl;
        if (month == "February"){
            if (yearint % 4 == 0){
                int day = 1;
                bool isdone = false;
                while (day < 30){
                    if (daycounter != firstday && !isdone){
                        cout << setw(3) << " " << "   ";
                        ++daycounter;
                        continue;
                    }
                    isdone = true;
                    if (daycounter < 7){
                        cout << setw(3) << day << "   ";
                        ++day;
                        ++daycounter;
                    }
                    else{
                        cout << setw(3) << day << "   " << endl;
                        daycounter = 1;
                        ++day;
                    }
                }
                firstday = daycounter;
                daycounter = 1;
            }
            else{
                int day = 1;
                bool isdone = false;
                while (day < 29){
                    if (daycounter != firstday && !isdone){
                        cout << setw(3) << " " << "   ";
                        ++daycounter;
                        continue;
                    }
                    isdone = true;
                    if (daycounter < 7){
                        cout << setw(3) << day << "   ";
                        ++day;
                        ++daycounter;
                    }
                    else{
                        cout << setw(3) << day << "   " << endl;
                        daycounter = 1;
                        ++day;
                    }
                }
                firstday = daycounter;
                daycounter = 1;
            }
        }
        else if (month == "April" || month == "June" || month == "September" || month == "November"){
            int day = 1;
            bool isdone = false;
            while (day < 31){
                if (daycounter != firstday && !isdone){
                    cout << setw(3) << " " << "   ";
                    ++daycounter;
                    continue;
                }
                isdone = true;
                if (daycounter < 7){
                    cout << setw(3) << day << "   ";
                    ++day;
                    ++daycounter;
                }
                else{
                    cout << setw(3) << day << "   " << endl;
                    daycounter = 1;
                    ++day;
                }
            }
            firstday = daycounter;
            daycounter = 1;
        }
        else{
            int day = 1;
            bool isdone = false;
            while (day < 32){
                if (daycounter != firstday && !isdone){
                    cout << setw(3) << " " << "   ";
                    ++daycounter;
                    continue;
                }
                isdone = true;
                if (daycounter < 7){
                    cout << setw(3) << day << "   ";
                    ++day;
                    ++daycounter;
                }
                else{
                    cout << setw(3) << day << "   " << endl;
                    daycounter = 1;
                    ++day;
                }
            }
            firstday = daycounter;
            daycounter = 1;
        }
    }
    return 0;
}