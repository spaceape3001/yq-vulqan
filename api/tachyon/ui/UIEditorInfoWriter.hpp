////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/ui/UIEditor.hpp>
#include <tachyon/ui/UIElementInfoWriter.hpp>   // this will change if elements derives....
#include <tachyon/api/Tachyon.hpp>

namespace yq::tachyon {
    
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
        
        template <SomeTachyon T>
        Writer&     edits()
        {
            if(m_meta && Meta::thread_safe_write()){
                m_meta -> m_edits.push_back(&meta<T>());
            }
            return *this;
        }

    private:
        UIEditorInfo* m_meta;
    };
}
