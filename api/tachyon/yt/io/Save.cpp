////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Save.hpp"
#include <yt/api/Tachyon.hpp>
#include <yt/api/Delegate.hpp>
#include <yt/tags.hpp>
#include <yq/meta/ObjectInfo.hpp>
#include <yq/meta/PropertyInfo.hpp>

namespace yq::tachyon {
    void    Save::extract(asset_k, asset_t&dst, const Asset&src)
    {
        extract(OBJECT, dst, src);
        //  TODO
    }

    void    Save::extract(delegate_k, delegate_t&dst, const Delegate& src)
    {
        dst.info    = &src.metaInfo();
        extract(OBJECT, dst, src);
    }
    
    void    Save::extract(object_k, object_t&dst, const Object&src)
    {
        for(const PropertyInfo* pi : src.metaInfo().properties(ALL).all){
            if(!pi->setter())   // it's read-only
                continue;
            if(!pi->tagged(kTag_Save))
                continue;
            any_x   val = pi->get(&src);
            if(!val)
                continue;
            dst.properties.push_back({ pi, std::move(*val) });
        }
    }
    
    void    Save::extract(tackyon_k, tachyon_t&dst, const Tachyon&src, bool skipChildren)
    {
        dst.info    = &src.metaInfo();
        extract(OBJECT, dst, src);
    }

    void    Save::extract(thread_k, thread_t&dst, const Thread&src)
    {
        extract(TACHYON, dst, src);
    }
}
