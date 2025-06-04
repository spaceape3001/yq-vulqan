////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "SceneEditor.hpp"
#include <tachyon/ui/UIMenu.hpp>

class SceneEditor::RenderedAddMenuUI : public UIMenu {
    YQ_OBJECT_DECLARE(RenderedAddMenuUI, UIMenu)
public:

    static void init_info();

    RenderedAddMenuUI(std::string_view, UIFlags flags={});
    RenderedAddMenuUI(const RenderedAddMenuUI&);
    virtual ~RenderedAddMenuUI();
    
    virtual RenderedAddMenuUI* clone() const override;
    
    void content() override;

private:
    struct Item;
    std::vector<Item>  m_items;
    
    void    build_menu();
};
