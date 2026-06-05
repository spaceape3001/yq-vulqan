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
    class AddPosition¹CMCommand : public PositionCommand {
        YQ_OBJECT_DECLARE(AddPosition¹CMCommand, PositionCommand)
    public:
        AddPosition¹CMCommand(const Header&, const Centimeter1D&Δ);
    
        const Centimeter1D&   Δ() const  { return m_Δ; }
        
        static void init_meta();
        
        Centimeter  Δx() const { return m_Δ.x; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        ~AddPosition¹CMCommand();
        AddPosition¹CMCommand(const AddPosition¹CMCommand&, const Header&);
        AddPosition¹CMCommand(const Header&);
        
    private:
        Centimeter1D  m_Δ = ZERO;
        
        AddPosition¹CMCommand(const AddPosition¹CMCommand&) = delete;
        AddPosition¹CMCommand(AddPosition¹CMCommand&&) = delete;
        AddPosition¹CMCommand& operator=(const AddPosition¹CMCommand&) = delete;
        AddPosition¹CMCommand& operator=(AddPosition¹CMCommand&&) = delete;
    };
}
