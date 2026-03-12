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
    class AddMaxSizeˣMCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(AddMaxSizeˣMCommand, SizeCommand)
    public:
        AddMaxSizeˣMCommand(const Header&, Meter);
        
        static void init_meta();
        
        Meter  Δx() const { return m_Δx; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        AddMaxSizeˣMCommand(const AddMaxSizeˣMCommand&, const Header&);
        AddMaxSizeˣMCommand(const Header&);
        ~AddMaxSizeˣMCommand();

    private:
        Meter  m_Δx = 0.0;
        
        AddMaxSizeˣMCommand(const AddMaxSizeˣMCommand&) = delete;
        AddMaxSizeˣMCommand(AddMaxSizeˣMCommand&&) = delete;
        AddMaxSizeˣMCommand& operator=(const AddMaxSizeˣMCommand&) = delete;
        AddMaxSizeˣMCommand& operator=(AddMaxSizeˣMCommand&&) = delete;
    };
}
