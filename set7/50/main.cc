#include "main.ih"

int main(int argc, char **argv)
{
    if (argc != 3)
        return 1;
    
    const chrono::hours inputHours{stoll(argv[1])};
    const chrono::seconds inputSeconds{stoll(argv[2])};
    const chrono::minutes hourToMin = chrono::hours{inputHours};
    const chrono::minutes secToMin = 
        chrono::duration_cast<chrono::minutes>(
            chrono::seconds{inputSeconds}
        );
    
    cout << inputHours.count() << " hours is " 
         << hourToMin.count() << " minutes\n";
    cout << inputSeconds.count() << " seconds is " 
         << secToMin.count() << " minutes\n";
    

}