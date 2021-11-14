all:sample.wasm
%.wasm: %.cpp
	em++  --no-entry $< -o $@ -s EXPORTED_FUNCTIONS='["_event","_bet","_action"]' -s ALLOW_MEMORY_GROWTH=1
