////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Editor.hpp>
#include <yq/tachyon/api/WidgetMetaWriter.hpp>

namespace yq::tachyon {
    /*! \brief Writer of editor information
    */
    template <typename C>
    class EditorMeta::Writer : public WidgetMeta::Writer<C> {
    public:
    
        Writer(EditorMeta* editorInfo) : WidgetMeta::Writer<C>(editorInfo), m_meta(editorInfo)
        {
        }
        
        Writer(EditorMeta& editorInfo) : Writer(&editorInfo)
        {
        }
        
        Writer&     menu_bar()
        {
            Meta::Writer::options({ Flag::MENU_BAR });
            return *this;
        }
        
    private:
        EditorMeta* m_meta;
        
    };
}
