////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/api/TypedID.hpp>
#include <yq/tachyon/api/Tachyon.hpp>
#include <yq/tachyon/api/Thread.hpp>
#include <yq/meta/Init.hpp>

namespace yq::tachyon {

    TypedID::TypedID(const Tachyon&t) : id(t.UniqueID::id()), types(t.metaInfo().types()) 
    {
    }
    
    TypedID::TypedID(const Tachyon*t) : id(t ? t->UniqueID::id() : 0ULL), types(t ? t->metaInfo().types() : Types())
    {
    }

    TypedID::TypedID(StdThread st) : id(Thread::standard(st)), types(Type::Thread)
    {
    }

    static void reg_typedid()
    {
        auto w = writer<TypedID>();
        w.description("Typed Identifier");
        w.set(Meta::Flag::ID);
        w.casts<TachyonID>();
    }
    
    YQ_INVOKE( reg_typedid(); )
}
YQ_TYPE_IMPLEMENT(yq::tachyon::TypedID)
