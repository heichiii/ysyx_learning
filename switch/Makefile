VERILATOR = verilator
VERILATOR_FLAGS = -Wall --cc --exe --build --trace
SOURCES = top.v sim_main.cpp


all: waveform.vcd

waveform.vcd: Vtop
	./obj_dir/Vtop

Vtop: $(SOURCES)
	$(VERILATOR) $(VERILATOR_FLAGS) $(SOURCES)

view:
	gtkwave waveform.vcd &

clean:
	rm -rf obj_dir waveform.vcd

.PHONY: all clean view
