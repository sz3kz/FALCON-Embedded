.PHONY: setup build

setup:
	arduino-cli core update-index && arduino-cli core install arduino:avr

build:
	arduino-cli compile --fqbn arduino:avr:uno --build-path ./build MyProject
