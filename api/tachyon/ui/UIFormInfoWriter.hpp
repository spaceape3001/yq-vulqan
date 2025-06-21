////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/ui/UIForm.hpp>
#include <tachyon/ui/UIElementInfoWriter.hpp>   // this will change if elements derives....
#include <tachyon/api/Tachyon.hpp>
#include <tachyon/typedef/proxy.hpp>
#include <type_traits>

namespace yq::tachyon {

    struct UIFormInfo::Field {
        std::string             label;
        FieldExecutor*          executor    = nullptr;
    };
    
    class UIFormInfo::FieldExecutor {
    public:
        virtual bool    iterable() const = 0;
        virtual void    execute(UIForm*edit) = 0;
    };

    template <SomeUIForm C> 
    class UIFormInfo::BoundFieldExecutor : public FieldExecutor {
    public:
        typedef void (C::*FN)();
    
        BoundFieldExecutor(FN fn) : m_function(fn) {}
    
        virtual bool    iterable() const { return false; }

        virtual void    execute(UIForm* edit)
        {
            (static_cast<C*>(edit)->*m_function)();
        }
        
    private:
        FN  m_function;
    };
    
    
    /*! \brief Writer of trigger information
    */
    template <typename C>
    class UIFormInfo::Writer : public UIElements::MyInfo::Writer<C> {
    public:
    
        Writer(UIFormInfo* pInfo) : UIElements::MyInfo::Writer<C>(pInfo), m_meta(pInfo)
        {
        }
        
        Writer(UIFormInfo& pInfo) : Writer(&pInfo)
        {
        }
        
        Writer& field(std::string_view label, void (C::*fn)())
        {
            if(m_meta && Meta::thread_safe_write()){
                m_meta -> m_fields.push_back({ std::string(label), new BoundFieldExecutor<C>(fn) });
            }
            return *this;
        }
        
        // TODO...
        Writer& field(std::string_view labelFormat, 
            uint64_t (C::*countFN)() const,
            void (C::*fn)(uint64_t)
        );
        

    private:
        UIFormInfo* m_meta;
    };
}
