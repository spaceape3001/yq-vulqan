////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/ui/UIEditor.hpp>
#include <tachyon/ui/UIElementInfoWriter.hpp>   // this will change if elements derives....
#include <tachyon/api/Tachyon.hpp>
#include <tachyon/typedef/proxy.hpp>
#include <type_traits>

namespace yq::tachyon {

    struct UIEditorInfo::Field {
        std::string_view        label;
        FieldExecutor*          executor    = nullptr;
    };
    
    class UIEditorInfo::FieldExecutor {
    public:
        virtual void execute(UIEditor*edit) = 0;
    };

    template <SomeUIEditor C> 
    class UIEditorInfo::BoundFieldExecutor : public FieldExecutor {
    public:
        typedef void (C::*FN)();
    
        BoundFieldExecutor(FN fn) : m_function(fn) {}
    
        virtual void execute(UIEditor* edit)
        {
            (static_cast<C*>(edit)->*m_function)();
        }
        
    private:
        FN  m_function;
    };
    
    
    /*! \brief Writer of trigger information
    */
    template <typename C>
    class UIEditorInfo::Writer : public UIElements::MyInfo::Writer<C> {
    public:
    
        Writer(UIEditorInfo* pInfo) : UIElements::MyInfo::Writer<C>(pInfo), m_meta(pInfo)
        {
        }
        
        Writer(UIEditorInfo& pInfo) : Writer(&pInfo)
        {
        }
        
        template <class T>
        Writer&     edits()
        {
            if(m_meta && Meta::thread_safe_write()){
                if constexpr (std::is_base_of_v<Tachyon,T>){
                    m_meta -> m_editTachyons.push_back(&meta<T>());
                }
                if constexpr (std::is_base_of_v<Proxy,T>){
                    if constexpr (is_interface_v<T>){
                        m_meta -> m_editIProxies.push_back(&meta<T>());
                    }
                }
            }
            return *this;
        }
        
        Writer& field(std::string_view label, void (C::*fn)())
        {
            if(m_meta && Meta::thread_safe_write()){
                m_meta -> m_fields.push_back({ label, new BoundFieldExecutor<C>(fn) });
            }
            return *this;
        }

    private:
        UIEditorInfo* m_meta;
    };
}
