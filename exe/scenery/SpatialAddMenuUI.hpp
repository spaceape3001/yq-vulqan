////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "SceneEditor.hpp"
#include <tachyon/ui/UIMenu.hpp>

class SceneEditor::SpatialAddMenuUI : public UIMenu {
    YQ_OBJECT_DECLARE(SpatialAddMenuUI, UIMenu)
public:

    static void init_info();

    SpatialAddMenuUI(std::string_view, UIFlags flags={});
    SpatialAddMenuUI(const SpatialAddMenuUI&);
    virtual ~SpatialAddMenuUI();
    
    virtual SpatialAddMenuUI* clone() const override;
    
    void content() override;

private:
    struct Item;
    std::vector<Item>  m_items;
    
    void    build_menu();
};
