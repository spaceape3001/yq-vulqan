////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/units.hpp>
#include <yq/tachyon/command/SizeCommand.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's x-scale
    class AddMaxSizeˣCMCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(AddMaxSizeˣCMCommand, SizeCommand)
    public:
        AddMaxSizeˣCMCommand(const Header&, Centimeter);
        
        static void init_meta();
        
        Centimeter  Δx() const { return m_Δx; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        AddMaxSizeˣCMCommand(const AddMaxSizeˣCMCommand&, const Header&);
        AddMaxSizeˣCMCommand(const Header&);
        ~AddMaxSizeˣCMCommand();

    private:
        Centimeter  m_Δx = 0.0;
        
        AddMaxSizeˣCMCommand(const AddMaxSizeˣCMCommand&) = delete;
        AddMaxSizeˣCMCommand(AddMaxSizeˣCMCommand&&) = delete;
        AddMaxSizeˣCMCommand& operator=(const AddMaxSizeˣCMCommand&) = delete;
        AddMaxSizeˣCMCommand& operator=(AddMaxSizeˣCMCommand&&) = delete;
    };
}
