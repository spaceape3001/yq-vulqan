////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/units.hpp>
#include <yq/tachyon/command/spatial/PositionCommand.hpp>
#include <yq/vector/Vector1.hpp>

namespace yq::tachyon {

    //! Instructs an object to adjust (self-increment) their position by given amount
    class AddPosition¹MCommand : public PositionCommand {
        YQ_OBJECT_DECLARE(AddPosition¹MCommand, PositionCommand)
    public:
        AddPosition¹MCommand(const Header&, const Meter1D&Δ);
    
        const Meter1D&   Δ() const  { return m_Δ; }
        
        static void init_meta();
        
        Meter  Δx() const { return m_Δ.x; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        ~AddPosition¹MCommand();
        AddPosition¹MCommand(const AddPosition¹MCommand&, const Header&);
        AddPosition¹MCommand(const Header&);
        
    private:
        Meter1D  m_Δ = ZERO;
        
        AddPosition¹MCommand(const AddPosition¹MCommand&) = delete;
        AddPosition¹MCommand(AddPosition¹MCommand&&) = delete;
        AddPosition¹MCommand& operator=(const AddPosition¹MCommand&) = delete;
        AddPosition¹MCommand& operator=(AddPosition¹MCommand&&) = delete;
    };
}
