// xllrandom.cpp
#include "xllrandom.h"

using namespace xll;

#ifdef _DEBUG
AddIn doc_xllrandom(
    Documentation(LR"xyz(
Implementation of the C++ &lt;random&gt; library.
)xyz")
);
#endif

AddIn xai_random_default_engine(
    Function(XLL_WORD, L"?xll_random_default_engine", PREFIX L"DEFAULT.ENGINE")
    .Arg(XLL_WORD, L"engine", L"is a value from the RANDOM_ENGINE_* enumeration.")
    .FunctionHelp(L"Set the default random engine.")
    .Category(CATEGORY)
    .Documentation(L"doc")
);
WORD WINAPI xll_random_default_engine(WORD de)
{
#pragma XLLEXPORT
    return de;
}