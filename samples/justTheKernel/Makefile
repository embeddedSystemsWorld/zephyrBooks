# select the BOARD type here:
# BOARD :=nucleo_l011k4
BOARD :=nucleo_l476rg
# BOARD :=nucleo_h743zi

all:
	@echo get the build process working...
	west build -p auto -b $(BOARD)  ./
	

ultraminimal:
	@echo get the build process working...
	west build -p auto -b $(BOARD)  ./  -- -DCONF_FILE="prj.conf ultraminimal.conf"


clean:
	rm ./build/ -rf
	
flash:
	west flash
