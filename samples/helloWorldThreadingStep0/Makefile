# change BOARD type here:
# BOARD :=nucleo_l476rg
BOARD :=nucleo_l011k4

all:
	@echo get the build process working...
	west build -p auto -b $(BOARD)  ./	

clean:
	-west build -t clean 
	rm ./build/ -rf
	
flash:
	west flash
