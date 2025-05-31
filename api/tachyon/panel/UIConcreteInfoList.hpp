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
    
        static void init_info();
    
        UIConcreteInfoList(const TachyonInfo*, UIFlags={});
        UIConcreteInfoList(std::string_view, const TachyonInfo*, UIFlags={});
        UIConcreteInfoList(const UIConcreteInfoList&);
        ~UIConcreteInfoList();
        virtual UIConcreteInfoList* clone() const override;
        
    protected:
        virtual std::vector<const TachyonInfo*> get_infos() const;
    
    private:
        const TachyonInfo*  m_base  = nullptr;
    };
}
