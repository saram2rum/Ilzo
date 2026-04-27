# 컴파일러 및 최적화 옵션
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O3

# 폴더 및 파일 설정
SRC_DIR = src
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(SRCS:.cpp=.o)
TARGET = ilzo

# 빌드 규칙
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# 청소 규칙
clean:
	rm -f $(OBJS) $(TARGET)