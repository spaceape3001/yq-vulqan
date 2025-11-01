////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/ui/UIElement.hpp>
#include <yq/tachyon/typedef/light.hpp>

namespace yq::tachyon{
    class Frame;
};

using namespace yq;
using namespace yq::tachyon;

class LightTableUI : public UIElement {
    YQ_OBJECT_DECLARE(LightTableUI, UIElement)
public:
    static void init_meta();
    
    LightTableUI(UIFlags flags={});
    LightTableUI(const LightTableUI& cp);
    
    virtual LightTableUI*   clone() const;
    const char*    title() const override;
    
    void    render() override;

    LightID         selected() const { return m_selected; }
    void            set_selected(LightID);

    void            tick() override;

private:

    struct Row;
    
    
    void            changed_select();

    ImTextureID         m_editing = nullptr;
    LightID             m_selected;
    std::vector<Row>    m_rows;
};

