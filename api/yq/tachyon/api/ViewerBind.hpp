////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/ID.hpp>
#include <yq/tachyon/typedef/viewer.hpp>

namespace yq::tachyon {
    class Viewer;

    //! Utiltity to bind a viewer to the whatever...
    class ViewerBind {
    public:
        ViewerID    viewer() const { return m_viewer; }
        
    protected:
        ViewerBind(ViewerID v) : m_viewer(v) {}
        ViewerBind(Viewer* v);
        virtual ~ViewerBind() {}
        
        ViewerID const m_viewer;
    };
}
