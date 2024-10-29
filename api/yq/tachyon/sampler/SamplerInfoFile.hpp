////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/sampler/SamplerInfo.hpp>
#include <yq/keyv/StdFile.hpp>

namespace yq::tachyon {
    struct SamplerInfo;
    
    class SamplerInfo::File : public StdFile {
    public:
    
        File(SamplerInfo&);
        File(const SamplerInfo&);
        File(const SamplerInfo&&) = delete;
        
        ~File();
        
        bool    recursive_attributes() const override { return false; }
        bool    read_enabled() const override { return !m_const; }

        virtual std::error_code     write(KVTree&) const override;
        std::error_code             read(KVTree&&, std::string_view fname) override; 
        
    
    private:
        SamplerInfo*        m_info;
        bool                m_const;
        
    };

}
