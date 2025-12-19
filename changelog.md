# CHANGE LOG

## UPCOMING
* Task pool (for non-thread related tasking)

## 2025-12.19

* Pipeline overhaul to accommodate meshes & lights & more
  - Buffers, textures now take in a configuration structure; this cleaned
    up the overload mess.  Means that all data activity must be moved into 
    this structure.  (Slight annoyance, not terrible)
```
    struct Pipeline::s_config, t_config, u_config, v_config {
        DataActivity    activity;
        uint32_t        binding;  //< default of MAX makes this auto-gen as before
        bool            external; //< default false
        uint32_t        location; //< location... use bindings where you can
        uint32_t        stages;   //< shader stage mask, default is all stages
    };
```
  - Data Activity tweak, STATIC means invariant data, COMMON means varying 
    data that may change, but isn't associated with a specific instance 
    of the object.
  - Data Activity... currently meaningless on rendered as every buffer/texture
    is checked every tick.
  - External buffers & textures, mark the SBO/Texture/UBO/VBO as being externally 
    managed.  An example being a common light buffer.  The appropriate VkBuffer
    or VkDescriptorSet must be passed in via the data map during rendering.
  - Bindings can now be explicitly stated
* Shaders now support the `#include` statement (this is a NICE google extension)
  - use `#include <>`
  - include path uses all data paths
  - first shader needs the `#version` and the rest is an error
*  Circular Spatial
  - Simple circular motion, some features TBD
*  User Spatial
  - Allows for simple user defined expressions for the parameters
*  Removed 3D's default "make spatial" helper, as this prevented a library
   reorganization, use the new "create_spatial" methods.
*  create_spatial() -- meant as a one stop helper to 1/2/3D objects to 
   create & add a new spatial to an object.
*  Draw calls can now be enumerated; default behavior is as before, if empty
   then the full range of the VBO/IBO is used.  (Note: the draw call vertex 
   used will depend on whether an IBO is defined for the pipeline.)
*  Heightfield object with Z-coloring
*  Cleaned up shaders
*  Consolidated the Color & Grad shapes into the single, using a draw mode to select.
*  ImGui has runtime enable/disable to it.  (Still need the ViewerCreateInfo to ask for ImGui; but the dynamic allows it to be reserved for things like debugging UIs)
*  ImGui upgrade to v1.92.5 (note, due to backend tweaks, we're incompatible with versions earlier than v1.92.0)
   - Caveat: Any uses of ImGui::Image will require the texture ID (though the method can't handle our TextureID directly, must do a ".id").

## 2025.12.05

* Updated pathing (this will affect INCLUDES) to be consistent with the rest of the Your Quill collection (include `<tachyon/...>` becomes `<yq/tachyon/...>`, so a find & replace will do the job.
* Lua support
* Save/load capability (though not full template/component support)
* GLTF loading; Mesh asset mostly there (will import and render, pipeline fixed to yellow)
* Additional UI support

## 2025.07.19

* When creating tachyons, include `<yq/tachyon/api/Tachyon.hxx>` to get the templated create code (it's been moved)
* Global font scaling set to 1.25; which makes it readable but with artifacts on my monitor.  Will need to make this a setting and do it properly (with a font load)
* Toolbar renamed to button bar (might be further renamed, but wanted it separate to "tools")
* Reorganization to the tachyon library file layout (sorry, getting cluttered again)
* All pipelines are preconfigured with dynamic viewport & scissors (this was chaos otherwise)
* Scene Editor is now a semi-functional application
* Asset overhaul (see toolbox) including a **RENAME** to Resource (so we can use the Asset name here.)

## 2025.04.11

* Basic ImGui UI framework
* Updated submodules
* Dynamic States filtering in pipeline creation (to make sure it's listed once)
* Dynamic viewports for pipelines
* Rocks is now in separate repo. 

## 2025.03.09

* Fixed bugs in closing/shutdown
* Vulkan Device spun off so it can support multiple windows on same GPU
* Better fullscreen support
* Started new "rocks" SDK example (note, use alt+F4 on all windows to quit)

## 2025.02.25

* Fixed bug in posts not binding to derived/base classes if they're marked abstract (which will always be the case with the current minimum header argument)
* Save/load of tachyons to XML format
* Tachyons can have asset & delegate properties

### Known issues
* Issue in closing not always closing the application.

## 2025.02.14

* Added Audio Thread
* Cleanup on commands, events, requests, & replies (consolidation, brought up to current standards, and removal of the old binders)
* Pipeline variation support
* SkyBox render object
* Add Gamepad Introspection to the Frame Inspector

### Known Issues
* Seems to be a retention issue on creating widgets sometimes vanishing.  Solution is to keep a ref-pointer, though this may stall shutdown/quit.
* Hello Triangle will exit with segmentation fault (debug-side only)

## 2025.02.08

* Added joystick/gamepad support -- two distinct classes
* Billboard Renders
* Fixed matrices in spatial/camera/orienation.  Starts pointing due (+X) with a right-handed coordinate system.
* Upgrade ImGui to v1.91.8 (so update your submodules!)
* Added some more push buffers for rendered objects

## 2025.02.02B

* Camera SDK example fixed (note, compatible with the toolbox tag 2025.02.02)

## 2025.02.02

* Switched over most code to using the frame, with snapshots, etc
* Multiple threads
* Frame Inspector
* Text label widget 
* Form widget
* Commands/events overhaul (there's a lot)
* Spatials/scene overhaul
* Spatial related interface/proxies/aspects
* NOTE... camera example is non-operational (disabled for this tagging, hoping to fix soon)

## 2024.12.26

* Keyword suffixes changed to be `_k` instead of `_t`

## 2024.12.25

* Viewer (including Visualizer & ImGui) is operating in a separate thread from inputs/GLFW
* Tachyon/Thread rearchitected to facilitate

## 2024.11.12

* ImGui events working, fully operational (with a bit of tear)
* Implemented a bunch of window/viewer commands via the GLFW manager
* Added concept of controller
* Simple controller in camera (up/down affects the pitch)

