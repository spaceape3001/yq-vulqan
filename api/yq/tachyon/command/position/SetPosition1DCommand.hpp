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
    class SetPosition¹DCommand : public PositionCommand {
        YQ_OBJECT_DECLARE(SetPosition¹DCommand, PositionCommand)
    public:
        SetPosition¹DCommand(const Header&, const Vector1D&);
    
        const Vector1D&   position() const  { return m_position; }
        
        static void init_meta();
        
        double  x() const { return m_position.x; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetPosition¹DCommand(const SetPosition¹DCommand&, const Header&);
        ~SetPosition¹DCommand();

    private:
        Vector1D  m_position;
        
        SetPosition¹DCommand(const SetPosition¹DCommand&) = delete;
        SetPosition¹DCommand(SetPosition¹DCommand&&) = delete;
        SetPosition¹DCommand& operator=(const SetPosition¹DCommand&) = delete;
        SetPosition¹DCommand& operator=(SetPosition¹DCommand&&) = delete;
    };
}
