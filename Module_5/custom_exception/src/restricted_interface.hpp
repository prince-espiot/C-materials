#ifndef AALTO_ELEC_CPP_RESTRICTED_PTR_CLASS_INTERFACE
#define AALTO_ELEC_CPP_RESTRICTED_PTR_CLASS_INTERFACE
#include "restricted_ptr.hpp"
#include <exception>
#include <iostream>

/* Add include guards here */

/* TODO:
 *
 * MakeRestricted: a template function that takes any type of
 * pointer as a parameter and returns a RestrictedPtr holding
 * that pointer with the use set to "RestrictedPtr instance".
 *
 * CopyRestricted: a template function that takes a reference to
 * a RestrictedPtr as a parameter and returns a copy of it. If
 * the copying fails, prints the error in the exception to
 * standard output with a newline appended and returns a
 * default constructed RestrictedPtr.
 *
 * operator<<: a template function that takes in a ostream
 * reference and a RestrictedPtr reference, prints the object
 * pointed to by the pointer to the stream using the << operator
 * and returns a reference to the stream. If the pointer is null,
 * prints the return value of GetError of the exception thrown by
 * GetData instead.
 */

template <typename T>
WeirdMemoryAllocator::RestrictedPtr<T> MakeRestricted(T *ptr)
{
    return WeirdMemoryAllocator::RestrictedPtr<T>(ptr, "RestrictedPtr instance");
}

template <typename T>
WeirdMemoryAllocator::RestrictedPtr<T> CopyRestricted(WeirdMemoryAllocator::RestrictedPtr<T> &ptr)
{
    try
    {
        auto copyPtr = ptr;
        return copyPtr;
    }
    catch (WeirdMemoryAllocator::RestrictedCopyException &e)
    {
        std::cout << e.GetError() << std::endl;
    }
    return WeirdMemoryAllocator::RestrictedPtr<T>();
}

template <typename T>
std::ostream &operator<<(std::ostream &os, WeirdMemoryAllocator::RestrictedPtr<T> &ptr)
{
    try
    {
        os << ptr.GetData() << std::endl;
        return os;
    }
    catch (WeirdMemoryAllocator::RestrictedNullException &e)
    {
        os << e.GetError() << std::endl;
        return os;
    }
    catch (WeirdMemoryAllocator::RestrictedCopyException &c)
    {
        os << c.GetError() << std::endl;
        return os;
    }
}

#endif