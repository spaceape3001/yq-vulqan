////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/spatial/PositionCommand.hpp>
#include <yq/vector/Vector1.hpp>
#include <yq/unit/MKS.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's position
    class SetPosition¹MCommand : public PositionCommand {
        YQ_OBJECT_DECLARE(SetPosition¹MCommand, PositionCommand)
    public:
        SetPosition¹MCommand(const Header&, const Meter1D&);
    
        const Meter1D&   position() const  { return m_position; }
        
        static void init_meta();
        
        Meter  x() const { return m_position.x; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetPosition¹MCommand(const SetPosition¹MCommand&, const Header&);
        ~SetPosition¹MCommand();

    private:
        Meter1D  m_position = ZERO;
        
        SetPosition¹MCommand(const SetPosition¹MCommand&) = delete;
        SetPosition¹MCommand(SetPosition¹MCommand&&) = delete;
        SetPosition¹MCommand& operator=(const SetPosition¹MCommand&) = delete;
        SetPosition¹MCommand& operator=(SetPosition¹MCommand&&) = delete;
    };
}
