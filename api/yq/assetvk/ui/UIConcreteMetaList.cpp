////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "UIConcreteMetaList.hpp"
#include <yq/tachyon/ui/UIElementMetaWriter.hpp>
#include <yq/tachyon/api/Tachyon.hpp>

namespace yq::tachyon {
    void UIConcreteMetaList::init_meta()
    {
        auto w = writer<UIConcreteMetaList>();
        w.description("UI List of Infos aren't abstract");
    }

    UIConcreteMetaList::UIConcreteMetaList(const ObjectMeta* info, UIFlags flags) : UIMetaList({}, flags), m_base(info)
    {
        assert(info);
    }
    
    UIConcreteMetaList::UIConcreteMetaList(std::string_view szTitle, const ObjectMeta* info, UIFlags flags) :
        UIMetaList(szTitle, flags), m_base(info)
    {
        assert(info);
    }
    
    UIConcreteMetaList::UIConcreteMetaList(const UIConcreteMetaList& cp) : UIMetaList(cp), m_base(cp.m_base)
    {
    }
    
    UIConcreteMetaList::~UIConcreteMetaList()
    {
    }
    
    UIConcreteMetaList* UIConcreteMetaList::clone() const 
    {
        return new UIConcreteMetaList(*this);
    }
    
    std::vector<const Meta*> UIConcreteMetaList::get_metas() const
    {
        std::vector<const Meta*> ret;
        if(m_base){
            for(const ObjectMeta* m : m_base->deriveds(ALL).all){
                if(!m)
                    continue;
                if(m->is_abstract())
                    continue;
                ret.push_back(m);
            }
        }
        return ret;
    }
}

YQ_OBJECT_IMPLEMENT(yq::tachyon::UIConcreteMetaList)
