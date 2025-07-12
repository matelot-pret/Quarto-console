# Makefile pour le projet Quarto

# Variables
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g
SRCDIR = src
SOURCES = $(SRCDIR)/play.c $(SRCDIR)/fonctions.c
TARGET = play

# Règle par défaut
all: $(TARGET)

# Compilation du programme principal
$(TARGET): $(SOURCES)
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCES)

# Nettoyage des fichiers générés
clean:
	rm -f $(TARGET) $(TARGET).exe *.o

# Règle pour forcer la recompilation
rebuild: clean all

# Exécution du programme
run: $(TARGET)
	./$(TARGET)

# Aide
help:
	@echo "Commandes disponibles:"
	@echo "  make         - Compile le projet"
	@echo "  make clean   - Supprime les fichiers générés"
	@echo "  make rebuild - Recompile tout le projet"
	@echo "  make run     - Compile et exécute le programme"
	@echo "  make help    - Affiche cette aide"

.PHONY: all clean rebuild run help
