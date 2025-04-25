////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/command/spatial/PositionCommand.hpp>
#include <yq/vector/Vector1.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's x-position
    class SetPositionˣ : public PositionCommand {
        YQ_OBJECT_DECLARE(SetPositionˣ, PositionCommand)
    public:
        SetPositionˣ(const Header&, double);
        
        static void init_info();
        
        double  x() const { return m_x; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetPositionˣ(const SetPositionˣ&, const Header&);
        ~SetPositionˣ();
        
    private:
        double  m_x = 0.0;
        
        SetPositionˣ(const SetPositionˣ&);
        SetPositionˣ(SetPositionˣ&&);
        SetPositionˣ& operator=(const SetPositionˣ&);
        SetPositionˣ& operator=(SetPositionˣ&&);
    };
}
