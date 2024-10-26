CXX := g++
CXXFLAGS := `pkg-config gtkmm-4.0 --cflags`
LDFLAGS := `pkg-config gtkmm-4.0 --libs`
OBJ_DIR := obj
OBJECTS := $(addprefix $(OBJ_DIR)/, main.o todo.o todo_title.o file_view.o  dialog.o)
H_DIR := headers
HEADERS := $(addprefix $(H_DIR)/, todo.h todo_title.h file_view.h dialog.h)

todo-menu : $(OBJECTS)
	$(CXX) $(OBJECTS) $(CXXFLAGS) -o $@ $(LDFLAGS)

$(OBJ_DIR)/%.o: src/%.cpp $(HEADERS)
	mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR) todo-menu