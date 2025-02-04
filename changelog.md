# CHANGE LOG

## Upcoming

* Billboard Renders
* Fixed matrices in spatial/camera/orienation.  Starts pointing due (+X) with a right-handed coordinate system.
* Upgrade ImGui to v1.91.8
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

