////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/size/MultiplyMaxSizeWCommand.hpp>
#include <tachyon/api/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplyMaxSizeʷCommand)

namespace yq::tachyon {
    MultiplyMaxSizeʷCommand::MultiplyMaxSizeʷCommand(const Header&h) : 
        SizeCommand(h)
    {
    }

    MultiplyMaxSizeʷCommand::MultiplyMaxSizeʷCommand(const Header&h, double x) : 
        SizeCommand(h), m_δw(x)
    {
    }

    MultiplyMaxSizeʷCommand::MultiplyMaxSizeʷCommand(const MultiplyMaxSizeʷCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_δw(cp.m_δw)
    {
    }
    
    MultiplyMaxSizeʷCommand::~MultiplyMaxSizeʷCommand()
    {
    }
    
    PostCPtr    MultiplyMaxSizeʷCommand::clone(rebind_k, const Header&h) const 
    {
        return new MultiplyMaxSizeʷCommand(*this, h);
    }

    void MultiplyMaxSizeʷCommand::init_info()
    {
        auto w = writer<MultiplyMaxSizeʷCommand>();
        w.description("MultiplyMax Size Command");
        w.property("δw", &MultiplyMaxSizeʷCommand::m_δw).tag(kTag_Log).tag(kTag_Save);
    }
}
