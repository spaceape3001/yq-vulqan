////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/command/spatial/PositionCommand.hpp>
#include <yq/vector/Vector1.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's position
    class SetPosition¹Command : public PositionCommand {
        YQ_OBJECT_DECLARE(SetPosition¹Command, PositionCommand)
    public:
        SetPosition¹Command(const Header&, const Vector1D&);
    
        const Vector1D&   position() const  { return m_position; }
        
        static void init_meta();
        
        double  x() const { return m_position.x; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetPosition¹Command(const SetPosition¹Command&, const Header&);
        ~SetPosition¹Command();

    private:
        Vector1D const  m_position;
        
        SetPosition¹Command(const SetPosition¹Command&) = delete;
        SetPosition¹Command(SetPosition¹Command&&) = delete;
        SetPosition¹Command& operator=(const SetPosition¹Command&) = delete;
        SetPosition¹Command& operator=(SetPosition¹Command&&) = delete;
    };
}
