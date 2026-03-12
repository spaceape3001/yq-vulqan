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
    class AddMaxSizeˣDCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(AddMaxSizeˣDCommand, SizeCommand)
    public:
        AddMaxSizeˣDCommand(const Header&, double);
        
        static void init_meta();
        
        double  Δx() const { return m_Δx; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        AddMaxSizeˣDCommand(const AddMaxSizeˣDCommand&, const Header&);
        AddMaxSizeˣDCommand(const Header&);
        ~AddMaxSizeˣDCommand();

    private:
        double  m_Δx = 0.0;
        
        AddMaxSizeˣDCommand(const AddMaxSizeˣDCommand&) = delete;
        AddMaxSizeˣDCommand(AddMaxSizeˣDCommand&&) = delete;
        AddMaxSizeˣDCommand& operator=(const AddMaxSizeˣDCommand&) = delete;
        AddMaxSizeˣDCommand& operator=(AddMaxSizeˣDCommand&&) = delete;
    };
}
