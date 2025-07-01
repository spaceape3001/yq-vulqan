////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/ui/UIEditor.hpp>
#include <tachyon/ui/UIFormInfoWriter.hpp>   // this will change if elements derives....
#include <tachyon/api/Tachyon.hpp>
#include <tachyon/typedef/proxy.hpp>
#include <type_traits>

namespace yq::tachyon {
    
    /*! \brief Writer of trigger information
    */
    template <typename C>
    class UIEditorMeta::Writer : public UIFormInfo::Writer<C> {
    public:
    
        Writer(UIEditorMeta* pInfo) : UIFormInfo::Writer<C>(pInfo), m_meta(pInfo)
        {
        }
        
        Writer(UIEditorMeta& pInfo) : Writer(&pInfo)
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

    private:
        UIEditorMeta* m_meta;
    };
}
