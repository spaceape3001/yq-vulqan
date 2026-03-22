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
    struct TEDocData;
    struct TEDocSnap;
    
    //! Document of stuff that lives on the frame, so needs a dedicated thread
    //! And it's Qt for qt based tools
    class TEDoc : public XThread<EditThread> {
        YQ_TACHYON_DATA(TEDocData)
        YQ_TACHYON_SNAP(TEDocSnap)
        YQ_TACHYON_DECLARE(TEDoc, EditThread)
        Q_OBJECT
    public:

        static void init_meta();
        
        TEDoc();
        ~TEDoc();

    protected:
        void snap(TEDocSnap&) const;
        
        Url     m_url;
    };
}
