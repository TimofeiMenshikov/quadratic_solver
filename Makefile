CXXFLAGS = -Wshadow -Winit-self -Wredundant-decls -Wcast-align -Wundef -Wfloat-equal -Winline -Wunreachable-code -Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum -Wswitch-default -Weffc++ -Wmain -Wextra -Wall -g -pipe -fexceptions -Wcast-qual -Wconversion -Wctor-dtor-privacy -Wempty-body -Wformat-security -Wformat=2 -Wignored-qualifiers -Wlogical-op -Wno-missing-field-initializers -Wnon-virtual-dtor -Woverloaded-virtual -Wpointer-arith -Wsign-promo -Wstack-usage=8192 -Wstrict-aliasing -Wstrict-null-sentinel -Wtype-limits -Wwrite-strings -Werror=vla -D_DEBUG -D_EJUDGE_CLIENT_SIDE 
FILENAME = input.txt
CXX = g++

SOURCES = main.cpp test.cpp input.cpp solve_equation.cpp print.cpp reinit.cpp number_comparison.cpp
OBJECTS = main.o test.o input.o solve_equation.o print.o reinit.o number_comparison.o
#OBJECTS = $(SOURCES: %.cpp = %.o)
TEST = True
INPUT_DEBUG = False
COLOR_CMD = False # TODO write in readme

ifeq ($(TEST), True)   
	CXXFLAGS += -DTEST
endif

ifeq ($(INPUT_DEBUG), True)
	CXXFLAGS += -DINPUT_DEBUG
endif

ifeq ($(COLOR_CMD), True)
	CXXFLAGS += -COLOR_CMD
endif


.PHONY: all
all: main.exe	
	main.exe $(FILENAME)

main.exe: $(OBJECTS)
	$(CXX) $^ $(CXXFLAGS) -o $@ 

%.o: %.cpp
	@echo [CXX] [CXXFLAGS]  -c -o  $@ $< 
	@$(CXX) $(CXXFLAGS) -c -o  $@ $< 


.PHONY: clean_exe
clean_exe:
	@echo "all .exe files are cleaned"
	@echo ""
	
	rm -rf *.exe

.PHONY: clean_object_files
clean_object_files:
	@echo "all object files (.o) are cleaned"
	@echo ""
	
	rm -rf *.o 

.PHONY: clean
clean:
	rm -rf *.o
	rm -rf *.exe

.PHONY: create_documentation
create_docs: 
	doxygen Doxyfile
	@echo ""
	@echo "documentation is updated"
