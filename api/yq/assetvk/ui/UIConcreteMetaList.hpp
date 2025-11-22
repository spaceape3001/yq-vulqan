////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/assetvk/ui/UIMetaList.hpp>

namespace yq::tachyon {
    class UIConcreteMetaList : public UIMetaList {
        YQ_OBJECT_DECLARE(UIConcreteMetaList, UIMetaList)
    public:
    
        static void init_meta();
    
        UIConcreteMetaList(const ObjectMeta*, UIFlags={});
        UIConcreteMetaList(std::string_view, const ObjectMeta*, UIFlags={});
        UIConcreteMetaList(const UIConcreteMetaList&);
        ~UIConcreteMetaList();
        virtual UIConcreteMetaList* clone() const override;
        
    protected:
        virtual std::vector<const Meta*> get_metas() const;
    
    private:
        const ObjectMeta*  m_base  = nullptr;
    };
}
