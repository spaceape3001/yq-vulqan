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
        const ViewerPtr&    viewer() const;
        
    protected:
        ViewerBind(ViewerPtr v);
        virtual ~ViewerBind();
        
        const ViewerPtr m_viewer;
    };
}
