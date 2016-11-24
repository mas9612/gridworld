CXX = c++
CXXFLAGS = -Wall -g -O0 -std=c++11 -stdlib=libc++
TARGET = reinforcementLearning
SRCS = main.cpp gridworld.cpp cell.cpp agent.cpp evaluator.cpp PenaltyAgent.cpp
OBJS := $(SRCS:.cpp=.o)

$(TARGET):	$(OBJS)
	$(CXX) -o $@ $(OBJS)

clean:
	rm -f $(TARGET) $(OBJS)
