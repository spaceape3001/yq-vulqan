////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/command/spatial/SizeCommand.hpp>
#include <yq/vector/Vector1.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's x-scale
    class AddSizeˣCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(AddSizeˣCommand, SizeCommand)
    public:
        AddSizeˣCommand(const Header&, double);
        
        static void init_info();
        
        double  Δx() const { return m_Δx; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        AddSizeˣCommand(const AddSizeˣCommand&, const Header&);
        AddSizeˣCommand(const Header&);
        ~AddSizeˣCommand();

    private:
        double  m_Δx = 0.0;
        
        AddSizeˣCommand(const AddSizeˣCommand&) = delete;
        AddSizeˣCommand(AddSizeˣCommand&&) = delete;
        AddSizeˣCommand& operator=(const AddSizeˣCommand&) = delete;
        AddSizeˣCommand& operator=(AddSizeˣCommand&&) = delete;
    };
}
