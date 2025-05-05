SRC_DIR = src
BUILD_DIR = build
LIB_DIR = lib
INCLUDE_DIR = include

OUTPUT_BINARY = GtkUIMaker

clean:
	@echo "==== Cleaning Build Dir ===="
	rm -rf $(BUILD_DIR)
	@echo "==== Remaking Dirs ===="
	mkdir build

dev:
	@echo "==== Building Program ===="
	cd build && ./$(OUTPUT_BINARY)

fmt:
	@echo "==== Formatting Src ===="
	find $(SRC_DIR) -name '*.cpp' | xargs clang-format -i --verbose
	@echo "==== Formatting Include ===="
	find $(INCLUDE_DIR) -name '*.hpp' | xargs clang-format -i --verbose

PHONY: clean