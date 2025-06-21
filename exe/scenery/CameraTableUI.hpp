////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "SceneEditor.hpp"
#include <tachyon/ui/UIElement.hpp>

using namespace yq;
using namespace yq::tachyon;

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

////////////////////////////////////////////////////////////////////////////////

class CamerasTableUI : public UIElement {   // soon to be replacement
    YQ_OBJECT_DECLARE(CamerasTableUI, UIElement)
public:
    static void init_info();
    
    CamerasTableUI(UIFlags flags={});
    CamerasTableUI(const CamerasTableUI& cp);
    
    virtual CamerasTableUI*   clone() const;
    const char*    title() const override;
    
    void    render() override;
    
    CameraID        selected() const { return m_selected; }

private:
    ImTextureID     m_editing = nullptr;
    CameraID        m_selected;
};


