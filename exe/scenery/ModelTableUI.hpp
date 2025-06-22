////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/ui/UIElement.hpp>
#include <tachyon/api/Model.hpp>

namespace yq::tachyon{
    class Frame;
};

using namespace yq;
using namespace yq::tachyon;

class ModelTableUI : public UIElement {
    YQ_OBJECT_DECLARE(ModelTableUI, UIElement)
public:
    static void init_info();
    
    ModelTableUI(UIFlags flags={});
    ModelTableUI(const ModelTableUI& cp);
    
    virtual ModelTableUI*   clone() const;
    const char*    title() const override;
    
    void    render() override;

    ModelID         selected() const { return m_selected; }
    void            set_selected(ModelID);

private:

    struct Row;
    
    
    void            changed_select();
    void            update_table(const Frame&);

    ImTextureID         m_editing = nullptr;
    ModelID             m_selected;
    std::vector<Row>    m_rows;
};

