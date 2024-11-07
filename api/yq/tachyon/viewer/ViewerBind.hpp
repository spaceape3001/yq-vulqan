////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/typedef/viewer.hpp>
#include <yq/core/Ref.hpp>

namespace yq::tachyon {
    class Viewer;

    //! Utiltity to bind a viewer to the whatever...
    class ViewerBind {
    public:
        Viewer*    viewer() const { return m_viewer; }
        
    protected:
        ViewerBind(Viewer* v) : m_viewer(v) {}
        virtual ~ViewerBind() {}
        
        Viewer* const m_viewer;
    };
}
