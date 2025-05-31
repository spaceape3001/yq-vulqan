////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/ui/UIElement.hpp>

namespace yq::tachyon {
    class RenderedInfo;
}

using yq::tachyon::UIElement;
using yq::tachyon::UIFlags;
using yq::tachyon::RenderedInfo;

// UIShapes
class UIShapePalette : public UIElement {
    YQ_OBJECT_DECLARE(UIShapePalette, UIElement)
public:

    struct Row;

    static void init_info();

    std::vector<Row>    m_rows;
    const RenderedInfo* m_selected  = nullptr;

    UIShapePalette(UIFlags flags={});
    
    UIShapePalette(const UIShapePalette& cp);
    
    virtual UIShapePalette* clone() const override ;
    virtual const char* title() const override;
    virtual void render() override;
    void        define_rows();
};

