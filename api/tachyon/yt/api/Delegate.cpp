////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yt/api/Delegate.hpp>
#include <yt/api/DelegateInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::Delegate)

namespace yq::tachyon {
    DelegateInfo::DelegateInfo(std::string_view zName, ObjectInfo& base, const std::source_location& sl) :
        ObjectInfo(zName, base, sl)
    {
        set(Flag::DELEGATE);
    }
    
    DelegateInfo::~DelegateInfo()
    {
    }

    ////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////

    void Delegate::init_info()
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
