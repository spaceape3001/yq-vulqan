################################################################################
##
##  YOUR QUILL
##
################################################################################

macro(tachyon_test name)
    add_executable(test_${name} ${name}.cpp)
    target_link_libraries(test_${name} PRIVATE tachyon BoostUT)
    add_test(NAME ${name} COMMAND test_${name} ${ARGN})
endmacro()

tachyon_test(memory)
tachyon_test(shader_load)
tachyon_test(task_engine)

