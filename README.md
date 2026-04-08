# FALCON Arduino reader
Simple arduino Uno code to read acceleration from MPU6050 and react when a threshhold is reached

## Requirements
* arduino-cli
* python3
* Make
* jetbrains ide / vscode ide + wokwi account

## How to use
```bash
make setup
make build
```
Since I don't have an arduino, I needed to utilize an emulation framework. I came across [Wokwi](https://wokwi.com/), which solved just this problem. The problem was that I wanted to version control this project in git, which would be only possible if I wrote the code locally. I came across the [Wokwi CLion plugin](https://plugins.jetbrains.com/plugin/23826-wokwi-simulator).
What I did is :
* I set up an account on wokwi, 
* I got the license key, 
* I downloaded the plugin,
* I entered the license when asked,
* I opened the project in clion
* I ran the simulation from the plugin


https://github.com/user-attachments/assets/d16018e0-4134-43fa-842d-25afe09573a8
