////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yt/api/TypedID.hpp>
#include <yt/api/Tachyon.hpp>
#include <yq/meta/Init.hpp>

namespace yq::tachyon {

    TypedID::TypedID(const Tachyon&t) : id(t.UniqueID::id()), types(t.metaInfo().types()) 
    {
    }
    
    TypedID::TypedID(const Tachyon*t) : id(t ? t->UniqueID::id() : 0ULL), types(t ? t->metaInfo().types() : Types())
    {
    }

    static void reg_typedid()
    {
        auto w = writer<TypedID>();
        w.description("Typed Identifier");
    }
    
    YQ_INVOKE( reg_typedid(); )
}
YQ_TYPE_IMPLEMENT(yq::tachyon::TypedID)
