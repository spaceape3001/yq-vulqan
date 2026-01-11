////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/vkqt/XWidget.hpp>
#include <yq/gluon/app/UndoMainWindow.hpp>

namespace yq::tachyon {

    /*! \brief  Main window
    
        Due to Qt'isms, the main window is restricted to the main thread (as is 
        all Qt-GUI stuff)
    */
    class YMain : public XWidget<gluon::UndoMainWindow, Tachyon> {
        YQ_TACHYON_DECLARE(YMain, Tachyon)
        Q_OBJECT
    public:
    
        YMain();
        ~YMain();
        
        virtual Execution   setup(const Context&) override;
        virtual Execution   teardown(const Context&) override;
        
        static void init_meta();
    protected:
        virtual void closing() override;
        
    private:
        bool    m_counted   = false;
    };
}
