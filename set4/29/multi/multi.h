#ifndef _INCLUDED_MULTI_
#define _INCLUDED_MULTI_

#include "../deriv1/deriv1.h"
#include "../deriv2/deriv2.h"

class Multi: public Deriv1, public Deriv2
{
    public:
        Multi();
};

#endif