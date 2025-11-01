////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/core/Object.hpp>
#include <yq/core/Ref.hpp>
#include <yq/core/UniqueID.hpp>
#include <yq/meta/ObjectMeta.hpp>
#include <tachyon/typedef/delegate.hpp>

namespace yq::tachyon {
    class DelegateMeta : public ObjectMeta {
    public:
        template <typename C> class Writer;

        DelegateMeta(std::string_view zName, ObjectMeta& base, const std::source_location& sl=std::source_location::current());
    protected:
        virtual ~DelegateMeta();
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
    class Delegate : public Object, public RefCount, public UniqueID {
        YQ_OBJECT_META(DelegateMeta)
        YQ_OBJECT_DECLARE(Delegate, Object)
    public:
    
        static void init_meta();
        
        virtual bool configure(/* TBD */) { return true; }
        
    protected:
        Delegate();
        virtual ~Delegate();
    };
}
