////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/typedef/as.hpp>

namespace yq::tachyon {
    class AsBind {
    public:
        const As&   as() const { return m_as; }
        
        bool    is_tachyon() const 
        { 
            return static_cast<bool>(std::get_if<AsTachyon>(&m_as)); 
        }
        
        bool    is_viewer() const 
        { 
            return static_cast<bool>(std::get_if<AsViewer>(&m_as)); 
        }
        
        bool    is_widget() const 
        { 
            return static_cast<bool>(std::get_if<AsWidget>(&m_as)); 
        }

        bool    is_window() const 
        { 
            return static_cast<bool>(std::get_if<AsWindow>(&m_as)); 
        }
        
        Tachyon*    tachyon() const
        {
            if(auto p = std::get_if<AsTachyon>(&m_as))
                return p -> tachyon;
            return nullptr;
        }

        Widget*    widget() const
        {
            if(auto p = std::get_if<AsWidget>(&m_as))
                return p -> widget;
            return nullptr;
        }

        Viewer*    viewer() const
        {
            if(auto p = std::get_if<AsViewer>(&m_as))
                return p -> viewer;
            if(auto p = std::get_if<AsWindow>(&m_as))
                return p -> viewer;
            return nullptr;
        }

        AsBind(window_t, Viewer* v) : m_as(AsWindow(v)) {}
        AsBind(viewer_t, Viewer* v) : m_as(AsViewer(v)) {}
        AsBind(Tachyon* t) : m_as(AsTachyon(t)) {}
        AsBind(Widget* w) : m_as(AsWidget(w)) {}
        AsBind(As a) : m_as(a) {}
        
        virtual ~AsBind(){}
    
    private:
        As const    m_as;
    };
}
