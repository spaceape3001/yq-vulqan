////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "CreateMenuUI.hpp"
#include <tachyon/MyImGui.hpp>
#include <tachyon/parameters.hpp>
#include <tachyon/api/Payload.hpp>
#include <tachyon/api/Tachyon.hpp>
#include <tachyon/ui/UIElementMetaWriter.hpp>
#include <yq/text/match.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::CreateMenuUI)

namespace yq::tachyon {
    struct CreateMenuUI::Item {
        std::string             title;
        const TachyonMeta*      info    = nullptr;
    };

    void CreateMenuUI::init_meta()
    {
        auto w = writer<CreateMenuUI>();
        w.description("UI Menu for creating things");
    }

    CreateMenuUI::CreateMenuUI(std::string_view kMenuName, const TachyonMeta& base, UIFlags flags) : CreateMenuUI(kMenuName, kParam_CreateInfo, base, flags)
    {
    }
    
    CreateMenuUI::CreateMenuUI(std::string_view kMenuName, uint32_t param, const TachyonMeta&base, UIFlags flags) : 
        UIMenu(kMenuName, flags), m_base(base), m_param(param)
    {
    }
    
    CreateMenuUI::CreateMenuUI(const CreateMenuUI&cp) : 
        UIMenu(cp), m_items(cp.m_items), m_base(cp.m_base), m_param(cp.m_param), m_init(false)
    {
    }
    
    
    CreateMenuUI::~CreateMenuUI()
    {
    }

    CreateMenuUI* CreateMenuUI::clone() const 
    {
        return new CreateMenuUI(*this);
    }
    
    void CreateMenuUI::content() 
    {
        if(!m_init){
            build_menu();
            m_init  = true;
        }
        
        for(const Item& i : m_items){
            if(ImGui::MenuItem(i.title.c_str())){
                triggered(Payload().append(m_param, i.info));
            }
        }
    }

    void CreateMenuUI::build_menu()
    {
        for(const TachyonMeta* ti : TachyonMeta::all()){
            assert(ti);
            if(!ti) [[unlikely]]
                continue;
            if(ti->is_abstract())
                continue;
            if(!(ti->is_this(m_base) || ti->is_base(m_base)))
                continue;
            
            m_items.push_back({ .title=std::string(ti->stem()), .info=ti });
        }
        std::stable_sort(m_items.begin(), m_items.end(), [](const Item& a, const Item& b) -> bool {
            return is_less_igCase(a.title, b.title);
        });
    }
}
