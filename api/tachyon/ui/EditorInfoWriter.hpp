////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/ui/Editor.hpp>
#include <tachyon/ui/WidgetInfoWriter.hpp>

namespace yq {
    namespace tachyon {
        template <typename C>
        class EditorInfo::Writer : public WidgetInfo::Writer<C> {
        public:
        
            Writer(EditorInfo* editorInfo) : WidgetInfo::Writer<C>(editorInfo)
            {
            }
            
            Writer(EditorInfo& editorInfo) : Writer(&editorInfo)
            {
            }
        };
    }
}
