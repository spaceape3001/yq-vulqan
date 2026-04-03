////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "TEManager.hpp"
#include <yq/tachyon/api/ManagerMetaWriter.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::TEManager)

namespace yq::tachyon {
    thread_local TEManager*     TEManager::s_instance   = nullptr;
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
        
    void TEManager::init_meta()
    {
        auto w = writer<TEManager>();
        w.description("Tachyon Edit Qt Manager");
    }
}

#include "moc_TEManager.cpp"
