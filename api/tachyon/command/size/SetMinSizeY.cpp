////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/size/SetMinSizeY.hpp>
#include <tachyon/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetMinSizeʸ)

namespace yq::tachyon {
    SetMinSizeʸ::SetMinSizeʸ(const Header& h) : 
        SizeCommand(h)
    {
    }

    SetMinSizeʸ::SetMinSizeʸ(const Header& h, double v) : 
        SizeCommand(h), m_y(v)
    {
    }

    SetMinSizeʸ::SetMinSizeʸ(const SetMinSizeʸ& cp, const Header& h) : 
        SizeCommand(cp, h), m_y(cp.m_y)
    {
    }
    
    SetMinSizeʸ::~SetMinSizeʸ()
    {
    }

    PostCPtr    SetMinSizeʸ::clone(rebind_k, const Header&h) const 
    {
        return new SetMinSizeʸ(*this, h);
    }
    
    void SetMinSizeʸ::init_info()
    {
        auto w = writer<SetMinSizeʸ>();
        w.description("SetMin Size Command in Y");
        w.property("y", &SetMinSizeʸ::m_y).tag(kTag_Log).tag(kTag_Save);
    }
}
