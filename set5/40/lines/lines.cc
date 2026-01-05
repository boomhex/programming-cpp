#include "lines.ih"

Lines::Lines(istream &in)
{
    Safe::Vec block;
    string line;
    while (getline(in, line) && !line.empty())
        block.push_back(line);          // all lines in the block
    
    Safe::g_order.push_back(this);            
    // put the block together with the object in the map
    Safe::g_lines.emplace(this, move(block)); 
}