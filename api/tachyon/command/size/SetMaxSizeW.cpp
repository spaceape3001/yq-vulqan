////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/size/SetMaxSizeW.hpp>
#include <tachyon/api/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetMaxSizeʷ)

namespace yq::tachyon {
    SetMaxSizeʷ::SetMaxSizeʷ(const Header& h) : 
        SizeCommand(h)
    {
    }

    SetMaxSizeʷ::SetMaxSizeʷ(const Header& h, double v) : 
        SizeCommand(h), m_w(v)
    {
    }

    SetMaxSizeʷ::SetMaxSizeʷ(const SetMaxSizeʷ& cp, const Header& h) : 
        SizeCommand(cp, h), m_w(cp.m_w)
    {
    }
    
    SetMaxSizeʷ::~SetMaxSizeʷ()
    {
    }

    PostCPtr    SetMaxSizeʷ::clone(rebind_k, const Header&h) const 
    {
        return new SetMaxSizeʷ(*this, h);
    }
    
    void SetMaxSizeʷ::init_info()
    {
        auto w = writer<SetMaxSizeʷ>();
        w.description("SetMax Size Command in X");
        w.property("w", &SetMaxSizeʷ::m_w).tag(kTag_Log).tag(kTag_Save);
    }
}
