#include "storage.ih"

Storage::Storage()
:
    d_queue(),
    d_qmutex(),
    d_finished(false)
{}
