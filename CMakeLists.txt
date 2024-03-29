cmake_minimum_required(VERSION 2.8)
project(cassetlib)

include_directories("${PROJECT_SOURCE_DIR}")

SET(USE_REAL ON CACHE BOOL ON)
SET(USE_SQLITE ON CACHE BOOL ON)
SET(USE_ZLIB ON CACHE BOOL ON)
SET(USE_TAR ON CACHE BOOL ON)
SET(LIB_PARTS locator.cpp archive.cpp)
SET(LINK_IN)
if(USE_REAL)
  LIST(APPEND LIB_PARTS real/rarchive.cpp real/rresource.cpp real/rfilesession.cpp)
  SET(USE_BOOSTFS true)
  add_definitions(-DUSE_REAL)
endif(USE_REAL)

if(USE_SQLITE)
  add_definitions(-DUSE_SQLITE)
  SET(USE_BOOSTFS true)
  LIST(APPEND LIB_PARTS sqlite/sarchive.cpp sqlite/sfilesession.cpp sqlite/sresource.cpp)
  LIST(APPEND LINK_IN sqlite3)
endif(USE_SQLITE)

if(USE_TAR)
  add_definitions(-DUSE_TAR)
  LIST(APPEND LIB_PARTS tar/tarchive.cpp tar/tresource.cpp tar/tfilesession.cpp)
endif(USE_TAR)

if(USE_ZLIB)
  add_subdirectory(zlib)
  LIST(APPEND LINK_IN zlib)
  add_definitions(-DUSE_ZLIB)
  LIST(APPEND LIB_PARTS tarc/tcarchive.cpp tarc/tcresource.cpp tarc/tcfilesession.cpp)
endif(USE_ZLIB)


add_library(cassetlib ${LIB_PARTS})
if(USE_BOOSTFS)
LIST(APPEND LINK_IN boost_filesystem)
endif(USE_BOOSTFS)
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

SET(BUILD_FOLDER_TO_SQLITE ON CACHE BOOL ON)
IF(BUILD_FOLDER_TO_SQLITE)
  add_subdirectory("folder2sqlite")
ENDIF(BUILD_FOLDER_TO_SQLITE)