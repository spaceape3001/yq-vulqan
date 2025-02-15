////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SaveDelegate.hpp"
#include <yt/api/Delegate.hpp>

namespace yq::tachyon {
    SaveDelegate::SaveDelegate(const Delegate& del) : SaveObject(del, del.id())
    {
    }
    
    SaveDelegate::SaveDelegate(std::string_view k, uint64_t i) : SaveObject(k, i)
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
