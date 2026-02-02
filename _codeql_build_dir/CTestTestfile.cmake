# CMake generated Testfile for 
# Source directory: /home/runner/work/as09/as09
# Build directory: /home/runner/work/as09/as09/_codeql_build_dir
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(assemble "/home/runner/work/as09/as09/_codeql_build_dir/as09" "-x" "/home/runner/work/as09/as09/test.asm")
set_tests_properties(assemble PROPERTIES  _BACKTRACE_TRIPLES "/home/runner/work/as09/as09/CMakeLists.txt;9;add_test;/home/runner/work/as09/as09/CMakeLists.txt;0;")
add_test(compare "/usr/local/bin/cmake" "-E" "compare_files" "a.out" "/home/runner/work/as09/as09/test.hex")
set_tests_properties(compare PROPERTIES  _BACKTRACE_TRIPLES "/home/runner/work/as09/as09/CMakeLists.txt;10;add_test;/home/runner/work/as09/as09/CMakeLists.txt;0;")
