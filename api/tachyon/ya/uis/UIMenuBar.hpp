////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/uis/UIElements.hpp>
#include <yt/keywords.hpp>

namespace yq::tachyon {

    /*! \brief It's a menu bar
    */
    class UIMenuBar : public UIElements {
    public:
    
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
