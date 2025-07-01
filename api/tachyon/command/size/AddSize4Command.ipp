////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/size/AddSize4Command.hpp>
#include <tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddSize⁴Command)

namespace yq::tachyon {
    AddSize⁴Command::AddSize⁴Command(const Header& h) : SizeCommand(h)
    {
    }
    
    AddSize⁴Command::AddSize⁴Command(const Header& h, const Vector4D& v) : 
        SizeCommand(h), m_Δ(v)
    {
    }

    AddSize⁴Command::AddSize⁴Command(const AddSize⁴Command& cp, const Header& h) : 
        SizeCommand(cp, h), m_Δ(cp.m_Δ)
    {
    }
    
    AddSize⁴Command::~AddSize⁴Command()
    {
    }

    PostCPtr    AddSize⁴Command::clone(rebind_k, const Header&h) const 
    {
        return new AddSize⁴Command(*this, h);
    }
    
    void AddSize⁴Command::init_info()
    {
        auto w = writer<AddSize⁴Command>();
        w.description("Add Size Command");
        w.property("Δx", &AddSize⁴Command::Δx).tag(kTag_Log);
        w.property("Δy", &AddSize⁴Command::Δy).tag(kTag_Log);
        w.property("Δz", &AddSize⁴Command::Δz).tag(kTag_Log);
        w.property("Δw", &AddSize⁴Command::Δw).tag(kTag_Log);
        w.property("Δ",  &AddSize⁴Command::m_Δ).tag(kTag_Save);
    }
}
