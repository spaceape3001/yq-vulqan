################################################################################
##
##  YOUR QUILL
##
################################################################################

find_package(Freetype)

add_executable(fontinfo fontinfo.cpp)
target_include_directories(fontinfo PRIVATE ${FREETYPE_INCLUDE_DIRS})
target_link_libraries(fontinfo PRIVATE ${FREETYPE_LIBRARIES} )

add_executable(glfw_joysticks glfw_joysticks.cpp)
target_link_libraries(glfw_joysticks ${GLFW3_LIBRARY} )

#add_executable(glfw_monitors glfw_monitors.cpp)
#target_link_libraries(glfw_monitors yq_tachyon)

add_executable(vk_devices vk_devices.cpp)
target_link_libraries(vk_devices yq_tachyon)

add_executable(vk_extensions vk_extensions.cpp)
target_link_libraries(vk_extensions yq_tachyon)

add_executable(vk_layers vk_layers.cpp)
target_link_libraries(vk_layers yq_tachyon)

add_executable(vk_queues vk_queues.cpp)
target_link_libraries(vk_queues yq_tachyon)

add_executable(resinfo resinfo.cpp)
target_link_libraries(resinfo yq_core yq_resource yq_tachyon yq_symbol)

add_executable(res res.cpp)
target_link_libraries(res yq_core yq_resource yq_tachyon yq_symbol)

add_executable(shexpand shexpand.cpp)
target_link_libraries(shexpand yq_tachyon)

add_executable(shcompile shcompile.cpp)
target_link_libraries(shcompile yq_tachyon)

add_executable(vx_structures vx_structures.cpp)
target_link_libraries(vx_structures yq_text yq_core yq_xml)
