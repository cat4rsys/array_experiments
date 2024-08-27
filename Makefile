CC := g++
CFLAGS := -Wshadow -Winit-self -Wredundant-decls -Wcast-align -Wundef -Wfloat-equal -Winline -Wunreachable-code -Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum -Wswitch-default -Weffc++ -Wmain -Wextra -Wall -g -pipe -fexceptions -Wcast-qual -Wconversion -Wctor-dtor-privacy -Wempty-body -Wformat-security -Wformat=2 -Wignored-qualifiers -Wlogical-op -Wno-missing-field-initializers -Wnon-virtual-dtor -Woverloaded-virtual -Wpointer-arith -Wsign-promo -Wstack-usage=8192 -Wstrict-aliasing -Wstrict-null-sentinel -Wtype-limits -Wwrite-strings -Werror=vla -D_DEBUG -D_EJUDGE_CLIENT_SIDE

SOURCES := source\print_array.cpp source\main.cpp source mode.cpp
OBJ := build\print_array.o build\main.o build\modes.o

BUILD := build

INCLUDES := include
OUTPUT := boot.exe

$(OUTPUT): $(OBJ)
	$(CC) $(OBJ) -o $@

build\print_array.o:
	@$(CC) $(CFLAGS) -I $(INCLUDES) -c source\print_array.cpp -o $@

build\modes.o:
	@$(CC) $(CFLAGS) -I $(INCLUDES) -c source\modes.cpp -o $@

build\main.o:
	@$(CC) $(CFLAGS) -I $(INCLUDES) -c source\main.cpp -o $@

clean:
	del build\*.o $(OUTPUT)
