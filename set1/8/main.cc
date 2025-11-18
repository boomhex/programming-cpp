#include "strings/strings.h"
#include <iostream>

// Helper to print the content of a Strings object
void printStrings(std::string const &label, Strings const &s)
{
    std::cout << label << " (size = " << s.size() << "): ";
    for (size_t i = 0; i < s.size(); ++i)
        std::cout << '"' << s[i] << "\" ";
    std::cout << '\n';
}

int main()
{
    // 1. Build an initial Strings object using operator+=
    Strings s1;
    s1 += "one";
    s1 += "two";
    s1 += "three";

    printStrings("s1 (initial)", s1);

    // 2. Copy-construct: s2 shares data with s1 (ref count > 1)
    Strings s2 = s1;
    printStrings("s2 (copy of s1)", s2);

    // 3. Modify s2 via operator[] (non-const, Proxy) → should trigger COW
    std::cout << "\nModifying s2[1] = \"TWO\" (should NOT affect s1)...\n";
    s2[1] = "TWO";

    printStrings("s1 (after s2 modification, should be unchanged)", s1);
    printStrings("s2 (after modification)", s2);

    // 4. Another copy; modifying s3 should not affect s2 (another COW)
    Strings s3 = s2;
    std::cout << "\nModifying s3[0] = \"ONE\" (should NOT affect s2)...\n";
    s3[0] = "ONE";

    printStrings("s2 (after s3 modification, should be unchanged)", s2);
    printStrings("s3 (after modification)", s3);

    // 5. Reading via Proxy (conversion to const std::string&)
    std::cout << "\nReading elements via operator[] / Proxy:\n";
    std::cout << "s3[0] = " << s3[0] << '\n';
    std::cout << "s3[1] = " << s3[1] << '\n';
    std::cout << "s3[2] = " << s3[2] << '\n';

    // 6. Test chaining of operator+= (if you like)
    std::cout << "\nAppending more elements to s1 using operator+=...\n";
    s1 += std::string("four");
    s1 += std::string("five");
    printStrings("s1 (after extra appends)", s1);

    return 0;
}