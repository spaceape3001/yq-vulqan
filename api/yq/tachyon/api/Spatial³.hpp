////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Spatial.hpp>
#include <yq/typedef/tensor44.hpp>

namespace yq::tachyon {
    class Spatial³;
    
    class Spatial³Info : public SpatialInfo {
    public:
    
        template <typename C> class Writer;

        Spatial³Info(std::string_view zName, SpatialInfo& base, const std::source_location& sl=std::source_location::current());
    
    protected:
        ~Spatial³Info();
    
    };
    
    class Spatial³ : public Spatial {
        YQ_OBJECT_INFO(Spatial³Info)
        YQ_OBJECT_DECLARE(Spatial³, Spatial)
    public:
    
        Spatial³();
        ~Spatial³();
        
        static void init_info();
        
        virtual Tensor44D   local2domain() const = 0;
        virtual Tensor44D   domain2local() const = 0;
    };
}
