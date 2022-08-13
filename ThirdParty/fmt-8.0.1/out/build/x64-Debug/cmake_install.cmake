# Install script for directory: E:/Project/git/Stockpile/ThirdParty/fmt-8.0.1

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "E:/Project/git/Stockpile/ThirdParty/fmt-8.0.1/out/install/x64-Debug")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "E:/Project/git/Stockpile/ThirdParty/fmt-8.0.1/out/build/x64-Debug/fmtd.lib")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/fmt" TYPE FILE FILES
    "E:/Project/git/Stockpile/ThirdParty/fmt-8.0.1/out/build/x64-Debug/fmt-config.cmake"
    "E:/Project/git/Stockpile/ThirdParty/fmt-8.0.1/out/build/x64-Debug/fmt-config-version.cmake"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/fmt/fmt-targets.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/fmt/fmt-targets.cmake"
         "E:/Project/git/Stockpile/ThirdParty/fmt-8.0.1/out/build/x64-Debug/CMakeFiles/Export/lib/cmake/fmt/fmt-targets.cmake")
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/fmt/fmt-targets-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/fmt/fmt-targets.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/fmt" TYPE FILE FILES "E:/Project/git/Stockpile/ThirdParty/fmt-8.0.1/out/build/x64-Debug/CMakeFiles/Export/lib/cmake/fmt/fmt-targets.cmake")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/fmt" TYPE FILE FILES "E:/Project/git/Stockpile/ThirdParty/fmt-8.0.1/out/build/x64-Debug/CMakeFiles/Export/lib/cmake/fmt/fmt-targets-debug.cmake")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE FILE OPTIONAL FILES
    "E:/Project/git/Stockpile/ThirdParty/fmt-8.0.1/$<TARGET_PDB_FILE:fmt"
    "E:/Project/git/Stockpile/ThirdParty/fmt-8.0.1/fmt-header-only>"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/fmt" TYPE FILE FILES
    "E:/Project/git/Stockpile/ThirdParty/fmt-8.0.1/include/fmt/args.h"
    "E:/Project/git/Stockpile/ThirdParty/fmt-8.0.1/include/fmt/chrono.h"
    "E:/Project/git/Stockpile/ThirdParty/fmt-8.0.1/include/fmt/color.h"
    "E:/Project/git/Stockpile/ThirdParty/fmt-8.0.1/include/fmt/compile.h"
    "E:/Project/git/Stockpile/ThirdParty/fmt-8.0.1/include/fmt/core.h"
    "E:/Project/git/Stockpile/ThirdParty/fmt-8.0.1/include/fmt/format.h"
    "E:/Project/git/Stockpile/ThirdParty/fmt-8.0.1/include/fmt/format-inl.h"
    "E:/Project/git/Stockpile/ThirdParty/fmt-8.0.1/include/fmt/locale.h"
    "E:/Project/git/Stockpile/ThirdParty/fmt-8.0.1/include/fmt/os.h"
    "E:/Project/git/Stockpile/ThirdParty/fmt-8.0.1/include/fmt/ostream.h"
    "E:/Project/git/Stockpile/ThirdParty/fmt-8.0.1/include/fmt/printf.h"
    "E:/Project/git/Stockpile/ThirdParty/fmt-8.0.1/include/fmt/ranges.h"
    "E:/Project/git/Stockpile/ThirdParty/fmt-8.0.1/include/fmt/xchar.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "E:/Project/git/Stockpile/ThirdParty/fmt-8.0.1/out/build/x64-Debug/fmt.pc")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("E:/Project/git/Stockpile/ThirdParty/fmt-8.0.1/out/build/x64-Debug/doc/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("E:/Project/git/Stockpile/ThirdParty/fmt-8.0.1/out/build/x64-Debug/test/cmake_install.cmake")
endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "E:/Project/git/Stockpile/ThirdParty/fmt-8.0.1/out/build/x64-Debug/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
