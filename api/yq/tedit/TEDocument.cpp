////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "TEDocument.hpp"
#include "TEDocumentData.hpp"
#include "TEDocumentMetaWriter.hpp"

YQ_TACHYON_IMPLEMENT(yq::tachyon::TEDocument)

namespace yq::tachyon {
    void TEDocument::init_meta()
    {
        auto w = writer<TEDocument>();
        w.description("Common Editor Document (& Thread)");
    }
        
    TEDocument::TEDocument()
    {
    }
    
    TEDocument::~TEDocument()
    {
    }

    void TEDocument::snap(TEDocumentSnap&sn) const
    {
        EditThread::snap(sn);
        sn.url  = m_url;
    }
}

//#include "moc_TEDocument.cpp"
