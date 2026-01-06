#include "main.ih"

istream &operator>>(istream &in, Student &stu)
{
    string line;
    if (!getline(in, line))
        return in;

    istringstream iss(line);
    vector<string> tok;
    string word;
    while (iss >> word)         // add all words into a vector
        tok.push_back(word);

    stu.d_grade = stod(tok.back());     // get grade
    tok.pop_back();
    stu.d_sNumber = stoull(tok.back()); // get s number
    tok.pop_back();
    stu.d_lastName = tok.back();        // get last name
    tok.pop_back();

    ostringstream os;
    for (size_t idx = 0; idx != tok.size(); ++idx)
    {
        if (idx) os << ' '; 
        os << tok[idx];                 // get all first names
    }
    if (!tok.empty()) os << ' ';
    os << stu.d_lastName;               // add last name to first names
    stu.d_name = os.str();

    return in;
}