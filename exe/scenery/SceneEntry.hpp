////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "SceneEditor.hpp"

struct SceneEditor::SceneEntry {
    SceneID             scene;
    CameraID            camera;
    const SceneInfo*    info    = nullptr;
    std::string         sid;    // ID for selectable
    std::string         stype;
    std::string         visBtn, visBtn2, invisBtn, invisBtn2;
    std::string         filepath;
    RGBA4F              gamma  = { 0., 0., 0., -1.};
    EFlags              flags;
};

