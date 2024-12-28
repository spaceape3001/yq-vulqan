////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Delegate.hpp>

namespace yq::tachyon {

    class Spatial;
    
    class SpatialInfo : public DelegateInfo {
    public:
        template <typename C> class Writer;

        SpatialInfo(std::string_view zName, DelegateInfo& base, const std::source_location& sl=std::source_location::current());
    
    protected:
        ~SpatialInfo();
    };


    /*! \brief Describer of x/y/z/etc in terms of relevant parametrics
    
        
    */
    class Spatial : public Delegate {
        YQ_OBJECT_INFO(SpatialInfo)
        YQ_OBJECT_DECLARE(Spatial, Delegate)
    public:
    
        virtual uint8_t dimensions(count_k) const = 0;
    
        Spatial();
        
        static void init_info();
    
    protected:
        virtual ~Spatial();
    };
}
