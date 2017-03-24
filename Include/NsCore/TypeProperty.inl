////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
// [CR #488]
////////////////////////////////////////////////////////////////////////////////////////////////////


#include <NsCore/Ptr.h>
#include <NsCore/Error.h>
#include <NsCore/TypeOfForward.h>


namespace Noesis
{
namespace Core
{

////////////////////////////////////////////////////////////////////////////////////////////////////
inline NsSymbol TypeProperty::GetName() const
{
    return mName;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
inline const Type* TypeProperty::GetContentType() const
{
    return mType;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
template<class T>
inline typename Param<T>::Type TypeProperty::Get(const void* ptr) const
{
    NS_ASSERT(TypeOf<T>() == mType);
    return Get<T>(ptr, Int2Type<IsBestByCopy<T>::Result>());
}

////////////////////////////////////////////////////////////////////////////////////////////////////
template<class T>
inline void TypeProperty::Set(void* ptr, typename Param<T>::Type value) const
{
    NS_ASSERT(TypeOf<T>() == mType);
    InternalSet(ptr, &value);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
MetaData& TypeProperty::GetMetaData()
{
    return mMetaData;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
const MetaData& TypeProperty::GetMetaData() const
{
    return mMetaData;
}

template<class T>
typename Param<T>::Type TypeProperty::Get(const void* ptr, ByRef) const
{
    return *reinterpret_cast<const T*>(InternalGet(ptr));
}

template <class T>
typename Param<T>::Type TypeProperty::Get(const void* ptr, ByCopy) const
{
    T storage;
    InternalGet(ptr, &storage);
    return storage;
}

}
}
