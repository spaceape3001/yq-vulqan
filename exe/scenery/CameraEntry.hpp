////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "SceneEditor.hpp"
#include <tachyon/typedef/controller.hpp>

struct SceneEditor::CameraEntry {
    CameraID            camera;
    const CameraInfo*   info        = nullptr;
    std::string         sid;        // ID for selectable
    std::string         stype;
    EFlags              flags;
};
