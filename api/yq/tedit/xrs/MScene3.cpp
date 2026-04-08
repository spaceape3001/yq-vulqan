////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MScene3.hpp"
#include "MTachyonMetaWriter.hpp"
#include <yq/tachyon/api/Scene3.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::MScene3)

namespace yq::tachyon {
    MScene3::MScene3(TypedID tid) : MScene(tid)
    {
    }
    
    MScene3::~MScene3()
    {
    }
    
    void MScene3::init_meta()
    {
        auto w = writer<MScene3>();
        w.description("Scene³ Qt Binder");
        w.manage<Scene³>();
    }
}


#include "moc_MScene3.cpp"
