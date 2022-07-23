################################################################################
##
##  YOUR QUILL
##
################################################################################


add_executable(glfw_joysticks glfw_joysticks.cpp)
target_link_libraries(glfw_joysticks yqvulqan)

add_executable(glfw_monitors glfw_monitors.cpp)
target_link_libraries(glfw_monitors yqvulqan)

add_executable(vk_devices vk_devices.cpp)
target_link_libraries(vk_devices yqvulqan)

add_executable(vk_extensions vk_extensions.cpp)
target_link_libraries(vk_extensions yqvulqan)

add_executable(vk_layers vk_layers.cpp)
target_link_libraries(vk_layers yqvulqan)


