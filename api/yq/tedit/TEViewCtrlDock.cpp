////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tbb/spin_rw_mutex.h>
#include "TEViewCtrlDock.hpp"
#include <yq/gluon/app/DockMetaWriter.hpp>
#include <yq/tedit/TEViewCtrlBox.hpp>
#include <yq/tachyon/api/Tachyon.hxx>

YQ_OBJECT_IMPLEMENT(yq::tachyon::TEViewCtrlDock)

namespace yq::tachyon {
    TEViewCtrlDock::TEViewCtrlDock(QWidget* parent) : TEViewCtrlDock(TEViewCtrlBoxOptions(), parent)
    {
    }
    
    TEViewCtrlDock::TEViewCtrlDock(const TEViewCtrlBoxOptions& opts, QWidget* parent) : gluon::Dock(parent)
    {
        auto p = Tachyon::create<TEViewCtrlBox>();
        m_box   = p;
        setWidget(p);
        setWindowTitle(tr("Viewer Control"));
    }
    
    TEViewCtrlDock::~TEViewCtrlDock()
    {
    }

    void TEViewCtrlDock::closeEvent(QCloseEvent* evt)
    {
        if(m_box){
            m_box -> hide();
            m_box -> cmd_teardown();
            m_box   = nullptr;
        }
        
        Dock::closeEvent(evt);
    }
    
    void TEViewCtrlDock::init_meta()
    {
        auto w = writer<TEViewCtrlDock>();
        w.description("Tachyon Edit View Control Dock");
    }
}

#include "moc_TEViewCtrlDock.cpp"
