////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/core/Object.hpp>
#include <yq/meta/ObjectInfo.hpp>

namespace yq::tachyon {
    class Delegate;

    class DelegateInfo : public ObjectInfo {
    public:
        template <typename C> class Writer;

        DelegateInfo(std::string_view zName, ObjectInfo& base, const std::source_location& sl=std::source_location::current());
    protected:
        virtual ~DelegateInfo();
    };
    
    /*! \brief Modifier/Extendible point
    
        Some attributes to a tachyon... need to be known, but it's a 
        design nightmare to leave up to that tachyon.  (ie, position
        of an object, or whether a controller gets triggered.)  Thus,
        the delgate, a point of flexibility that should result in
        some aspect of the tachyon snap/state/behavior.  
        
        Note, the result of this delegate should be showing up on 
        the frame.  (Configuration exposure for save/load TBD.)
        
    */
    class Delegate : public Object {
        YQ_OBJECT_INFO(DelegateInfo)
        YQ_OBJECT_DECLARE(Delegate, Object)
    public:
    
        static void init_info();
        
    protected:
        Delegate();
        virtual ~Delegate();
    };
}
