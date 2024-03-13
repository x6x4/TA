#include "AppClass.h"
#include <cstddef>

AppClass::AppClass()
#ifdef CRTP
: isAcceptable(false)
#else
: _fsm(*this),
  isAcceptable(false)
#endif
{
#ifdef FSM_DEBUG
#ifdef CRTP
    setDebugFlag(true);
#else
    _fsm.setDebugFlag(true);
#endif
#endif
}

bool AppClass::CheckString(const std::string &theString)
{
#ifdef CRTP
    enterStartState();
    while(*theString != '\0')
    {
        switch(*theString)
        {
        case '0':
            Zero();
            break;

        case '1':
            One();
            break;

        default:
            Unknown();
            break;
        }
        ++theString;
    }

    // end of string has been reached - send the EOS transition.
    EOS();
#else
    _fsm.enterStartState();
    size_t i = 0;
    
    while(theString[i] != '\0')
    {
        switch(theString[i])
        {
        case '0':
            _fsm.Zero();
            break;

        case '1':
            _fsm.One();
            break;

        default:
            _fsm.Unknown();
            break;
        }
        ++i;
    }

    // end of string has been reached - send the EOS transition.
    _fsm.EOS();
#endif

    return isAcceptable;
}

bool check_string(const std::string& str) {
    AppClass thisContext;
    return thisContext.CheckString(str);
}

