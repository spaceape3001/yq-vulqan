////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/resource/Resource.hpp>
#include <yq/tachyon/enum/SaveType.hpp>
#include <yq/tachyon/io/Builder.hpp>

namespace yq::tachyon {
    class Save : public Resource, public virtual Builder {
        YQ_RESOURCE_DECLARE(Save, Resource)
    public:
    
        Save(SaveType st=SaveType::General);
        virtual ~Save();
        
        static void    init_meta();
        
        SaveType                    type() const { return m_type; }
        const std::vector<Url>&     uses() const { return m_uses; }
        
    private:
        SaveType                    m_type        = SaveType::General;
        std::vector<Url>            m_uses;
    };
}
