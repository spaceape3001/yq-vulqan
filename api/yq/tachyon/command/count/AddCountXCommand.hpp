////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/CountCommand.hpp>
#include <yq/vector/Vector1.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's x-scale
    class AddCountˣCommand : public CountCommand {
        YQ_OBJECT_DECLARE(AddCountˣCommand, CountCommand)
    public:
        AddCountˣCommand(const Header&, unsigned);
        
        static void init_meta();
        
        unsigned  Δx() const { return m_Δx; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        AddCountˣCommand(const AddCountˣCommand&, const Header&);
        AddCountˣCommand(const Header&);
        ~AddCountˣCommand();

    private:
        unsigned  m_Δx = 0.0;
        
        AddCountˣCommand(const AddCountˣCommand&) = delete;
        AddCountˣCommand(AddCountˣCommand&&) = delete;
        AddCountˣCommand& operator=(const AddCountˣCommand&) = delete;
        AddCountˣCommand& operator=(AddCountˣCommand&&) = delete;
    };
}
