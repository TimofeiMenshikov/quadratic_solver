compile_flags = -Wshadow -Winit-self -Wredundant-decls -Wcast-align -Wundef -Wfloat-equal -Winline -Wunreachable-code -Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum -Wswitch-default -Weffc++ -Wmain -Wextra -Wall -g -pipe -fexceptions -Wcast-qual -Wconversion -Wctor-dtor-privacy -Wempty-body -Wformat-security -Wformat=2 -Wignored-qualifiers -Wlogical-op -Wno-missing-field-initializers -Wnon-virtual-dtor -Woverloaded-virtual -Wpointer-arith -Wsign-promo -Wstack-usage=8192 -Wstrict-aliasing -Wstrict-null-sentinel -Wtype-limits -Wwrite-strings -Werror=vla -D_DEBUG -D_EJUDGE_CLIENT_SIDE 
CC = 

test: main.exe
	main.exe


release:
	@echo "quadratic solver in release mode:"
	@echo ""
	@echo "make object files"
	@echo ""

	g++ -c main.cpp $(compile_flags) 
	
	@echo "make exe file"

	g++ main.o test.o -o main.exe

	@echo "run exe file"
	
	main.exe


main.exe:
	g++ main.o test.o -o main.exe 


main.o: 
	g++ -c main.cpp $(compile_flags) -DTEST 


test.o: 
	g++ -c test.cpp $(compile_flags) -DTEST

clean_exe:
	@echo "all .exe files are cleaned"
	@echo ""
	
	rm -rf *.exe


clean_object_files:
	@echo "all object files (.o) are cleaned"
	@echo ""
	
	rm -rf *.o 


print: 
	ifeq ($(CC), gcc)
		@echo "hello world"
	else
		@echo "world hello"

		@echo ""
	endif

