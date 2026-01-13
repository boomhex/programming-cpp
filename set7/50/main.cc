#include "main.ih"

int main(int argc, char **argv)
{
    if (argc != 3)
        return 1;
    
    size_t inputHours = atoi(argv[1]);
    size_t inputSeconds = atoi(argv[2]);
    chrono::minutes hourToMin = chrono::hours{inputHours};
    chrono::minutes secToMin = 
        chrono::duration_cast<chrono::minutes>(
            chrono::seconds{inputSeconds}
        );
    

    cout << inputHours << " hours is " 
         << hourToMin.count() << " minutes\n";
    cout << inputSeconds << " seconds is " 
         << secToMin.count() << " minutes\n";
    

}