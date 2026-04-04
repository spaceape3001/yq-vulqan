////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MManager.hpp"
#include "MTachyonMetaWriter.hpp"
#include <yq/tachyon/api/Manager.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::MManager)

namespace yq::tachyon {
    MManager::MManager(TypedID tid) : MTachyon(tid)
    {
    }
    
    MManager::~MManager()
    {
    }
    
    void MManager::init_meta()
    {
        auto w = writer<MManager>();
        w.description("Manager Qt Binder");
        w.manage<Manager>();
    }
}


#include "moc_MManager.cpp"
