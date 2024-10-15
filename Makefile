# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11 -I/opt/homebrew/include
LDFLAGS = -L/opt/homebrew/lib -lsfml-graphics -lsfml-window -lsfml-system

# Source files and object files
SRC = main.cpp student.cpp socialbattery.cpp building.cpp mathsbuilding.cpp Unibar.cpp interaction.cpp academicbuilding.cpp \
      HUD.cpp mainhub.cpp computersciencebuilding.cpp
OBJ = $(SRC:.cpp=.o)

# Executable name
EXEC = finalgame

# Test source files
TEST_SRC = TestSocialBattery.cpp TestGradeSystem.cpp TestLevelSystem.cpp TestMultiBuildingInteraction.cpp TestGameEnding.cpp
TEST_OBJ = $(TEST_SRC:.cpp=.o)

# Default target to build the program
all: $(EXEC)

# Link the object files to create the executable
$(EXEC): $(OBJ)
	$(CXX) $(OBJ) -o $(EXEC) $(LDFLAGS)

# Compile and run specific tests
testsocialbattery: TestSocialBattery.o
	$(CXX) TestSocialBattery.o $(OBJ) -o testsocialbattery $(LDFLAGS)

testgradesystem: TestGradeSystem.o
	$(CXX) TestGradeSystem.o $(OBJ) -o testgradesystem $(LDFLAGS)

testlevelsystem: TestLevelSystem.o
	$(CXX) TestLevelSystem.o $(OBJ) -o testlevelsystem $(LDFLAGS)

testmultibuildinginteraction: TestMultiBuildingInteraction.o
	$(CXX) TestMultiBuildingInteraction.o $(OBJ) -o testmultibuildinginteraction $(LDFLAGS)

testgameending: TestGameEnding.o
	$(CXX) TestGameEnding.o $(OBJ) -o testgameending $(LDFLAGS)

# Compile each source file into an object file
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean the build directory
clean:
	rm -f $(OBJ) $(TEST_OBJ) $(EXEC) testsocialbattery testgradesystem testlevelsystem testmultibuildinginteraction testgameending
