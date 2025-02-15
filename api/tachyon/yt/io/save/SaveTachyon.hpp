////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/io/save/SaveObject.hpp>

namespace yq::tachyon {
    class Tachyon;
    class TachyonInfo;
    
    class SaveTachyon : public SaveObject {
    public:
        SaveTachyon(const Tachyon&);
        SaveTachyon(std::string_view, uint64_t);
        
        const TachyonInfo* info() const;
        virtual bool    valid() const override;
    protected:
        virtual ~SaveTachyon();
    };
}
