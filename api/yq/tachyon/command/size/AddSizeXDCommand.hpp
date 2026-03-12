////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/SizeCommand.hpp>
#include <yq/vector/Vector1.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's x-scale
    class AddSizeˣDCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(AddSizeˣDCommand, SizeCommand)
    public:
        AddSizeˣDCommand(const Header&, double);
        
        static void init_meta();
        
        double  Δx() const { return m_Δx; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        AddSizeˣDCommand(const AddSizeˣDCommand&, const Header&);
        AddSizeˣDCommand(const Header&);
        ~AddSizeˣDCommand();

    private:
        double  m_Δx = 0.0;
        
        AddSizeˣDCommand(const AddSizeˣDCommand&) = delete;
        AddSizeˣDCommand(AddSizeˣDCommand&&) = delete;
        AddSizeˣDCommand& operator=(const AddSizeˣDCommand&) = delete;
        AddSizeˣDCommand& operator=(AddSizeˣDCommand&&) = delete;
    };
}
