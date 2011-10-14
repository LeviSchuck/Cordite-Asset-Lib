project(cassetlib)

add_library(cassetlib file.cpp locator.cpp archive.cpp)

add_executable(cassetlibTest main.cpp)

target_link_libraries(cassetlibTest
cassetlib
)