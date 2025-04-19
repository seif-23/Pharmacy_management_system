cmake_minimum_required(VERSION 3.10)
project(PharmacyManagementSystem)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add include directory
include_directories(${PROJECT_SOURCE_DIR}/include)

# Add all source files
file(GLOB SOURCES 
    "src/*.cpp"
)

# Create executable
add_executable(pharmacy_system ${SOURCES})

# Copy data files to build directory
configure_file(${PROJECT_SOURCE_DIR}/data/medicines.txt ${PROJECT_BINARY_DIR}/medicines.txt COPYONLY)
configure_file(${PROJECT_SOURCE_DIR}/data/customer.txt ${PROJECT_BINARY_DIR}/customer.txt COPYONLY)
configure_file(${PROJECT_SOURCE_DIR}/data/Cashier.txt ${PROJECT_BINARY_DIR}/Cashier.txt COPYONLY)
configure_file(${PROJECT_SOURCE_DIR}/data/Pharmacist.txt ${PROJECT_BINARY_DIR}/Pharmacist.txt COPYONLY) 