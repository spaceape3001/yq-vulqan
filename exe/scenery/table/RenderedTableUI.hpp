////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/ui/UIElement.hpp>
#include <tachyon/typedef/rendered.hpp>

namespace yq::tachyon{
    class Frame;
};

using namespace yq;
using namespace yq::tachyon;

class RenderedTableUI : public UIElement {
    YQ_OBJECT_DECLARE(RenderedTableUI, UIElement)
public:
    static void init_meta();
    
    RenderedTableUI(UIFlags flags={});
    RenderedTableUI(const RenderedTableUI& cp);
    
    virtual RenderedTableUI*   clone() const;
    const char*    title() const override;
    
    void    render() override;

    RenderedID        selected() const { return m_selected; }
    void                set_selected(RenderedID);

    void            tick() override;

private:

    struct Row;
    
    
    void                changed_select();

    ImTextureID         m_editing = nullptr;
    RenderedID          m_selected;
    std::vector<Row>    m_rows;
};

