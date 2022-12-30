SOURCES= main.cpp Smith.cpp MetalBar.cpp Marketplace.cpp BasicBakery.cpp StrongBakery.cpp Bread.cpp BakerKing.cpp Dough.cpp Oven.cpp TimeOfDay.cpp TownCrier.cpp innkeeper.cpp tavern.cpp bindMixer.cpp functionAssistant.cpp Bank/MiddelClassPerson.cpp Bank/RichPerson.cpp Cook.cpp Hunter.cpp
DIRECTORIES = Bank
OBJECTS=$(addprefix $(BUILD_DIR)/, $(SOURCES:.cpp=.o))
DEPS=$(addprefix $(BUILD_DIR)/, $(SOURCES:.cpp=.d))
EXE=prog.exe
CXXFLAGS=-I. -pthread -std=c++20

# Making for host if no argument is provided, ie, "ARCH=null"
ifndef ${ARCH}
CXX=g++
BUILD_DIR=build/host
BIN_DIR=bin/host
endif


all: $(BIN_DIR)/$(EXE)


# Rule that checks dependencies and if there are changes then create the directiory if it does not already exist, and then compiles the .cpp files into .o files
${BIN_DIR}/$(EXE): $(DEPS) $(OBJECTS)  # << Check the $(DEPS) new dependency
	mkdir	-p $(BIN_DIR) 
	$(CXX) $(CXXFLAGS) -o $@ $(OBJECTS)



# Rule that describes how a .d (dependency) file is created from a .cpp file
# Similar to the assigment that you just completed %.cpp -> %.o
${BUILD_DIR}/%.d: %.cpp
	mkdir -p $(BUILD_DIR)
	mkdir -p $(BUILD_DIR)/$(DIRECTORIES)
	$(CXX) -MT$(@:.d=.o) -MM $(CXXFLAGS) $^ > $@

${BUILD_DIR}/%.o: %.cpp
	mkdir -p $(BUILD_DIR)
	mkdir -p $(BUILD_DIR)/$(DIRECTORIES)
	$(CXX) -c $< -o $@ $(CXXFLAGS)

ifneq ($(MAKECMDGOALS),clean)
-include $(DEPS)
endif

#  if the clean command is used
clean:
	-rm -rf bin/
	-rm -rf build/
