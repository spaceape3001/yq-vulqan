////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/gluon/app/Dock.hpp>

namespace yq::tachyon {
    struct TEViewCtrlBoxOptions;
    class TEViewCtrlBox;
    
    class TEViewCtrlDock : public gluon::Dock {
        YQ_OBJECT_DECLARE(TEViewCtrlDock, gluon::Dock)
        Q_OBJECT
    public:
    
        TEViewCtrlDock(QWidget* parent=nullptr);
        TEViewCtrlDock(const TEViewCtrlBoxOptions& opts, QWidget* parent=nullptr);
        ~TEViewCtrlDock();
        
        static void init_meta();
        
        void closeEvent(QCloseEvent*);
        
    private:
        TEViewCtrlBox*  m_box   = nullptr;
        
    };
}
