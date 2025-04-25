////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/command/spatial/PositionCommand.hpp>
#include <yq/vector/Vector1.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's z-position
    class SetPositionᶻ : public PositionCommand {
        YQ_OBJECT_DECLARE(SetPositionᶻ, PositionCommand)
    public:
        SetPositionᶻ(const Header&, double);
        
        static void init_info();
        
        double  z() const { return m_z; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetPositionᶻ(const SetPositionᶻ&, const Header&);
        ~SetPositionᶻ();
        
    private:
        double  m_z = 0.0;
        
        SetPositionᶻ(const SetPositionᶻ&) = delete;
        SetPositionᶻ(SetPositionᶻ&&) = delete;
        SetPositionᶻ& operator=(const SetPositionᶻ&) = delete;
        SetPositionᶻ& operator=(SetPositionᶻ&&) = delete;
    };
}
