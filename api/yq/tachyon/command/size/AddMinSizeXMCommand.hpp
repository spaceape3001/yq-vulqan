////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/unit/declare.hpp>
#include <yq/tachyon/command/SizeCommand.hpp>
#include <yq/shape/Size1.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's x-scale
    class AddMinSizeˣMCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(AddMinSizeˣMCommand, SizeCommand)
    public:
        AddMinSizeˣMCommand(const Header&, Meter);
        
        static void init_meta();
        
        Meter  Δx() const { return m_Δx; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        AddMinSizeˣMCommand(const AddMinSizeˣMCommand&, const Header&);
        AddMinSizeˣMCommand(const Header&);
        ~AddMinSizeˣMCommand();

    private:
        Meter  m_Δx = 0.0;
        
        AddMinSizeˣMCommand(const AddMinSizeˣMCommand&) = delete;
        AddMinSizeˣMCommand(AddMinSizeˣMCommand&&) = delete;
        AddMinSizeˣMCommand& operator=(const AddMinSizeˣMCommand&) = delete;
        AddMinSizeˣMCommand& operator=(AddMinSizeˣMCommand&&) = delete;
    };
}
