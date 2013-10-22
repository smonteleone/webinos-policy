CC=g++
CFLAGS=-c -g -Wall
LDFLAGS=-g
SOURCES=pm_test.cpp \
core/common.cpp \
core/policymanager/PolicySetDescriptor.cpp \
core/policymanager/AuthorizationsSet.cpp \
core/policymanager/Subject.cpp \
core/policymanager/ObligationsSet.cpp \
core/policymanager/IPolicyBaseDescriptor.cpp \
core/policymanager/ProvisionalAction.cpp \
core/policymanager/TriggersSet.cpp \
core/policymanager/PolicySet.cpp \
core/policymanager/PolicyDescriptor.cpp \
core/policymanager/Globals.cpp \
core/policymanager/Request.cpp \
core/policymanager/Rule.cpp \
core/policymanager/Policy.cpp \
core/policymanager/Condition.cpp \
core/policymanager/IPolicyBase.cpp \
core/policymanager/PolicyManager.cpp \
core/policymanager/ProvisionalActions.cpp \
core/policymanager/DataHandlingPreferences.cpp \
core/policymanager/Obligation.cpp \
../contrib/xmltools/tinystr.cpp \
../contrib/xmltools/tinyxmlerror.cpp \
../contrib/xmltools/tinyxml.cpp \
../contrib/xmltools/slre.cpp \
../contrib/xmltools/tinyxmlparser.cpp

OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=pm_test

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f pm_test.o pm_test
	rm -f core/*.o
	rm -f core/policymanager/*.o
	rm -f ../contrib/xmltools/*.o
