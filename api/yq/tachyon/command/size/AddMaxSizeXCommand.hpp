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
    class AddMaxSizeˣCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(AddMaxSizeˣCommand, SizeCommand)
    public:
        AddMaxSizeˣCommand(const Header&, double);
        
        static void init_meta();
        
        double  Δx() const { return m_Δx; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        AddMaxSizeˣCommand(const AddMaxSizeˣCommand&, const Header&);
        AddMaxSizeˣCommand(const Header&);
        ~AddMaxSizeˣCommand();

    private:
        double  m_Δx = 0.0;
        
        AddMaxSizeˣCommand(const AddMaxSizeˣCommand&) = delete;
        AddMaxSizeˣCommand(AddMaxSizeˣCommand&&) = delete;
        AddMaxSizeˣCommand& operator=(const AddMaxSizeˣCommand&) = delete;
        AddMaxSizeˣCommand& operator=(AddMaxSizeˣCommand&&) = delete;
    };
}
