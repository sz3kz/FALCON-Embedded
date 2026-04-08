.PHONY: setup build

setup:
	arduino-cli core update-index && arduino-cli core install arduino:avr
	arduino-cli lib install 'Adafruit MPU6050' 'Adafruit Unified Sensor' 'Adafruit BusIO'

build:
	arduino-cli compile --fqbn arduino:avr:uno --build-path ./build MyProject
