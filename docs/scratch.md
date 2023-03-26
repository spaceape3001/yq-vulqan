
Refactoring the vulkan

Viewer couples the GLFW window & vulkan, provides a platform for one or more widgets (note a widget can take the WHOLE window)  A viewer will have 

Layout Helper for laying things out ... this will have the Qt vibe

Portal is the special widget, one that defines a drawing space

Widget is the one that draws... there's going to be generic 2D & 3D & 4D widgets that take 2D & 3D & 4D space & objects.


Context handles the vulkan side... 
