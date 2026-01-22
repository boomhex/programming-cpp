#include "tempdirhandler.ih"

TempDirHandler::~TempDirHandler()
{
    destroyPath();
}