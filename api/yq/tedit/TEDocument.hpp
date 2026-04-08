////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Thread.hpp>
#include <yq/tachyon/thread/EditThread.hpp>
#include <yq/vkqt/XThread.hpp>

namespace yq::tachyon {
    struct TEDocumentData;
    struct TEDocumentSnap;
    
    //! Document of stuff that lives on the frame, so needs a dedicated thread
    //! And it's Qt for qt based tools
    class TEDocument : public XThread<EditThread> {
        YQ_TACHYON_DATA(TEDocumentData)
        YQ_TACHYON_SNAP(TEDocumentSnap)
        YQ_TACHYON_DECLARE(TEDocument, EditThread)
        Q_OBJECT
    public:

        static void init_meta();
        
        TEDocument();
        ~TEDocument();

    protected:
        void snap(TEDocumentSnap&) const;
        
        Url     m_url;
    };
}
