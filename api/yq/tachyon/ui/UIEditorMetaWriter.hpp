////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/ui/UIEditor.hpp>
#include <yq/tachyon/ui/UIFormMetaWriter.hpp>   // this will change if elements derives....
#include <yq/tachyon/api/Tachyon.hpp>
#include <yq/tachyon/api/Post.hpp>
#include <yq/tachyon/typedef/proxy.hpp>
#include <type_traits>

namespace yq::tachyon {
    
    /*! \brief Writer of trigger information
    */
    template <typename C>
    class UIEditorMeta::Writer : public UIFormMeta::Writer<C> {
    public:
    
        Writer(UIEditorMeta* pInfo) : UIFormMeta::Writer<C>(pInfo), m_meta(pInfo)
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

        void    readonly(bool v=true)
        {
            if(m_meta && Meta::thread_safe_write()){
                m_meta -> m_readonly    = v;
            }
        }

    private:
        UIEditorMeta* m_meta;
    };
}
