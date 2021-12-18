/* Add include guards here */

#ifndef AALTO_ELEC_CPP_RESTRICTED_PTR_EXCEPTION_CLASS
#define AALTO_ELEC_CPP_RESTRICTED_PTR_EXCEPTION_CLASS
#include <exception>
#include <string>

/* TODO: classes RestrictedPtrException, RestrictedCopyException
 * and RestrictedNullException
 * ------------
 * Description:
 * Exception classes used by the RestrictedPtr class.
 * PtrException is a abstract base class of the other two and inherits
 * std::exception.
 * CopyException signifies a copying error.
 * NullException signifies a nullptr error.
 * ------------
 * Functions:
 *
 * All of them should have a constructor taking a single const
 * reference to a string which is the use of the RestrictedPtr that
 * caused the exception.
 *
 * GetError: A function that takes no arguments and returns
 * a string description of the error (see "Other" section for details).
 * Calling GetError on RestrictedPtrException should return the
 * error description of the actual exception type (Null- or
 * CopyException).
 *
 * GetUse: takes no parameters and returns the string given as a
 * parameter to the constructor.
 * ------------
 * Other:
 * As always, any function that doesn't modify the object or allow
 * modifying the object's members from the outside should be const.
 *
 * Wrap everything inside the WeirdMemoryAllocator namespace.
 *
 * GetError format:
 * RestrictedCopyException:
<use>: Too many copies of RestrictedPtr!
 * RestrictedNullException:
<use>: nullptr exception!
 * where <use> is replaced by the string given in to the constructor.
*/

namespace WeirdMemoryAllocator
{
    class RestrictedPtrException : public std::exception
    {
    public:
        RestrictedPtrException(const std::string &exp_str) : str_(exp_str) {}
        virtual std::string GetError() const
        {
            if (str_ == "nullptr")
            {
                return (str_ + "");
            }
            else
            {
                return (str_ + "");
            }
        }
        std::string GetUse() const
        {
            return str_;
        }

    protected:
        std::string str_;
    };

    class RestrictedCopyException : public RestrictedPtrException
    {
    public:
        RestrictedCopyException(const std::string &copy_str) : RestrictedPtrException(copy_str) {}
        std::string GetError() const
        {
            return (str_ + ": Too many copies of RestrictedPtr!");
        }
    };

    class RestrictedNullException : public RestrictedPtrException
    {
    public:
        RestrictedNullException(const std::string &copy_str) : RestrictedPtrException(copy_str) {}
        std::string GetError() const
        {
            return (str_ + ": nullptr exception!");
        }
    };
}

#endif
