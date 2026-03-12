////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/unit/declare.hpp>
#include <yq/tachyon/command/SizeCommand.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's x-scale
    class AddSizeˣMCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(AddSizeˣMCommand, SizeCommand)
    public:
        AddSizeˣMCommand(const Header&, Meter);
        
        static void init_meta();
        
        Meter  Δx() const { return m_Δx; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        AddSizeˣMCommand(const AddSizeˣMCommand&, const Header&);
        AddSizeˣMCommand(const Header&);
        ~AddSizeˣMCommand();

    private:
        Meter  m_Δx = 0.0;
        
        AddSizeˣMCommand(const AddSizeˣMCommand&) = delete;
        AddSizeˣMCommand(AddSizeˣMCommand&&) = delete;
        AddSizeˣMCommand& operator=(const AddSizeˣMCommand&) = delete;
        AddSizeˣMCommand& operator=(AddSizeˣMCommand&&) = delete;
    };
}
