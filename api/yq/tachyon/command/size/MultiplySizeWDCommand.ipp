////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MultiplySizeWDCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplySizeʷDCommand)

namespace yq::tachyon {
    MultiplySizeʷDCommand::MultiplySizeʷDCommand(const Header&h) : 
        SizeCommand(h)
    {
    }

    MultiplySizeʷDCommand::MultiplySizeʷDCommand(const Header&h, double x) : 
        SizeCommand(h), m_δw(x)
    {
    }

    MultiplySizeʷDCommand::MultiplySizeʷDCommand(const MultiplySizeʷDCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_δw(cp.m_δw)
    {
    }
    
    MultiplySizeʷDCommand::~MultiplySizeʷDCommand()
    {
    }
    
    PostCPtr    MultiplySizeʷDCommand::clone(rebind_k, const Header&h) const 
    {
        return new MultiplySizeʷDCommand(*this, h);
    }

    void MultiplySizeʷDCommand::init_meta()
    {
        auto w = writer<MultiplySizeʷDCommand>();
        w.description("Multiply Size DCommand");
        w.property("δw", &MultiplySizeʷDCommand::m_δw).tag(kTag_Log).tag(kTag_Save);
    }
}
