////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/panel/UIInfoList.hpp>

namespace yq::tachyon {
    class UIConcreteInfoList : public UIInfoList {
        YQ_OBJECT_DECLARE(UIConcreteInfoList, UIInfoList)
    public:
    
        static void init_meta();
    
        UIConcreteInfoList(const TachyonMeta*, UIFlags={});
        UIConcreteInfoList(std::string_view, const TachyonMeta*, UIFlags={});
        UIConcreteInfoList(const UIConcreteInfoList&);
        ~UIConcreteInfoList();
        virtual UIConcreteInfoList* clone() const override;
        
    protected:
        virtual std::vector<const TachyonMeta*> get_infos() const;
    
    private:
        const TachyonMeta*  m_base  = nullptr;
    };
}
