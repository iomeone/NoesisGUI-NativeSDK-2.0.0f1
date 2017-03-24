////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include <NsCore/Memory.h>

////////////////////////////////////////////////////////////////////////////////////////////////////
// nstl malloc allocator implementation
////////////////////////////////////////////////////////////////////////////////////////////////////

namespace eastl
{

////////////////////////////////////////////////////////////////////////////////////////////////////
inline MallocAllocator::MallocAllocator(const char*)
{
}

////////////////////////////////////////////////////////////////////////////////////////////////////
inline MallocAllocator::MallocAllocator(const MallocAllocator&)
{
}

////////////////////////////////////////////////////////////////////////////////////////////////////
inline MallocAllocator::MallocAllocator(const MallocAllocator&, const char*)
{
}

////////////////////////////////////////////////////////////////////////////////////////////////////
inline MallocAllocator& MallocAllocator::operator=(const MallocAllocator&)
{
    return *this;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
inline const char* MallocAllocator::get_name() const
{
    return "";
}

////////////////////////////////////////////////////////////////////////////////////////////////////
inline void MallocAllocator::set_name(const char*)
{
}

////////////////////////////////////////////////////////////////////////////////////////////////////
inline void* MallocAllocator::allocate(size_t n, int flags)
{
    NS_UNUSED(flags);

    return Noesis::Core::AnsiMalloc(n);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
inline void* MallocAllocator::allocate(size_t n, size_t alignment, size_t offset, int flags)
{
    NS_UNUSED(alignment);
    NS_UNUSED(offset);

    return allocate(n, flags);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
inline void MallocAllocator::deallocate(void* p, size_t)
{
    Noesis::Core::AnsiFree(p);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
inline bool operator==(const MallocAllocator&, const MallocAllocator&)
{
    return true; // All allocators are considered equal
}

////////////////////////////////////////////////////////////////////////////////////////////////////
inline bool operator!=(const MallocAllocator&, const MallocAllocator&)
{
    return false; // All allocators are considered equal
}

}
