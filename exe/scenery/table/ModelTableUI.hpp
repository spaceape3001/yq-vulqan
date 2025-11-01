////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/ui/UIElement.hpp>
#include <yq/tachyon/typedef/model.hpp>

namespace yq::tachyon{
    class Frame;
};

using namespace yq;
using namespace yq::tachyon;

class ModelTableUI : public UIElement {
    YQ_OBJECT_DECLARE(ModelTableUI, UIElement)
public:
    static void init_meta();
    
    ModelTableUI(UIFlags flags={});
    ModelTableUI(const ModelTableUI& cp);
    
    virtual ModelTableUI*   clone() const;
    const char*    title() const override;
    
    void    render() override;

    ModelID         selected() const { return m_selected; }
    void            set_selected(ModelID);

    void            tick() override;

private:

    struct Row;
    
    
    void            changed_select();

    ImTextureID         m_editing = nullptr;
    ModelID             m_selected;
    std::vector<Row>    m_rows;
};

