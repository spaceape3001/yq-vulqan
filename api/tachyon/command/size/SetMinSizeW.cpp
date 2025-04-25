////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/size/SetMinSizeW.hpp>
#include <tachyon/api/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetMinSizeʷ)

namespace yq::tachyon {
    SetMinSizeʷ::SetMinSizeʷ(const Header& h) : 
        SizeCommand(h)
    {
    }

    SetMinSizeʷ::SetMinSizeʷ(const Header& h, double v) : 
        SizeCommand(h), m_w(v)
    {
    }

    SetMinSizeʷ::SetMinSizeʷ(const SetMinSizeʷ& cp, const Header& h) : 
        SizeCommand(cp, h), m_w(cp.m_w)
    {
    }
    
    SetMinSizeʷ::~SetMinSizeʷ()
    {
    }

    PostCPtr    SetMinSizeʷ::clone(rebind_k, const Header&h) const 
    {
        return new SetMinSizeʷ(*this, h);
    }
    
    void SetMinSizeʷ::init_info()
    {
        auto w = writer<SetMinSizeʷ>();
        w.description("SetMin Size Command in X");
        w.property("w", &SetMinSizeʷ::m_w).tag(kTag_Log).tag(kTag_Save);
    }
}
