CXX := g++
CXXFLAGS := `pkg-config gtkmm-4.0 --cflags`
LDFLAGS := `pkg-config gtkmm-4.0 --libs`
OBJ_DIR := obj
OBJECTS := $(addprefix $(OBJ_DIR)/, main.o todo.o)

todo-menu : $(OBJECTS)
	$(CXX) $(OBJECTS) $(CXXFLAGS) -o $@ $(LDFLAGS)

$(OBJ_DIR)/%.o: %.cpp todo.h
	mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR) todo-menu