# CHANGE LOG

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

