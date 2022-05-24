cmake_minimum_required(VERSION 3.22)

# specify the C standard
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)

# set the project name and version
project(MyCMakeTest VERSION 1.0)

# add the binary tree to the search path for include files
# target_include_directories(MyCMakeTest PUBLIC
#                            "${PROJECT_BINARY_DIR}"
#                            )
# add the executable
add_executable(MyCMakeTest main.c)


enable_testing()

# test main
add_test(NAME MyCMakeTest COMMAND ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/MyCMakeTest "[{|")
set_tests_properties(MyCMakeTest
    PROPERTIES PASS_REGULAR_EXPRESSION "\\[\\{\\|" #由于在双引号里面正则表达式需要使用两次反斜杠转译特殊字符
    )

# add test print para2
add_executable(printPara2 tests/test_print_para2.c
                    src/print_para2.c
               )
add_test(NAME printPara2 COMMAND ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/printPara2 "para1" 2)
set_tests_properties(printPara2
    PROPERTIES PASS_REGULAR_EXPRESSION "args: \\[\\[para1 2\\]\\]"
    )