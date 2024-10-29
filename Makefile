CPP_FILES := $(wildcard *.cpp)
OBJ_FILES := $(addprefix obj/,$(notdir $(CPP_FILES:.cpp=.o)))
LD_FLAGS := ...
CC_FLAGS := -g
INCLUDES := 
LIB		= ./libFridgeduino.a


$(LIB):		$(OBJ_FILES)
		$(AR) $(ARFLAGS) obj/$(LIB) $(OBJ_FILES)

obj/%.o: %.cpp
	g++ -DX86_PLAT $(CC_FLAGS) $(INCLUDES) -c -o $@ $<
	
clean:
	rm obj/*
	

-include $(OBJFILES:.o=.d)
