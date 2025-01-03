////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/vector/Vector3.hpp>
#include <yt/keywords.hpp>
#include <yq/tachyon/api/Interface.hpp>

namespace yq::tachyon {

    class PName;

    class IName {
        YQ_INTERFACE_DECLARE(IName, PName)
    public:
    
        virtual std::string_view    name() const = 0;
        virtual void                name(set_k, std::string&&){}
        
        static void init_info();
    };
}
