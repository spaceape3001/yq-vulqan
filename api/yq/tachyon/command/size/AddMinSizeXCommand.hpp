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
    class AddMinSizeˣCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(AddMinSizeˣCommand, SizeCommand)
    public:
        AddMinSizeˣCommand(const Header&, double);
        
        static void init_meta();
        
        double  Δx() const { return m_Δx; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        AddMinSizeˣCommand(const AddMinSizeˣCommand&, const Header&);
        AddMinSizeˣCommand(const Header&);
        ~AddMinSizeˣCommand();

    private:
        double  m_Δx = 0.0;
        
        AddMinSizeˣCommand(const AddMinSizeˣCommand&) = delete;
        AddMinSizeˣCommand(AddMinSizeˣCommand&&) = delete;
        AddMinSizeˣCommand& operator=(const AddMinSizeˣCommand&) = delete;
        AddMinSizeˣCommand& operator=(AddMinSizeˣCommand&&) = delete;
    };
}
