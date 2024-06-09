# compiler setting
COMPILER = g++ -v
CXXFLAGS = -g -MMD -Wall -Wextra -Winit-self -std=c++17

# library setting
ROS_WS  = ../../
LDFLAGS = -L/usr/local/lib
LDFLAGS+= -L$(ROS_WS)/install/lib
LIBS    = -lstdc++
LIBS   += -Wl,-rpath,$(ROS_WS)/install/lib -lservice_cli_lib

# include setting
INCLUDE = -I$(SRCROOT)/ -Isrc/
INCLUDE+= -I/opt/ros/${ROS_DISTRO}/include
INCLUDE+= -I$(ROS_WS)/install/include
EXCLUDE = .git%

# binary setting
# TARGET  = $(shell basename $$(pwd))
TARGET  = main
BINROOT = bin

# source setting
SRCROOT = exe_src
SRCS    = $(filter-out $(EXCLUDE) $(TEST_EXT), $(shell find $(SRCROOT) -name "*.cpp"))
SRCDIRS = $(dir $(SRCS))

# object setting
OBJROOT = objs
OBJDIRS = $(addprefix $(OBJROOT)/, $(patsubst $(SRCROOT)/%, %, $(SRCDIRS)))
OBJS    = $(addprefix $(OBJROOT)/, $(patsubst $(SRCROOT)/%.cpp, %.o, $(SRCS)))

# test setting
TEST_EXT= %_test.cpp
TESTLIBS = $(LIBS) -lpthread -lgtest -lgtest_main
TESTROOT = src
TESTSRCS = $(filter-out $(EXCLUDE) %main.cpp, $(shell find $(SRCROOT) -name "*.cpp"))
TESTOBJS = $(addprefix $(OBJROOT)/, $(patsubst $(TESTROOT)/%.cpp, %.o, $(TESTSRCS)))
TESTDIRS = $(dir $(TESTSRCS))

# dependency setting
DEPS = $(OBJS:.o=.d)

.PHONY: clean all analyze

all: $(OBJS) $(TARGET)
	@echo "make all"

test: $(TESTOBJS)
	@echo "build $< -> $@"
	@[ -d $(BINROOT) ] || mkdir -p $(BINROOT)
	$(COMPILER) -o $(BINROOT)/$@ $^ $(LDFLAGS) $(TESTLIBS)

$(TARGET): $(OBJS)
	@echo "build $< -> $@"
	@[ -d $(BINROOT) ] || mkdir -p $(BINROOT)
	$(COMPILER) -o $(BINROOT)/$@ $^ $(LDFLAGS) $(LIBS)

$(OBJROOT)/%.o: $(SRCROOT)/%.cpp
	@echo "build $< -> $@"
	@[ -d $@ ] || mkdir -p $(dir $@)
	$(COMPILER) $(CXXFLAGS) $(INCLUDE) -o $@ -c $<

analyze:
	cppcheck --std=c++17 --enable=all $(SRCROOT)

fix_lib:
	@ldconfig

clean:
	@rm -rf $(OBJROOT) $(BINROOT)

-include $(DEPS)
