////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/widget/AppWidget.hpp>
#include <tachyon/api/WidgetInfoWriter.hpp>

namespace yq::tachyon {
    /*! \brief Writer of editor information
    */
    template <typename C>
    class AppWidgetInfo::Writer : public WidgetInfo::Writer<C> {
    public:
    
        Writer(AppWidgetInfo* editorInfo) : WidgetInfo::Writer<C>(editorInfo), m_meta(editorInfo)
        {
        }
        
        Writer(AppWidgetInfo& editorInfo) : Writer(&editorInfo)
        {
        }
        
        Writer&     menubar()
        {
            Meta::Writer::options({ Flag::MENU_BAR });
            return *this;
        }
        
        #if 0
        Writer&     menu(bar_k, std::string_view, std::initializer_list<std::string_view> action_list = {})
        {
            Meta::Writer::options({ Flag::MENU_BAR });
            //  TODO
            return *this;
        }
        
        Writer&     menu(popup_k, std::string_view, std::initializer_list<std::string_view> action_list = {})
        {
            Meta::Writer::options({ Flag::MENU_BAR });
            //  TODO
            return *this;
        }
        #endif

    private:
        AppWidgetInfo* m_meta;
    };
}
