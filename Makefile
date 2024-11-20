#Modifierad manuellt för linux, potentiellt inte korrekt

# DIN KÄLLKOD-var dina egna .cpp-filer finns
SRC_DIR = src
# FILNAMNET för ditt program som skall byggas, och VAR
OBJ_NAME = play
BUILD_DIR = build/debug

# KOMPILATOR, g++-14/c++/c++-14/g++ beroende på installation
CC = g++ #eller g++-11 ? men jag har g++-17 på .vscode ..

# Valbara kompileringsflaggor(options)
COMPILER_FLAGS = -std=c++17 -Wall -O0 -g

# ALLA filer med filändelsen .cpp i foldern SRC_DIR
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)

# INKLUDERINGSFILER–var dina header-filer finns
#-Iinclude for this projects includes through Constants.h, -I/usr/include for regular C++ header files, and linuxbrew SDL2 for my SDL2 header files
INCLUDE_PATHS = -Iinclude -I/usr/include -I/home/linuxbrew/.linuxbrew/Cellar/sdl2/2.30.9/include

# BIBLIOTEKSFILER–kompilerad objektkod
LIBRARY_PATHS = -Llib \
                -L/home/linuxbrew/.linuxbrew/Cellar/sdl2/2.30.9/lib \
                -L/home/linuxbrew/.linuxbrew/Cellar/sdl2_image/2.8.2_2/lib \
                -L/home/linuxbrew/.linuxbrew/Cellar/sdl2_ttf/2.22.0/lib \
                -L/home/linuxbrew/.linuxbrew/Cellar/sdl2_mixer/2.8.0/lib \
                -L/home/linuxbrew/.linuxbrew/lib

# LÄNKNING - objekfiler som används vid länkning. Enklare program utan SDL behöver normalt inte några speciella länk-flaggor
LINKER_FLAGS = -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf -ljpeg

all:
	$(CC) $(COMPILER_FLAGS) $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(SRC_FILES) $(LINKER_FLAGS) -o $(BUILD_DIR)/$(OBJ_NAME)
