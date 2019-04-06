// xllarray.h - Array and range functions
#pragma once
#include <algorithm>
#include "../xll12/xll/xll.h"

#ifndef CATEGORY
#define CATEGORY L"XLL"
#endif
#ifndef PREFIX
#define PREFIX CATEGORY L"."
#endif

namespace xll {

    inline LPOPER is_handle(OPER& o)
    {
        if (o.size() == 1 && o[0].xltype == xltypeNum) {
            handle<OPER> ho(o[0].val.num);
            if (ho)
                return ho.ptr();
        }

        return 0;
    }

    inline void take(OPER& o, int n)
    {
        if (abs(n) >= o.size())
            return;

        if (n > 0) {
            o.resize(n, o.columns());
        }
        else if (n < 0) {
            std::reverse(o.begin(), o.end());
            o.resize(-n, o.columns());
            std::reverse(o.begin(), o.end());
        }
        else {
            o.resize(0,0);
        }
    }

} // xll