////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/spatial/PositionCommand.hpp>
#include <yq/vector/Vector1.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's position
    class SetPosition¹CMCommand : public PositionCommand {
        YQ_OBJECT_DECLARE(SetPosition¹CMCommand, PositionCommand)
    public:
        SetPosition¹CMCommand(const Header&, const Centimeter1D&);
    
        const Centimeter1D&   position() const  { return m_position; }
        
        static void init_meta();
        
        Centimeter  x() const { return m_position.x; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetPosition¹CMCommand(const SetPosition¹CMCommand&, const Header&);
        ~SetPosition¹CMCommand();

    private:
        Centimeter1D  m_position = ZERO;
        
        SetPosition¹CMCommand(const SetPosition¹CMCommand&) = delete;
        SetPosition¹CMCommand(SetPosition¹CMCommand&&) = delete;
        SetPosition¹CMCommand& operator=(const SetPosition¹CMCommand&) = delete;
        SetPosition¹CMCommand& operator=(SetPosition¹CMCommand&&) = delete;
    };
}
