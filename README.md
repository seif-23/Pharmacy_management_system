# Pharmacy Management System

A comprehensive C++ application for managing a pharmacy, including inventory, employees, and customer transactions.

## Features

- Multi-user system with different roles (Owner, Pharmacist, Cashier)
- Inventory management
- Employee management
- Customer management
- Sales and transaction tracking
- Medicine information management

## Project Structure

```
pharmacy_management/
├── include/           # Header files
├── src/              # Source files
├── data/             # Data files
├── tests/            # Test files
├── docs/             # Documentation
├── CMakeLists.txt    # Build configuration
└── README.md         # This file
```

## Requirements

- C++17 compatible compiler
- CMake 3.10 or higher

## Build Instructions

1. Create a build directory:
```bash
mkdir build
cd build
```

2. Generate build files:
```bash
cmake ..
```

3. Build the project:
```bash
cmake --build .
```

## Usage

Run the executable:
```bash
./pharmacy_system
```

### Default Credentials

- Owner password: d1234
- For other roles (Pharmacist, Cashier), check the respective .txt files in the data directory

## License

This project is licensed under the MIT License - see the LICENSE file for details.
