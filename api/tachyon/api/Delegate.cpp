////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/api/Delegate.hpp>
#include <tachyon/api/DelegateMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::Delegate)

namespace yq::tachyon {
    DelegateMeta::DelegateMeta(std::string_view zName, ObjectMeta& base, const std::source_location& sl) :
        ObjectMeta(zName, base, sl)
    {
        set(Flag::DELEGATE);
    }
    
    DelegateMeta::~DelegateMeta()
    {
    }

    ////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////

    void Delegate::init_meta()
    {
        auto w = writer<Delegate>();
        w.description("Tachyon Delegate");
    }
        
    Delegate::Delegate()
    {
    }
    
    Delegate::~Delegate()
    {
    }

}
