#ifndef AALTO_ELEC_CPP_RESTRICTED_PTR_CLASS
#define AALTO_ELEC_CPP_RESTRICTED_PTR_CLASS

#include "restricted_ref_counter.hpp"
#include <memory>
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
template <class T>
class RestrictedPtr
{
private:
    T* pointer_;
    int* refcount_;
    std::string somestring;
public:
    RestrictedPtr():pointer_(nullptr), refcount_(new int (1)),somestring("no car"){}

    RestrictedPtr(T* pointer):pointer_(pointer), refcount_(new int(1)) {
        *refcount_ = 1;
    } 

    RestrictedPtr(const RestrictedPtr & obj){   //copy
        this->pointer_ = obj.pointer_;
        this->refcount_ = obj.refcount_;
        this->somestring = obj.somestring;
        if((*refcount_)>=3){
            refcount_= new int ;
            pointer_ = nullptr;
            (*refcount_) = 1;
        }else{
            (*refcount_)++;
        }

    }

    RestrictedPtr& operator=(const RestrictedPtr &obj){
        
        if (this->GetRefCount()==1){
            delete this->pointer_;
            delete this->refcount_;
        }else if(this->GetRefCount()>1){
            (*refcount_)--;
        }
        this->pointer_ = obj.pointer_;
        this->refcount_ = obj.refcount_;
        this->somestring = obj.somestring;
        if((*refcount_) >=3){
            refcount_= new int ;
            pointer_ = nullptr;
            (*refcount_) = 1;
        }else{
            (*refcount_)++;
        }

    return *this;
    }
    ~RestrictedPtr(){
        if((*refcount_) >0){
            (*refcount_)--;
        }
        if((*refcount_)== 0){
            delete pointer_;
            delete refcount_;
        }
    }

    T& GetData (){
         return *pointer_;    
    }

    T* GetPointer (){
        return pointer_;
    }

    int GetRefCount(){
        return *refcount_;
    }
};


#endif