// xlldistribution.cpp - random distributions
#include "xllrandom.h"

using namespace xll;

#define ENUM_(a,b,c,d,e,f) RANDOM_DISTRIBUTION_ ## a,
enum Distribution { RANDOM_DISTRIBUTION(ENUM_) };

#define HASH_(x) L#x
#define UNPAREN(...) __VA_ARGS__
#define XLL_ENUM_(a,b,c,d,e,f) XLL_ENUM_DOC(RANDOM_DISTRIBUTION_##a, RANDOM_DISTRIBUTION_##a, CATEGORY, f L". Parameters: " HASH_(UNPAREN(e)), HASH_(f))
RANDOM_DISTRIBUTION(XLL_ENUM_)
