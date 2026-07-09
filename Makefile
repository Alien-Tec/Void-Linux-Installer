# Executable name
TARGET = gnuslashlinux_installer

# Compiler and flags
CC     = gcc
CFLAGS = -Wall -Wextra -g `pkg-config --cflags gtk+-3.0` -Iinclude
LIBS   = `pkg-config --libs gtk+-3.0` -lpthread

# Header dependencies
HEADERS = include/gnuslashlinux_installer.h include/lang.h include/country_data.h

# -----------------------------------------------------------------------
# Shared source files (both builds)
# -----------------------------------------------------------------------
SRCS_COMMON = src/core/main.c \
              src/ui/ui.c \
              src/core/utils.c \
              src/core/installer.c \
              src/core/partition_utils.c \
              src/core/country_data.c \
              src/ui/ui_partition.c \
              src/ui/ui_callbacks.c \
              src/core/installer_steps.c \
              src/i18n/lang_manager.c \
              src/i18n/lang_en.c \
              src/i18n/lang_de.c

# -----------------------------------------------------------------------
# Exclusive Void Linux module
# -----------------------------------------------------------------------
SRCS_VOID = src/core/installer_steps_void.c

# Build normal: common + Void module
SRCS = $(SRCS_COMMON) $(SRCS_VOID)
OBJS = $(SRCS:.c=.o)

# Build universal: maintains subfolder structure inside build/
BUILDDIR_UNI = build/universal
OBJS_UNI     = $(patsubst src/%.c, $(BUILDDIR_UNI)/%.o, $(SRCS_COMMON))

# -----------------------------------------------------------------------
# Rules
# -----------------------------------------------------------------------
.PHONY: all universal clean run run-universal install uninstall

all: $(TARGET)

# --- Normal build (Void Linux) ---
$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET) $(LIBS)

# Compile .c -> .o (normal build)
%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

# --- Universal build (without xbps / Void Linux) ---
universal: $(TARGET)_universal

$(TARGET)_universal: $(OBJS_UNI)
	$(CC) $(OBJS_UNI) -o $(TARGET)_universal $(LIBS)
	@echo ""
	@echo ">>> Universal build ready: $(TARGET)_universal"
	@echo "    (No XBPS / Void Linux steps)"

# Rule for universal objects (automatically creates nested folders in build/)
$(BUILDDIR_UNI)/%.o: src/%.c $(HEADERS)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -DUNIVERSAL_BUILD -c $< -o $@

# --- Clean ---
clean:
	rm -f $(OBJS) $(TARGET) $(TARGET)_universal
	rm -rf build

# --- Execution ---
run: all
	sudo ./$(TARGET)

run-universal: universal
	sudo ./$(TARGET)_universal

# --- Installation ---
install: all
	@echo "Installiere Installer, Desktop-Datei und Logo..."
	install -Dm755 $(TARGET) /usr/local/bin/$(TARGET)
	install -Dm644 gnuslashlinux_installer.desktop /usr/share/applications/gnuslashlinux_installer.desktop
	install -Dm644 logo.png /usr/share/icons/hicolor/256x256/apps/gnuslashlinux_installer.png
	@echo "Installation erfolgreich abgeschlossen."

# --- Deinstallation ---
uninstall:
	@echo "Entferne installierte Dateien..."
	rm -f /usr/local/bin/$(TARGET)
	rm -f /usr/share/applications/gnuslashlinux_installer.desktop
	rm -f /usr/share/icons/hicolor/256x256/apps/gnuslashlinux_installer.png
	@echo "Deinstallation erfolgreich abgeschlossen."
