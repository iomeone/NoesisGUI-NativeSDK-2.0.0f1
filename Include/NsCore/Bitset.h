////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef __CORE_BITSET_H__
#define __CORE_BITSET_H__


#include <Noesis.h>
#include <EASTL/bitset.h>


////////////////////////////////////////////////////////////////////////////////////////////////////
// Namespace alias 
////////////////////////////////////////////////////////////////////////////////////////////////////
namespace Noesis
{
namespace Core
{
namespace nstl = eastl;
}
}

////////////////////////////////////////////////////////////////////////////////////////////////////
// NsBitset, same interface as std::bitset with the following improvements:
//  - find_first() and find_next()
////////////////////////////////////////////////////////////////////////////////////////////////////
template <size_t N>
class NsBitset : public Noesis::Core::nstl::bitset<N>
{
private:
    typedef Noesis::Core::nstl::bitset<N> BaseType;

public:
    NsBitset();
    NsBitset(uint32_t value);
};

////////////////////////////////////////////////////////////////////////////////////////////////////
#include "Bitset.inl"


#endif 
