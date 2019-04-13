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

    // Return pointer to OPER if o is a handle, otherwise return a nullptr
    inline LPOPER is_handle(OPER& o)
    {
        if (o.size() == 1 && o[0].xltype == xltypeNum) {
            handle<OPER> ho(o[0].val.num);
            if (ho)
                return ho.ptr();
        }

        return nullptr;
    }

    template<class O>
    inline O& take(O& o, int n)
    {
        if (abs(n) <= o.size()) {
            if (n > 0) {
                o.resize(n, o.columns());
            }
            else if (n < 0) {
                // copy_backward is more efficient, if it works
                std::reverse(o.begin(), o.end());
                o.resize(-n, o.columns());
                std::reverse(o.begin(), o.end());
            }
            else {
                o.resize(0,0);
            }
        }

        return o;
    }

    template<class O>
    inline O& drop(O& o, int n)
    {
        if (n < 0)
            return take(o, o.size() + n);
        else if (n > 0)
            return take(o, o.size() - n);

        return o;
    }

} // xll