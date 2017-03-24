////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////
namespace eastl
{

////////////////////////////////////////////////////////////////////////////////////////////////////
// queue
////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////
template<class T, typename Container>
inline queue<T, Container>::queue() :
    mContainer()
{
}

////////////////////////////////////////////////////////////////////////////////////////////////////
template<class T, typename Container>
inline queue<T, Container>::queue(const this_type& other) :
    mContainer(other.mContainer)
{
}

////////////////////////////////////////////////////////////////////////////////////////////////////
template<class T, typename Container>
inline typename queue<T, Container>::this_type& 
queue<T, Container>::operator=(const this_type& other)
{
    mContainer = other.mContainer;
    return *this;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
template<class T, typename Container>
inline void queue<T, Container>::push(const value_type& value)
{
    mContainer.push_back(value);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
template<class T, typename Container>
inline void queue<T, Container>::pop()
{
    mContainer.pop_front();
}

////////////////////////////////////////////////////////////////////////////////////////////////////
template<class T, typename Container>
inline typename queue<T, Container>::reference 
queue<T, Container>::front()
{
    return const_cast<reference>(static_cast<const this_type*>(this)->front());
}

////////////////////////////////////////////////////////////////////////////////////////////////////
template<class T, typename Container>
inline typename queue<T, Container>::const_reference 
queue<T, Container>::front() const
{
    return mContainer.front();
}

////////////////////////////////////////////////////////////////////////////////////////////////////
template<class T, typename Container>
inline typename queue<T, Container>::reference 
queue<T, Container>::back()
{
    return const_cast<reference>(static_cast<const this_type*>(this)->back());
}

////////////////////////////////////////////////////////////////////////////////////////////////////
template<class T, typename Container>
inline typename queue<T, Container>::const_reference 
queue<T, Container>::back() const
{
    return mContainer.back();
}

////////////////////////////////////////////////////////////////////////////////////////////////////
template<class T, typename Container>
inline bool queue<T, Container>::empty() const
{
    return mContainer.empty();
}

////////////////////////////////////////////////////////////////////////////////////////////////////
template<class T, typename Container>
inline typename queue<T, Container>::size_type 
queue<T, Container>::size() const
{
    return mContainer.size();
}

////////////////////////////////////////////////////////////////////////////////////////////////////
template<class T, typename Container>
inline typename queue<T, Container>::container_type& 
queue<T, Container>::get_container()
{
    return mContainer;
}

}

////////////////////////////////////////////////////////////////////////////////////////////////////
// NsQueue
////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////
template<class T, typename Container>
inline NsQueue<T, Container>::NsQueue() :
    BaseType()
{
}

////////////////////////////////////////////////////////////////////////////////////////////////////
template<class T, typename Container>
inline NsQueue<T, Container>::NsQueue(const ThisType& other) :
    BaseType(other)
{
}

////////////////////////////////////////////////////////////////////////////////////////////////////
template<class T, typename Container>
inline typename NsQueue<T, Container>::ThisType& 
NsQueue<T, Container>::operator=(const ThisType& other)
{
    return static_cast<ThisType&>(BaseType::operator=(other));
}
