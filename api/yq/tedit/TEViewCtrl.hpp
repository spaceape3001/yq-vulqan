////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Tachyon.hpp>
#include <yq/tachyon/typedef/camera.hpp>
#include <yq/tachyon/typedef/scene.hpp>
#include <yq/tachyon/typedef/viewer.hpp>
#include <yq/tachyon/typedef/widget.hpp>
#include <yq/vkqt/XWidget.hpp>
#include <QWidget>

namespace yq::tachyon {
    class TEViewCtrl : public XWidget<QWidget,Tachyon> {
        YQ_TACHYON_DECLARE(TEViewCtrl, Tachyon)
        Q_OBJECT
    public:
    
        // thinking dedicated QObject on the viewer's thread...
    
        TEViewCtrl(QWidget* parent=nullptr);
        ~TEViewCtrl();
        
    private:
        ViewerID    m_viewer;
        WidgetID    m_widget;
    };
}
