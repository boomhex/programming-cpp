#include "main.ih"
void printTimes(time_t time)
{
    tm local = *localtime(&time);
    tm utc = *gmtime(&time);
    cout << put_time(&local, "%c %Z") << "\n";
    cout << put_time(&utc, "%c %Z") << "\n";
}