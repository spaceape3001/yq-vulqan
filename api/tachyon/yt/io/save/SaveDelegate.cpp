////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SaveDelegate.hpp"
#include <yt/api/Delegate.hpp>

namespace yq::tachyon {
    SaveDelegate::SaveDelegate(Save& save, const Delegate& del) : SaveObject(save, del, del.id())
    {
    }
    
    SaveDelegate::SaveDelegate(Save& save, std::string_view k, uint64_t i) : SaveObject(save, k, i)
    {
    }
    
    SaveDelegate::~SaveDelegate()
    {
    }

    const DelegateInfo* SaveDelegate::info() const
    {
        return dynamic_cast<const DelegateInfo*>(SaveObject::info());
    }

    bool    SaveDelegate::valid() const 
    {
        return info() && id();
    }
}
