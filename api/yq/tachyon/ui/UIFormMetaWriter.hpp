////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/ui/UIForm.hpp>
#include <yq/tachyon/ui/UIElementMetaWriter.hpp>   // this will change if elements derives....
#include <yq/tachyon/api/Tachyon.hpp>
#include <yq/tachyon/typedef/proxy.hpp>
#include <type_traits>

namespace yq::tachyon {

    struct UIFormMeta::Field {
        std::string             label;
        UIForm::CFlags          flags;
        FieldExecutor*          executor    = nullptr;
    };
    
    class UIFormMeta::FieldExecutor {
    public:
        virtual bool    iterable() const = 0;
        virtual void    execute(UIForm*edit) = 0;
    };

    template <SomeUIForm C> 
    class UIFormMeta::BoundFieldExecutor : public FieldExecutor {
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
    class UIFormMeta::Writer : public UIElements::MyMeta::Writer<C> {
    public:
    
        Writer(UIFormMeta* pInfo) : UIElements::MyMeta::Writer<C>(pInfo), m_meta(pInfo)
        {
        }
        
        Writer(UIFormMeta& pInfo) : Writer(&pInfo)
        {
        }
        
        Writer& field(std::string_view label, void (C::*fn)())
        {
            if(m_meta && Meta::thread_safe_write()){
                m_meta -> m_fields.push_back({ std::string(label), {}, new BoundFieldExecutor<C>(fn) });
            }
            return *this;
        }
        
        Writer& field(std::string_view label, UIForm::CFlags flags, void (C::*fn)())
        {
            if(m_meta && Meta::thread_safe_write()){
                m_meta -> m_fields.push_back({ std::string(label), flags, new BoundFieldExecutor<C>(fn) });
            }
            return *this;
        }

        // TODO...
        Writer& field(std::string_view labelFormat, 
            uint64_t (C::*countFN)() const,
            void (C::*fn)(uint64_t)
        );
        

    private:
        UIFormMeta* m_meta;
    };
}
