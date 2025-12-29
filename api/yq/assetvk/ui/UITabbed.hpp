////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/ui/UIPanel.hpp>

namespace yq::tachyon {
    class UITabbedWriter;
    
    class UITabbed : public UIPanel {
        YQ_OBJECT_DECLARE(UITabbed, UIPanel)
    public:
        using Writer = UITabbedWriter;
    
    
    /*
        Meant to do a tab widget... mostly there, but issues.
        Rather than stalling, putting this on the backburner
        for later (not a critical issue)
    */
    
    
        UITabbed(std::string_view, UIFlags flgs={});
        UITabbed(const UITabbed&);
        
        UITabbed* clone() const;
        
        //void    render();
        void    content();
        
        static void init_meta();
        
    private:
        int     m_selected   = -1;
    };
}
