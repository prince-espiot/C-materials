/* Add include guards here */

#ifndef AALTO_ELEC_CPP_RESTRICTED_PTR_CLASS
#define AALTO_ELEC_CPP_RESTRICTED_PTR_CLASS
#include <string>
#include <iostream>
#include "restricted_ptr_ex.hpp"
#include "restricted_ref_counter.hpp"
#include <utility>

/*
 * Copy your implementation from the last round here (or wait for
 * the example answer to come out and copy that) and wrap it inside a
 * WeirdMemoryAllocator namespace.
 *
 * Changes to the class:
 *
 * Add a new member string to store the use of the RestrictedPtr
 * and add a new string parameter, which is the use of the pointer, to the
 * constructor that originally only takes a pointer. Remember to modify
 * copying to also copy the use. If the pointer is automatically set to
 * a nullptr (i.e. not given in the constructor), the use is "nullptr".
 *
 * The copy constructor and assigment operators should throw a RestrictedCopyException
 * if the operations fail (as they in some cases should). When the copying
 * fails, only the exception should be thrown and no changes should be made
 * to the existing pointer.
 *
 * The GetData function should throw a RestrictedNullException with the use
 * of the RestrictedPtr given to it if the pointer is null.
 *
 * The class shouldn't leak any memory.
 */

/*
    Implement a class RestrictedPtr that holds a pointer of any type with at least the following members:
        - default constructor (takes no parameters)
        - constructor with a raw pointer parameter
        - copy constructor
        - destructor
        - copy assignment operator
        - function GetData that takes no parameters and returns the data the raw pointer refers to.
            The data returned should be such that modifying it modifies the data the pointer refers to.
        - function GetPointer that takes no parameters and returns the raw pointer
        - function GetRefCount that takes no parameters and returns an int with the reference count

    At any time the objects should keep track of how many references there are to a pointer
    and not allow more than 3 references. If the reference count drops to 0, the referenced
    pointer's memory should be released. If the reference count is already 3 when copying,
    the copier should set it's pointer to nullptr and reference count to 1.
    NOTE: GetPointer, GetData and GetRefCount are needed for the tests to run
*/
namespace WeirdMemoryAllocator
{
    template <class T>
    class RestrictedPtr
    {
    public:
        RestrictedPtr() : pointer_(nullptr), somestring_("nullptr"), refcount_(new int(1)), mystring_("") {}
        RestrictedPtr(T *ptr, std::string ptr_use) : pointer_(ptr), somestring_(ptr_use), refcount_(new int(1))
        {
            *refcount_ = 1;
        }

        RestrictedPtr(const RestrictedPtr &rest_obj)
        {
            this->pointer_ = rest_obj.pointer_;
            this->somestring_ = rest_obj.somestring_;
            this->refcount_ = rest_obj.refcount_;
            this->mystring_ = rest_obj.mystring_;

            if ((*refcount_) >= 3)
            {
                throw RestrictedCopyException(somestring_);
            }
            else
            {
                (*refcount_)++;
            }
        }

        friend void swap ( RestrictedPtr& first, RestrictedPtr& second){

            std::swap(first.pointer_ ,second.pointer_ );
            std::swap(first.somestring_ ,second.somestring_);
            std::swap(first.refcount_ ,second.refcount_);
            std::swap(first.mystring_ ,second.mystring_ );
        }

        RestrictedPtr &operator=(const RestrictedPtr &obj)
        {
            
            RestrictedPtr temp(obj);
            swap(*this, temp);
            return *this;
        }

        ~RestrictedPtr()
        {
            if ((*refcount_) > 0)
            {
                (*refcount_)--;
            }
            if ((*refcount_) == 0)
            {
                delete pointer_;
                delete refcount_;
            }
        }

        T &GetData()
        {
            if (pointer_ == nullptr)
            {
                throw RestrictedNullException(somestring_);
            }
            else
            {
                return *pointer_;
            }
        }

        T *GetPointer()
        {
            return pointer_;
        }
        int GetRefCount()
        {
            if (*refcount_ > 3)
            {
                throw RestrictedCopyException(somestring_);
            }
            else
            {
                return *refcount_;
            }
        }

    private:
        T *pointer_;
        std::string somestring_;
        int *refcount_;
        std::string mystring_;
    };
}

#endif
