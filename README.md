# Smart Energy Smart-Meter Pulse Counter & Analytics Agent

## Overview

A Linux-based smart energy meter simulation developed using C and C++.

The system simulates power-consumption pulses and processes them using a C++ analytics engine.

## Key Concepts

- C/C++ programming
- Linux development
- Pulse counting
- Energy aggregation
- Sliding-window analysis
- Peak detection
- Factory Design Pattern
- Linux device-driver concepts

## Architecture

Virtual Meter Driver
        ↓
   Pulse Counter
        ↓
 Energy Aggregator
        ↓
  Sliding Window
        ↓
  Peak Detector

Meter types are managed using the Factory Pattern:

MeterFactory
 ├── Residential
 ├── Commercial
 └── Industrial

## Technologies

- C
- C++17
- Linux / WSL2
- GCC / G++
- CMake
- Git / GitHub

## Run

Compile:

g++ -std=c++17 src/*.cpp -Iinclude -o smart_meter_linux

Run:

./smart_meter_linux

Example output:

Smart Energy Meter System
--------------------------
Meter ID: MTR001
Meter Type: Residential
Total Pulses: 10
Total Energy: 0.01 kWh
Window Size: 3
Window Average: 0.009 kWh
Status: HIGH CONSUMPTION

## Configuration

Meter settings are stored in:

config/meter_config.txt

Sample pulse data:

data/sample_pulses.txt

## Testing

Test programs are included for:

- Pulse Counter
- Energy Aggregator
- Sliding Window
- Peak Detector
- Meter Factory

## Author

Aditi Rath

B.Tech CSE, ITER, Siksha 'O' Anusandhan University