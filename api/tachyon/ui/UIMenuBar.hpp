////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/ui/UIElements.hpp>
#include <yt/keywords.hpp>

namespace yq::tachyon {

    class UIMenuBarWriter;

    /*! \brief It's a menu bar
    */
    class UIMenuBar : public UIElements {
        YQ_OBJECT_DECLARE(UIMenuBar, UIElements)
    public:
    
        using Writer = UIMenuBarWriter;
    
        static void init_info();
    
        //! Constructs a regular menu bar
        UIMenuBar(UIFlags flags={});
        
        //! Constructs a "main" menu bar (for the main window)
        UIMenuBar(main_k, UIFlags flags={});
        
        //! Copy constructor
        UIMenuBar(const UIMenuBar&);
        virtual ~UIMenuBar();
        
    protected:
        virtual UIMenuBar*  clone() const override;
        virtual void        render() override;

    private:
        bool    m_isMain;
    };
}
