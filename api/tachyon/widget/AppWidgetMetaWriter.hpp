////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/widget/AppWidget.hpp>
#include <tachyon/api/WidgetMetaWriter.hpp>

namespace yq::tachyon {
    /*! \brief Writer of editor information
    */
    template <typename C>
    class AppWidgetMeta::Writer : public WidgetMeta::Writer<C> {
    public:
    
        Writer(AppWidgetMeta* editorInfo) : WidgetMeta::Writer<C>(editorInfo), m_meta(editorInfo)
        {
        }
        
        Writer(AppWidgetMeta& editorInfo) : Writer(&editorInfo)
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
        AppWidgetMeta* m_meta;
    };
}
