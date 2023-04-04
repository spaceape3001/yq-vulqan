////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/ui/Widget.hpp>
#include <meta/ObjectInfo.hpp>

namespace yq {
    namespace tachyon {
        template <typename C>
        class WidgetInfo::Writer : public ObjectInfo::Writer<C> {
        public:
            Writer(WidgetInfo* widgetInfo) : ObjectInfo::Writer<C>(widgetInfo)
            {
            }
            
            Writer(WidgetInfo& widgetInfo) : Writer(&widgetInfo)
            {
            }
        };
    }
}
