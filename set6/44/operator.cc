#include "main.ih"

istream &operator>>(istream &in, Student &stu)
{
    string line;
    getline(in, line);
    if (line.empty())
        return in;

    auto popLast = [](string &text)
    {
        while (text.back() == ' ' || text.back() == '\t')
            text.pop_back();

        size_t lastSpacePos = text.find_last_of(" \t");
        if (lastSpacePos == string::npos)
        {
            string lastField = text;
            text.clear();
            return lastField;
        }

        string lastField = text.substr(lastSpacePos + 1);
        text.erase(lastSpacePos);
        return lastField;
    };
    string gradeText   = popLast(line);
    string numberText  = popLast(line);
    string lastName    = popLast(line);

    while (line.back() == ' ' || line.back() == '\t')
        line.pop_back();

    stu.d_grade    = stod(gradeText);
    stu.d_sNumber  = stoull(numberText);
    stu.d_lastName = lastName;

    while (line.front() == ' ' || line.front() == '\t')
        line.erase(0, 1);

    stu.d_name = line.empty() ? lastName : line + ' ' + lastName;

    return in;
}