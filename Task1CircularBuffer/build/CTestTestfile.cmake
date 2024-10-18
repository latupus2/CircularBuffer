# CMake generated Testfile for 
# Source directory: F:/VScode/NSU/OOP/task1Projects/Task1CircularBuffer
# Build directory: F:/VScode/NSU/OOP/task1Projects/Task1CircularBuffer/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
if(CTEST_CONFIGURATION_TYPE MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test(CircularBufferTest "F:/VScode/NSU/OOP/task1Projects/Task1CircularBuffer/build/Debug/CircularBufferTest.exe")
  set_tests_properties(CircularBufferTest PROPERTIES  _BACKTRACE_TRIPLES "F:/VScode/NSU/OOP/task1Projects/Task1CircularBuffer/CMakeLists.txt;18;add_test;F:/VScode/NSU/OOP/task1Projects/Task1CircularBuffer/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test(CircularBufferTest "F:/VScode/NSU/OOP/task1Projects/Task1CircularBuffer/build/Release/CircularBufferTest.exe")
  set_tests_properties(CircularBufferTest PROPERTIES  _BACKTRACE_TRIPLES "F:/VScode/NSU/OOP/task1Projects/Task1CircularBuffer/CMakeLists.txt;18;add_test;F:/VScode/NSU/OOP/task1Projects/Task1CircularBuffer/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
  add_test(CircularBufferTest "F:/VScode/NSU/OOP/task1Projects/Task1CircularBuffer/build/MinSizeRel/CircularBufferTest.exe")
  set_tests_properties(CircularBufferTest PROPERTIES  _BACKTRACE_TRIPLES "F:/VScode/NSU/OOP/task1Projects/Task1CircularBuffer/CMakeLists.txt;18;add_test;F:/VScode/NSU/OOP/task1Projects/Task1CircularBuffer/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
  add_test(CircularBufferTest "F:/VScode/NSU/OOP/task1Projects/Task1CircularBuffer/build/RelWithDebInfo/CircularBufferTest.exe")
  set_tests_properties(CircularBufferTest PROPERTIES  _BACKTRACE_TRIPLES "F:/VScode/NSU/OOP/task1Projects/Task1CircularBuffer/CMakeLists.txt;18;add_test;F:/VScode/NSU/OOP/task1Projects/Task1CircularBuffer/CMakeLists.txt;0;")
else()
  add_test(CircularBufferTest NOT_AVAILABLE)
endif()
