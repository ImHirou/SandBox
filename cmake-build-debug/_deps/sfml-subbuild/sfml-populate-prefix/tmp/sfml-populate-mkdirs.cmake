# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "F:/MyCodes/SandBox/cmake-build-debug/_deps/sfml-src"
  "F:/MyCodes/SandBox/cmake-build-debug/_deps/sfml-build"
  "F:/MyCodes/SandBox/cmake-build-debug/_deps/sfml-subbuild/sfml-populate-prefix"
  "F:/MyCodes/SandBox/cmake-build-debug/_deps/sfml-subbuild/sfml-populate-prefix/tmp"
  "F:/MyCodes/SandBox/cmake-build-debug/_deps/sfml-subbuild/sfml-populate-prefix/src/sfml-populate-stamp"
  "F:/MyCodes/SandBox/cmake-build-debug/_deps/sfml-subbuild/sfml-populate-prefix/src"
  "F:/MyCodes/SandBox/cmake-build-debug/_deps/sfml-subbuild/sfml-populate-prefix/src/sfml-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "F:/MyCodes/SandBox/cmake-build-debug/_deps/sfml-subbuild/sfml-populate-prefix/src/sfml-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "F:/MyCodes/SandBox/cmake-build-debug/_deps/sfml-subbuild/sfml-populate-prefix/src/sfml-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
