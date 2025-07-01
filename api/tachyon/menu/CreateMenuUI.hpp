////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/ui/UIMenu.hpp>
namespace yq::tachyon {
    class TachyonMeta;
    
    class CreateMenuUI : public UIMenu {
        YQ_OBJECT_DECLARE(CreateMenuUI, UIMenu)
    public:

        static void init_info();

        CreateMenuUI(std::string_view kMenuName, const TachyonMeta&, UIFlags flags={});
        CreateMenuUI(std::string_view kMenuName, uint32_t, const TachyonMeta&, UIFlags flags={});
        CreateMenuUI(const CreateMenuUI&);
        
        ~CreateMenuUI();

        virtual CreateMenuUI* clone() const override;
        
        void content() override;

    private:
        struct Item;
        
        std::vector<Item>   m_items;
        const TachyonMeta&  m_base;
        uint32_t            m_param;
        bool                m_init  = false;
        
        void    build_menu();
    };
}
