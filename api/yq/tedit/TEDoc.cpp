////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "TEDoc.hpp"
#include "TEDocData.hpp"
#include "TEDocMetaWriter.hpp"

YQ_TACHYON_IMPLEMENT(yq::tachyon::TEDoc)

namespace yq::tachyon {
    void TEDoc::init_meta()
    {
        auto w = writer<TEDoc>();
        w.description("Common Editor Document (& Thread)");
    }
        
    TEDoc::TEDoc()
    {
    }
    
    TEDoc::~TEDoc()
    {
    }

    void TEDoc::snap(TEDocSnap&sn) const
    {
        EditThread::snap(sn);
        sn.url  = m_url;
    }
}

#include "moc_TEDoc.cpp"
