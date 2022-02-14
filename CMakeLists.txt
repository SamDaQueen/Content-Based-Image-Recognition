cmake_minimum_required(VERSION 3.0)
project(project2)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE-DIRECTORIES})

link_libraries(${OpenCV_LIBS})

add_subdirectory(include)
add_executable(matching ./src/matching.cpp)
add_executable(extract ./src/extractFeatures.cpp)

target_link_libraries(matching CSV_UTIL)
target_link_libraries(matching Distance)
target_link_libraries(extract CSV_UTIL)
target_link_libraries(extract Features)

target_include_directories(matching PUBLIC
"${PROJECT_BINARY_DIR}"
"${PROJECT_SOURCE_DIR}/include")
target_include_directories(extract PUBLIC
"${PROJECT_BINARY_DIR}"
"${PROJECT_SOURCE_DIR}/include")

set(EXECUTABLE_OUTPUT_PATH "bin")



