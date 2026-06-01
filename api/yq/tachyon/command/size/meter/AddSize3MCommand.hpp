////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/units.hpp>
#include <yq/tachyon/command/SizeCommand.hpp>
#include <yq/shape/Size3.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's scale
    class AddSize³MCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(AddSize³MCommand, SizeCommand)
    public:
        AddSize³MCommand(const Header&, const Size3M&);
    
        const Size3M&   Δ() const  { return m_Δ; }
        
        static void init_meta();
        
        Meter  Δx() const { return m_Δ.x; }
        Meter  Δy() const { return m_Δ.y; }
        Meter  Δz() const { return m_Δ.z; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        AddSize³MCommand(const AddSize³MCommand&, const Header&);
        AddSize³MCommand(const Header&);
        ~AddSize³MCommand();

    private:
        Size3M  m_Δ = ZERO;
        
        AddSize³MCommand(const AddSize³MCommand&) = delete;
        AddSize³MCommand(AddSize³MCommand&&) = delete;
        AddSize³MCommand& operator=(const AddSize³MCommand&) = delete;
        AddSize³MCommand& operator=(AddSize³MCommand&&) = delete;
    };
}
