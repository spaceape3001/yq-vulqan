////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/ui/UIElement.hpp>
#include <yq/tachyon/typedef/controller.hpp>

namespace yq::tachyon{
    class Frame;
};

using namespace yq;
using namespace yq::tachyon;

class ControllerTableUI : public UIElement {
    YQ_OBJECT_DECLARE(ControllerTableUI, UIElement)
public:
    static void init_meta();
    
    ControllerTableUI(UIFlags flags={});
    ControllerTableUI(const ControllerTableUI& cp);
    
    virtual ControllerTableUI*   clone() const;
    const char*    title() const override;
    
    void    render() override;

    ControllerID         selected() const { return m_selected; }
    void            set_selected(ControllerID);

    void            tick() override;

private:

    struct Row;
    
    
    void            changed_select();

    TextureID           m_editing;
    ControllerID        m_selected;
    std::vector<Row>    m_rows;
};

