////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/api/ID.hpp>
#include <yt/typedef/viewer.hpp>

namespace yq::tachyon {
    class Viewer;
    struct TypedID;

    //! Utiltity to bind a viewer to the whatever...
    class ViewerBind {
    public:
        ViewerID    viewer() const { return m_viewer; }
        
    protected:
        ViewerBind(ViewerID v) : m_viewer(v) {}
        ViewerBind(const Viewer* v);
        ViewerBind(TypedID);
        virtual ~ViewerBind() {}
        
        ViewerID const m_viewer;
    };
}
