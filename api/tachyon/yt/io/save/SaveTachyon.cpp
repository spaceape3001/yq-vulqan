////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SaveTachyon.hpp"
#include <yt/api/Tachyon.hpp>

namespace yq::tachyon {
    SaveTachyon::SaveTachyon(const Tachyon& tac) : SaveObject(tac, tac.id())
    {
    }
    
    SaveTachyon::SaveTachyon(std::string_view k, uint64_t i) : SaveObject(k, i)
    {
    }
    
    SaveTachyon::~SaveTachyon()
    {
    }

    const TachyonInfo* SaveTachyon::info() const
    {
        return dynamic_cast<const TachyonInfo*>(SaveObject::info());
    }

    bool    SaveTachyon::valid() const 
    {
        return info() && id();
    }
}
