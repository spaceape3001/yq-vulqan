////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/typedef/viewer.hpp>
#include <yq/tedit/xrs/MTachyon.hpp>

namespace yq::tachyon {
    class MViewer : public MTachyon {
        YQ_TACHYON_DECLARE(MViewer, MTachyon)
        Q_OBJECT
    public:
    
        MViewer(TypedID);
        ~MViewer();
        
        ViewerID        oid() const;
        TypedID         owindow() const;
        TypedID         owidget() const;
        TypedID         ofocus() const;
        
        const ViewerSnap*   osnap() const;
        
        static void init_meta();
    };
}
