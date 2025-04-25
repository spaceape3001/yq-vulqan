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
    class SetPositionʷ : public PositionCommand {
        YQ_OBJECT_DECLARE(SetPositionʷ, PositionCommand)
    public:
        SetPositionʷ(const Header&, double);
        
        static void init_info();
        
        double  w() const { return m_w; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetPositionʷ(const SetPositionʷ&, const Header&);
        ~SetPositionʷ();
        
    private:
        double  m_w = 0.0;
        
        SetPositionʷ(const SetPositionʷ&);
        SetPositionʷ(SetPositionʷ&&);
        SetPositionʷ& operator=(const SetPositionʷ&);
        SetPositionʷ& operator=(SetPositionʷ&&);
    };
}
