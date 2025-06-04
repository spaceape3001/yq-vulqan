////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "SceneEditor.hpp"
#include <tachyon/ui/UIElement.hpp>

class SceneEditor::CameraTableUI : public UIElement {
    YQ_OBJECT_DECLARE(CameraTableUI, UIElement)
public:
    static void init_info();
    
    CameraTableUI(UIFlags flags={});
    CameraTableUI(const CameraTableUI& cp);
    
    virtual CameraTableUI*   clone() const;
    const char*    title() const override;
    
    void    render() override;

    ImTextureID      m_editing = nullptr;
};


