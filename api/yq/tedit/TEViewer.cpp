////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "TEViewer.hpp"
#include "TEViewerData.hpp"
#include "TEViewerMetaWriter.hpp"

YQ_WIDGET_IMPLEMENT(yq::tachyon::TEViewer)

namespace yq::tachyon {
    void TEViewer::init_meta()
    {
        auto w = writer<TEViewer>();
        w.abstract();
        w.description("Tachyon Edit Viewer");
    }

    TEViewer::TEViewer()
    {
    }
    
    TEViewer::~TEViewer()
    {
    }
        
}

//#include "moc_TEViewer.cpp"
