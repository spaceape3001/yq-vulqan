////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MultiplySizeYDCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplySizeʸDCommand)

namespace yq::tachyon {
    MultiplySizeʸDCommand::MultiplySizeʸDCommand(const Header& h) : 
        SizeCommand(h)
    {
    }
    
    MultiplySizeʸDCommand::MultiplySizeʸDCommand(const Header& h, double y) : 
        SizeCommand(h), m_δy(y)
    {
    }

    MultiplySizeʸDCommand::MultiplySizeʸDCommand(const MultiplySizeʸDCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_δy(cp.m_δy)
    {
    }

    MultiplySizeʸDCommand::~MultiplySizeʸDCommand()
    {
    }

    PostCPtr    MultiplySizeʸDCommand::clone(rebind_k, const Header&h) const 
    {
        return new MultiplySizeʸDCommand(*this, h);
    }
    
    void MultiplySizeʸDCommand::init_meta()
    {
        auto w = writer<MultiplySizeʸDCommand>();
        w.description("Multiply Size DCommand");
        w.property("δy", &MultiplySizeʸDCommand::m_δy).tag(kTag_Log).tag(kTag_Save);
    }
}
