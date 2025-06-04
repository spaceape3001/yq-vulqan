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


class SceneEditor::ScenesTableUI : public UIElement {
    YQ_OBJECT_DECLARE(ScenesTableUI, UIElement)
public:

    static void init_info();

    ScenesTableUI(UIFlags flags={});
    ScenesTableUI(const ScenesTableUI& cp);
    virtual ScenesTableUI*   clone() const ;
    virtual const char* title() const override;
    void    render() override;
   
    ImTextureID      m_invisible;
    ImTextureID      m_visible;
    ImTextureID      m_editing;
};

