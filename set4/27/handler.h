#ifndef INCLUDED_HANDLER_
#define INCLUDED_HANDLER_

#include "msgbase.h"

class Handler : private MsgBase
{
    using MsgBase::Msg;

public:
    Handler() = default;

    void handle(Msg msg);
};

#endif
