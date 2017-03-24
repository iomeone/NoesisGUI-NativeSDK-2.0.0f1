////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////


#include <NsCore/Memory.h>


////////////////////////////////////////////////////////////////////////////////////////////////////
// Default nstl allocator implementation
////////////////////////////////////////////////////////////////////////////////////////////////////

namespace eastl
{

////////////////////////////////////////////////////////////////////////////////////////////////////
inline DefaultAllocator::DefaultAllocator(const char*)
{
}

////////////////////////////////////////////////////////////////////////////////////////////////////
inline DefaultAllocator::DefaultAllocator(const DefaultAllocator&)
{
}

////////////////////////////////////////////////////////////////////////////////////////////////////
inline DefaultAllocator::DefaultAllocator(const DefaultAllocator&, const char*)
{
}

////////////////////////////////////////////////////////////////////////////////////////////////////
inline DefaultAllocator& DefaultAllocator::operator=(const DefaultAllocator&)
{
    return *this;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
inline const char* DefaultAllocator::get_name() const
{
    return "";
}

////////////////////////////////////////////////////////////////////////////////////////////////////
inline void DefaultAllocator::set_name(const char*)
{
}

////////////////////////////////////////////////////////////////////////////////////////////////////
inline void* DefaultAllocator::allocate(size_t n, int)
{
    return NsAlloc(n);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
inline void* DefaultAllocator::allocate(size_t n, size_t, size_t, int flags)
{
    return allocate(n, flags);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
inline void DefaultAllocator::deallocate(void* p, size_t)
{
    NsDealloc(p);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
inline bool operator==(const DefaultAllocator&, const DefaultAllocator&)
{
    return true; // All allocators are considered equal
}

////////////////////////////////////////////////////////////////////////////////////////////////////
inline bool operator!=(const DefaultAllocator&, const DefaultAllocator&)
{
    return false; // All allocators are considered equal
}

}