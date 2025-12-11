#ifndef INCLUDED_PROCESSOR_
#define INCLUDED_PROCESSOR_

#include "msgbase.h"

class Processor : private MsgBase
{
    using MsgBase::Msg;

public:
    Processor() = default;

    void process(Msg msg);
};

#endif
