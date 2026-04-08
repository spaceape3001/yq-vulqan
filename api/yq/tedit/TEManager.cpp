////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "TEManager.hpp"

#include <yq/tachyon/api/Frame.hpp>
#include <yq/tachyon/api/ManagerMetaWriter.hpp>
#include <yq/tedit/xrs/MTachyon.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::TEManager)

namespace yq::tachyon {
    thread_local TEManager*     TEManager::s_instance   = nullptr;

    void TEManager::init_meta()
    {
        auto w = writer<TEManager>();
        w.description("Tachyon Edit Qt Manager");
    }

    TEManager::TEManager()
    {
        if(!s_instance)
            s_instance  = this;
    }
    
    TEManager::~TEManager()
    {
        if(s_instance == this)
            s_instance  = nullptr;
    }

    MTachyon* TEManager::manage(TypedID tId)
    {
        MTachyon*   ret = m_managed.get(tId.id, nullptr);
        if(ret)
            return ret;
        
        const Frame*    frame   = Frame::current();
        if(!frame)
            return nullptr;
        const TachyonMeta*  tm  = frame->meta(tId);
        if(!tm)
            return nullptr;
        const MTachyonMeta* mtm = MTachyonMeta::find(*tm);
        if(!mtm)
            return nullptr;
        
        ret = mtm->create(tId);
        if(!ret)
            return nullptr;
        retain(CHILD, ret);
        m_managed[tId.id]   = ret;
        return ret;
    }
}

#include "moc_TEManager.cpp"
