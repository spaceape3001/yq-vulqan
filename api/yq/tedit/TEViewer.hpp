////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tbb/spin_rw_mutex.h>
#include <yq/core/Ref.hpp>
#include <yq/vkqt/XTachyon.hpp>
#include <yq/assetvk/widget/CompositeWidget.hpp>

namespace yq::tachyon {
    struct TEViewerData;
    struct TEViewerSnap;
    
    /*! \brief Manage a viewer (with widget)
    */
    class TEViewer : public XTachyon<QObject, CompositeWidget> {
        YQ_TACHYON_DATA(TEViewerData)
        YQ_TACHYON_SNAP(TEViewerSnap)
        YQ_WIDGET_DECLARE(TEViewer, CompositeWidget)
        Q_OBJECT
    public:

        TEViewer();
        ~TEViewer();
        
        static void init_meta();
        
    private:
        //TypedID         m_docId;
    };
}
