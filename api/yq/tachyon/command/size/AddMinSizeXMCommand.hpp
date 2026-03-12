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
    class AddMinSizeˣDCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(AddMinSizeˣDCommand, SizeCommand)
    public:
        AddMinSizeˣDCommand(const Header&, double);
        
        static void init_meta();
        
        double  Δx() const { return m_Δx; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        AddMinSizeˣDCommand(const AddMinSizeˣDCommand&, const Header&);
        AddMinSizeˣDCommand(const Header&);
        ~AddMinSizeˣDCommand();

    private:
        double  m_Δx = 0.0;
        
        AddMinSizeˣDCommand(const AddMinSizeˣDCommand&) = delete;
        AddMinSizeˣDCommand(AddMinSizeˣDCommand&&) = delete;
        AddMinSizeˣDCommand& operator=(const AddMinSizeˣDCommand&) = delete;
        AddMinSizeˣDCommand& operator=(AddMinSizeˣDCommand&&) = delete;
    };
}
