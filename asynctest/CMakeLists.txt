cmake_minimum_required(VERSION 3.5)

project(AsyncRun)

aux_source_directory(. SOURCE_FILE)

add_executable(Demo ${SOURCE_FILE})

# should link the pthread lib
target_link_libraries(Demo pthread) 

enable_testing()

macro(test_macro arg result)
  add_test(test_${arg} Demo ${arg})
  set_tests_properties(test_${arg} PROPERTIES PASS_REGULAR_EXPRESSION ${result})
endmacro (test_macro)

## start test
test_macro(1 "1")
test_macro(2 "2")
test_macro(10 "[1-9]+")
