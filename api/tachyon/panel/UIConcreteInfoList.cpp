////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "UIConcreteInfoList.hpp"
#include <tachyon/ui/UIElementMetaWriter.hpp>
#include <tachyon/api/Tachyon.hpp>

namespace yq::tachyon {
    void UIConcreteInfoList::init_info()
    {
        auto w = writer<UIConcreteInfoList>();
        w.description("UI List of Infos aren't abstract");
    }

    UIConcreteInfoList::UIConcreteInfoList(const TachyonMeta* info, UIFlags flags) : UIInfoList({}, flags), m_base(info)
    {
        assert(info);
    }
    
    UIConcreteInfoList::UIConcreteInfoList(std::string_view szTitle, const TachyonMeta* info, UIFlags flags) :
        UIInfoList(szTitle, flags), m_base(info)
    {
        assert(info);
    }
    
    UIConcreteInfoList::UIConcreteInfoList(const UIConcreteInfoList& cp) : UIInfoList(cp), m_base(cp.m_base)
    {
    }
    
    UIConcreteInfoList::~UIConcreteInfoList()
    {
    }
    
    UIConcreteInfoList* UIConcreteInfoList::clone() const 
    {
        return new UIConcreteInfoList(*this);
    }
    
    std::vector<const TachyonMeta*> UIConcreteInfoList::get_infos() const
    {
        std::vector<const TachyonMeta*> ret;
        for(const TachyonMeta* ti : TachyonMeta::all()){
            if(!ti)
                continue;
            if(ti->is_abstract())
                continue;
            if((ti->id() != m_base->id()) && !ti->is_base(*m_base))
                continue;
            ret.push_back(ti);
        }
        return ret;
    }
}

YQ_OBJECT_IMPLEMENT(yq::tachyon::UIConcreteInfoList)
