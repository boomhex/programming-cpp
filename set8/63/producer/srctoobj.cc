#include "producer.ih"

string Producer::srcToObj(filesystem::path &src)    const
{   
    return (d_outDir / (src.stem().string() + ".o")).string();
}