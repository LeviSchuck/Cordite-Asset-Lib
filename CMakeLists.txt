cmake_minimum_required(VERSION 2.8)
project(cassetlib)

include_directories("${PROJECT_SOURCE_DIR}")

SET(USE_REAL ON CACHE BOOL ON)
SET(USE_SQLITE ON CACHE BOOL ON)
SET(USE_ZLIB ON CACHE BOOL ON)
SET(LIB_PARTS locator.cpp archive.cpp)
SET(LINK_IN)
if(USE_REAL)
  LIST(APPEND LIB_PARTS real/rarchive.cpp real/rresource.cpp real/rfilesession.cpp)
  LIST(APPEND LINK_IN boost_filesystem)
  add_definitions(-DUSE_REAL)
endif(USE_REAL)

if(USE_SQLITE)
  
endif(USE_SQLITE)

if(USE_ZLIB)
  
endif(USE_ZLIB)

add_library(cassetlib ${LIB_PARTS})

if(LINK_IN)
target_link_libraries(cassetlib
${LINK_IN}
)
endif(LINK_IN)


SET(BUILD_TEST_APP ON CACHE BOOL ON)
IF(BUILD_TEST_APP)
add_executable(cassetlibTest main.cpp)

target_link_libraries(cassetlibTest
cassetlib
)
ENDIF(BUILD_TEST_APP)