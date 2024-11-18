////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/editor/Editor.hpp>
#include <yq/tachyon/widget/WidgetInfoWriter.hpp>

namespace yq::tachyon {
    /*! \brief Writer of editor information
    */
    template <typename C>
    class EditorInfo::Writer : public WidgetInfo::Writer<C> {
    public:
    
        Writer(EditorInfo* editorInfo) : WidgetInfo::Writer<C>(editorInfo), m_meta(editorInfo)
        {
        }
        
        Writer(EditorInfo& editorInfo) : Writer(&editorInfo)
        {
        }
        
        Writer&     menu_bar()
        {
            Meta::Writer::options({ Flag::MENU_BAR });
            return *this;
        }
        
    private:
        EditorInfo* m_meta;
        
    };
}
