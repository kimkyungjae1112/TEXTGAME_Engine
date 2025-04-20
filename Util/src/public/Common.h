#ifndef __COMMON_H__
#define __COMMON_H__

#include <iostream>
#include <string>
#include <vector>
#include "Util.h"

#define CLASS_PTR(KlassName) \
class KlassName; \
using KlassName ## UPtr = KKJ::UniquePtr<KlassName>; \
using KlassName ## Ptr = KKJ::SharedPtr<KlassName>;


#endif // !__COMMON_H__