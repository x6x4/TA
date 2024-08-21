#ifndef _H_THECONTEXT
#define _H_THECONTEXT

#include "AppClass_sm.h"
#include <string>
#include "../check_string.h"

class SmcCheckString;

#ifdef CRTP
class AppClass : public AppClassContext<AppClass>
#else
class AppClass
#endif
{
private:
#ifndef CRTP
    AppClassContext _fsm;
#endif

    bool isAcceptable;
        // If a string is acceptable, then this variable is set to YES;
        // NO, otherwise.

public:
    AppClass();
        // Default constructor.

    ~AppClass() {};
        // Destructor.

    bool CheckString(const std::string &str, SmcCheckString &smc);
        // Checks if the string is acceptable.

    inline void Acceptable()
    { isAcceptable = true; };

    inline void Unacceptable()
    { isAcceptable = false; };
        // State map actions.
};

#endif

class SmcCheckString : public CheckString {

AppClass _fsm; 

public:
    bool operator() (const std::string& str) override {
        AppClass thisContext;  //  field
        return thisContext.CheckString(str, *this);
    }
};
