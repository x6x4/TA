#################################################################
# Macros.
#

SM_SOURCES=     AppClass.sm
SOURCES=        $(SM_SOURCES:.sm=_sm.cpp) \
                AppClass.cpp \
                ../main.cpp
HEADERS=        $(SM_SOURCES:.sm=_sm.h) \
                AppClass.h
OBJECTS=        ../build/$(SOURCES:.cpp=.o)
TARGET=         ../build/my_regex.out
MY_REGEX=       ./$(TARGET)

SMC_DIR=        ../../../smc

# Uncomment to turn off IOStreams for debug.
# NO_STREAMS=     -nostreams

# Uncomment to see state machine debug output.
# FSM_DEBUG=      -DFSM_DEBUG

# Uncomment to turn on debug message generation.
TRACE=          -g $(NO_STREAMS)

# Uncomment to turn off try/catch/rethrow generation.
# NO_CATCH=       -nocatch

# Uncomment to turn off exception throws.
# NO_EXCEPT=      -noex

# Uncomment to turn on CRTP code and -crtp SMC flag.
# CRTP=           -crtp
# CRTP_FLAG=      -DCRTP

SMC=            java -jar ${SMC_DIR}/bin/Smc.jar
SMC_FLAGS=      -c++ $(TRACE) $(NO_CATCH) $(NO_EXCEPT) $(CRTP)

CXX=            c++
CPPFLAGS=       -DSMC -Wall -Wextra -I${SMC_DIR}/lib/C++ $(FSM_DEBUG) $(CRTP_FLAG)

RM_F=           rm -f

#################################################################
# Rules.
#

%_sm.h %_sm.cpp : %.sm
		$(SMC) $(SMC_FLAGS) $<

%_sm.dot :      %.sm
		$(SMC) -graph -glevel 1 $<

%_sm.png :      %_sm.dot
		dot -T png -o $@ $<

%_sm.html :     %.sm
		$(SMC) -table $<


#  main section

all :           $(TARGET)

$(TARGET) :     $(HEADERS) $(SOURCES)
		$(CXX) $(CPPFLAGS) -o $@ $(SOURCES)

graph :         $(SM_SOURCES:%.sm=%_sm.dot)

png :           $(SM_SOURCES:%.sm=%_sm.png)

table :         $(SM_SOURCES:%.sm=%_sm.html)

clean :
		-$(RM_F) $(TARGET)
		-$(RM_F) $(OBJECTS)
		-$(RM_F) *_sm.h
		-$(RM_F) *_sm.cpp
		-$(RM_F) *_sm.dot
		-$(RM_F) *_sm.png
		-$(RM_F) *_sm.html
