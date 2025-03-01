################################################################################
##
##  YOUR QUILL
##
################################################################################


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
