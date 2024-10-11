################################################################################
##
##  YOUR QUILL
##
################################################################################

macro(vulqan_test name)
    add_executable(test_${name} ${name}.cpp)
    target_link_libraries(test_${name} PRIVATE yqvulqan BoostUT)
    add_test(NAME ${name} COMMAND test_${name} ${ARGN})
endmacro()

vulqan_test(shader_load)
vulqan_test(task_engine)

