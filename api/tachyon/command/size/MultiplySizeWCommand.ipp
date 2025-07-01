////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/size/MultiplySizeWCommand.hpp>
#include <tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplySizeʷCommand)

namespace yq::tachyon {
    MultiplySizeʷCommand::MultiplySizeʷCommand(const Header&h) : 
        SizeCommand(h)
    {
    }

    MultiplySizeʷCommand::MultiplySizeʷCommand(const Header&h, double x) : 
        SizeCommand(h), m_δw(x)
    {
    }

    MultiplySizeʷCommand::MultiplySizeʷCommand(const MultiplySizeʷCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_δw(cp.m_δw)
    {
    }
    
    MultiplySizeʷCommand::~MultiplySizeʷCommand()
    {
    }
    
    PostCPtr    MultiplySizeʷCommand::clone(rebind_k, const Header&h) const 
    {
        return new MultiplySizeʷCommand(*this, h);
    }

    void MultiplySizeʷCommand::init_info()
    {
        auto w = writer<MultiplySizeʷCommand>();
        w.description("Multiply Size Command");
        w.property("δw", &MultiplySizeʷCommand::m_δw).tag(kTag_Log).tag(kTag_Save);
    }
}
