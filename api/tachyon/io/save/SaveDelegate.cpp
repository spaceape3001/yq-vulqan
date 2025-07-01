////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SaveDelegate.hpp"
#include <tachyon/api/Delegate.hpp>

namespace yq::tachyon {
    SaveDelegate::SaveDelegate(Save& save, const Delegate& del) : SaveObject(save, del, del.id())
    {
    }
    
    SaveDelegate::SaveDelegate(Save& save, const DelegateMeta*info, uint64_t i) : SaveObject(save, info, i)
    {
    }
    
    SaveDelegate::~SaveDelegate()
    {
    }

    const DelegateMeta* SaveDelegate::info() const
    {
        return dynamic_cast<const DelegateMeta*>(SaveObject::info());
    }

    bool    SaveDelegate::valid() const 
    {
        return info() && id();
    }
}
